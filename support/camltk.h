#include <caml/alloc.h>
#include <caml/misc.h>
#include <caml/fail.h>
#include <caml/memory.h>
#include <caml/callback.h>

/* cltkEval.c */
extern Tcl_Interp *cltclinterp; /* The Tcl interpretor */
value copy_string_list(int, char **);

/* copy a Caml string to the C heap. Must be deallocated with stat_free */
char *string_to_c();

/* cltkCaml.c */
/* pointers to Caml values */
extern value *tkerror_exn;
extern value *handler_code;
int CamlCBCmd();
void tk_error(char *) Noreturn;

/* cltkMain.c */
extern int signal_events;
void invoke_pending_caml_signals();
extern Tk_Window cltk_mainWindow;
extern int cltk_slave_mode;

/* check that initialisations took place */
#define CheckInit()  if (!cltclinterp) tk_error("Tcl/Tk not initialised")

#define RCNAME ".camltkrc"
#define CAMLCB "camlcb"

/* caml/byterun/signals.h */
extern void enter_blocking_section (void);
extern void leave_blocking_section (void);

