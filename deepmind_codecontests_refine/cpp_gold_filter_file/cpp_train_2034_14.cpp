#include <bits/stdc++.h>
using namespace std;
char a[110];
char Bi[20] = {"9223372036854775808"};
char li[11] = {"2147483648"};
char si[6] = {"32768"};
char bi[4] = {"128"};
int main() {
  while (~scanf("%s", a)) {
    int flag = 0;
    int x = strlen(a);
    if (a[0] == '-') {
      x--;
      flag = 1;
    }
    if (x > 19) {
      printf("BigInteger\n");
    } else if (x < 3)
      printf("byte\n");
    else if (x == 3) {
      if (flag) {
        if (strcmp(bi, a + 1) >= 0)
          printf("byte\n");
        else
          printf("short\n");
      } else {
        bi[2] -= 1;
        if (strcmp(bi, a) >= 0)
          printf("byte\n");
        else
          printf("short\n");
        bi[2] += 1;
      }
    } else if (x < 5)
      printf("short\n");
    else if (x == 5) {
      if (flag) {
        if (strcmp(si, a + 1) >= 0)
          printf("short\n");
        else
          printf("int\n");
      } else {
        si[4] -= 1;
        if (strcmp(si, a) >= 0)
          printf("short\n");
        else
          printf("int\n");
        si[4] += 1;
      }
    } else if (x < 10)
      printf("int\n");
    else if (x == 10) {
      if (flag) {
        if (strcmp(li, a + 1) >= 0)
          printf("int\n");
        else
          printf("long\n");
      } else {
        li[9] -= 1;
        if (strcmp(li, a) >= 0)
          printf("int\n");
        else
          printf("long\n");
        li[9] += 1;
      }
    } else if (x < 19)
      printf("long\n");
    else if (x == 19) {
      if (flag) {
        if (strcmp(Bi, a + 1) >= 0)
          printf("long\n");
        else
          printf("BigInteger \n");
      } else {
        Bi[18] -= 1;
        if (strcmp(Bi, a) >= 0)
          printf("long\n");
        else
          printf("BigInteger \n");
        Bi[18] += 1;
      }
    }
  }
}
