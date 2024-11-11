#include <bits/stdc++.h>
int C[1100100], P[100000];
int pc;
int min(int a, int b) {
  if (a < b) return a;
  return b;
}
int max(int a, int b) {
  if (a > b) return a;
  return b;
}
int main() {
  int X2, X1, X0, i, j, pm;
  for (i = 2; i < 1100100; i++) {
    if (C[i] == 0) {
      for (j = i + i; j <= 1100100; j += i) {
        C[j] = 1;
      }
    }
  }
  j = 0;
  for (i = 2; i < 1100100; i++) {
    if (C[i] == 0) {
      P[j++] = i;
    }
  }
  pc = j;
  scanf("%d", &X2);
  for (i = pc - 1; i >= 0; i--) {
    if (X2 % P[i] == 0) {
      pm = P[i];
      break;
    }
  }
  X1 = X2 - pm + 1;
  X0 = X1;
  for (i = 0; i < pc; i++) {
    int p = P[i];
    if (p <= X2 / 2 && (X1 + p - 1) / p * p >= X1 &&
        (X1 + p - 1) / p * p <= X2) {
      X0 = min(X0, (X1 + p - 1) / p * p - p + 1);
    }
  }
  printf("%d\n", X0);
}
