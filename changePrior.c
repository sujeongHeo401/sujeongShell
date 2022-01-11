#include <sys/resource.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int which = PRIO_PROCESS;
    id_t pid;
    int ret;

    pid = getpid();
    ret = getpriority(which, 0);
    printf("PID=%d, PRIORITY=%d\n", pid, ret);
    ret = nice(10);
    ret = getpriority(which, 0);
    printf("PID=%d, PRIORITY=%d\n", pid, ret);

    ret = setpriority(which, 0, 5);
    ret = getpriority(which, 0);

    printf("PID=%d, PRIORITY=%d\n", pid, ret);
    return 0;
}
// ubuntu@ip-xxxx:~/programming$ gcc priority.c -o priority
// ubuntu@ip-xxxx:~/programming$ ./priority
// PID=17559, PRIORITY=0
// PID=17559, PRIORITY=10
// PID=17559, PRIORITY=10
