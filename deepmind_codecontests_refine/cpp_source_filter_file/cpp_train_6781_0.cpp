#include <bits/stdc++.h>
int main() {
  long long n, a[100100], u[100100] = {};
  int kol = 0;
  kol = 1;
  a[0] = 1;
  u[0] = 1;
  for (int i = 2; i < 10100; i++) {
    if (u[i] == 0) {
      a[kol] = i;
      kol++;
      for (int j = i; j < 10100; j += i) {
        u[j] = 1;
      }
    }
  }
  for (int i = 0; i < 100100; i++) u[i] = -1;
  long long x[100100], y[100100];
  scanf("%I64d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%I64d%I64d", &x[i], &y[i]);
  }
  long long st;
  for (int i = 0; i < n; i++) {
    st = 0;
    if (y[i] == 0) st++;
    long long t = 0, t2 = 1, t3 = 0, p[100100], p2[100100];
    p2[0] = 1;
    for (int j = 1; j < kol && a[j] <= x[i]; j++) {
      if (x[i] % a[j] == 0) {
        p[t] = a[j];
        t++;
        x[i] /= a[j];
        j--;
      }
    }
    for (int j = 0; j < t; j++) {
      t3 = t2;
      if (u[p[j]] == -1) {
        p2[t2] = p[j];
        t2++;
      }
      for (int k = 0; k < t3; k++) {
        int flag = 0;
        p2[t2] = p2[k] * p[j];
        if (u[p2[t2]] != i) flag = 1;
        if (u[p2[t2]] + y[i] < i) st++;
        u[p2[t2]] = i;
        t2 += flag;
      }
    }
    printf("%I64d\n", st);
  }
  return 0;
}
