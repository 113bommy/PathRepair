#include <bits/stdc++.h>
const int C = 20000001, CC = 100001, Inf = 1000000000;
int a, b, k, i = 0, j = 0, lop[50], ip = 0, wynn = 0, f[C];
bool p[C], sgn[CC];
int lim;
long long dv[CC], ij;
void generate(int ww, int n) {
  int j = 0, i = 0, gg = 0;
  dv[0] = ww, lim = 1;
  while (i < n) {
    while (j < lim) {
      if (dv[j] * lop[i] < Inf) {
        dv[gg + lim] = dv[j] * lop[i];
        sgn[gg + lim] = (sgn[j] ^ 1);
        gg++;
      }
      j++;
    }
    lim = lim + gg, gg = 0, j = 0, i++;
  }
}
inline int divinity(int a, int b, int x) { return b / x - (a - 1) / x; }
int main() {
  for (i = 2; i * i < C; i++) {
    if (p[i] == 0) {
      f[i] = i;
      if (ip < 25) lop[ip] = i, ip++;
      for (j = i * i; j < C; j += i)
        if (p[j] == 0) f[j] = i, p[j] = 1;
    }
  }
  p[0] = p[1] = 1, f[1] = Inf;
  for (; i < C; i++)
    if (p[i] == 0) f[i] = i;
  scanf("%d %d %d", &a, &b, &k);
  for (i = 2; i * i <= k; i++)
    if (k % i == 0) break;
  if (i * i <= k) {
    printf("%d\n", 0);
    return 0;
  }
  if (k < 100) {
    for (i = 0; i < 25; i++)
      if (lop[i] == k) break;
    generate(k, i);
    for (i = 0; i < lim; i++) {
      if (sgn[i] == 0)
        wynn += divinity(a, b, dv[i]);
      else
        wynn -= divinity(a, b, dv[i]);
    }
  } else {
    for (ij = 1; ij * k <= b; ij++) {
      if (ij * k >= a && f[ij] >= k) wynn++;
    }
  }
  printf("%d\n", wynn);
  return 0;
}
