#include <bits/stdc++.h>
using namespace std;
char a[3][11], vic[11], rep[11];
int n;
void movee() {
  int i, lena = strlen(a[1]), lenb = strlen(vic);
  if (lena == lenb) {
    for (i = 0; i < lenb; i++)
      if (a[1][i] != vic[i]) break;
    if (i == lenb)
      memset(a[1], 0, sizeof(a[1]));
    else
      memset(a[2], 0, sizeof(a[2]));
  } else
    memset(a[2], 0, sizeof(a[2]));
}
void add() {
  int i, j;
  if (a[1][0] == 0) {
    for (i = 0; rep[i]; i++) a[1][i] = rep[i];
  } else {
    for (i = 0; rep[i]; i++) a[2][i] = rep[i];
  }
}
int main() {
  int i;
  scanf("%s%s", a[1], a[2]);
  scanf("%d", &n);
  printf("%s %s\n", a[1], a[2]);
  for (i = 1; i <= n; i++) {
    scanf("%s%s", vic, rep);
    movee();
    add();
    printf("%s %s\n", a[1], a[2]);
  }
  return 0;
}
