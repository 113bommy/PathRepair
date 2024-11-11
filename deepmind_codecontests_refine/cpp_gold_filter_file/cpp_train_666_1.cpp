#include <bits/stdc++.h>
int fac[100100];
int n, m, i, x, j, l, r, p, ans, st, dr, mn, mx, M;
void init() {
  int i, j;
  for (i = 2; i <= 100000; i++)
    if (!fac[i]) {
      fac[i] = i;
      if (i > 316) continue;
      for (j = i * i; j <= 100000; j += i)
        if (!fac[j]) fac[j] = i;
    }
}
int solve(int x, int y) {
  int v[20];
  int N;
  int i, j, lim, ind, nr, rez = 0;
  if (y == 0) return 0;
  v[0] = 0;
  N = 0;
  for (i = x; i > 1; i /= fac[i])
    if (N == 0 || v[N - 1] != fac[i]) v[N++] = fac[i];
  lim = 1 << N;
  for (i = 0; i < lim; i++) {
    ind = 0;
    nr = 1;
    for (j = 0; j < N; j++)
      if (i & (1 << j)) {
        ind++;
        nr = nr * v[j];
      }
    int ax = y / nr;
    if (ind % 2 == 1)
      rez = (long long)((long long)((long long)rez - (long long)(M + 1) * ax +
                                    (long long)nr * ax * ((long long)ax + 1) /
                                        2) %
                            p +
                        (long long)p) %
            p;
    else
      rez = (long long)((long long)((long long)rez + (long long)(M + 1) * ax -
                                    (long long)nr * ax * ((long long)ax + 1) /
                                        2) %
                            p +
                        (long long)p) %
            p;
  }
  rez = (long long)((long long)rez * ((long long)n - x + 1)) % p;
  return ((int)rez);
}
int main() {
  scanf("%d%d%d%d%d", &n, &M, &l, &r, &p);
  init();
  for (x = 1; x <= n; x++) {
    for (st = 0, dr = 100001; st < dr;) {
      m = (st + dr) / 2;
      if ((long long)x * x + (long long)m * m >= (long long)l * l)
        dr = m;
      else
        st = m + 1;
    }
    mn = st;
    for (st = 0, dr = 100001; st < dr;) {
      m = (st + dr) / 2 + 1;
      if ((long long)x * x + (long long)m * m <= (long long)r * r)
        st = m;
      else
        dr = m - 1;
    }
    if (mn < 1) mn = 1;
    mx = st;
    if (mx > M) mx = M;
    if (mn > mx) continue;
    ans = (long long)((long long)((long long)ans + solve(x, mx) -
                                  solve(x, mn - 1)) %
                          p +
                      p) %
          p;
  }
  ans = (long long)ans * 2 % p;
  if (l <= 1)
    ans = (long long)((long long)ans + n * ((long long)M + 1) +
                      ((long long)n + 1) * M) %
          p;
  printf("%d", ans);
  return 0;
}
