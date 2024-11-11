#include <bits/stdc++.h>
bool x[1000000] = {0};
int a, b, c;
int y[10001];
int main() {
  for (a = 2; a < 1001; a++) {
    if (x[a] == 0) {
      for (b = a * a; b < 1000000; b = b + a) x[b] = 1;
    }
  }
  int qqq[11200];
  int p, q, k, z, r, s = 1, t = 13;
  while (s != 11184) {
    k = t;
    p = 0;
    while (k >= 10) {
      y[p] = k % 10;
      k = k / 10;
      p++;
    }
    y[p] = k;
    z = 0;
    for (r = 0; r <= p; r++) z = z * 10 + y[r];
    if (x[t] == 0 && x[z] == 0 && t != z) {
      qqq[s] = t;
      s++;
    }
    t++;
  }
  while (scanf("%d", &c) == 1) {
    printf("%d\n", qqq[c]);
  }
  return 0;
}
