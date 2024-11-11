#include <bits/stdc++.h>
using namespace std;
char ans[105];
char biao[4][20] = {"127", "32767", "2147483647", "9223372036854775807"};
int main() {
  int i, t, ln;
  scanf("%s", ans);
  ln = strlen(ans);
  if (ln < 3)
    printf("byte\n");
  else if (ln == 3) {
    if (strcmp(biao[0], ans) < 0)
      printf("short\n");
    else
      printf("byte\n");
  } else if (ln < 5)
    printf("short\n");
  else if (ln == 5) {
    if (strcmp(biao[1], ans) < 0)
      printf("int\n");
    else
      printf("short\n");
  } else if (ln < 10)
    printf("int\n");
  else if (ln == 10) {
    if (strcmp(biao[2], ans) < 0)
      printf("long\n");
    else
      printf("int\n");
  } else if (ln < 19)
    printf("long\n");
  else if (ln == 19) {
    if (strcmp(biao[3], ans) < 0)
      printf("BigInteger\n");
    else
      printf("long\n");
  } else
    printf("BigInteger\n");
  return 0;
}
