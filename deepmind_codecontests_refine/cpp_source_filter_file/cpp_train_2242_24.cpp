#include <bits/stdc++.h>
int x, i, B[100000], sayac;
char q, A[100000];
int main() {
  scanf("%d%c", &x, &q);
  for (i = 1; i <= x; i++) scanf("%c", &A[i]);
  for (i = 1; i <= x; i++) scanf("%d", &B[i]);
  i = 1;
  while (1) {
    if (i < 1 || i > x) {
      printf("FINITE");
      break;
    }
    if (A[i] == '<')
      i -= B[i];
    else if (A[i] == '>')
      i += B[i];
    sayac++;
    if (sayac == 100000) {
      printf("INFINITE");
      break;
    }
  }
  return 0;
}
