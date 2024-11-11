#include <bits/stdc++.h>
const double eps = 1e-12, inf = 1e12;
const int mod = (1 << 20) - 1, Base = 65, Red = 1, Blue = 2, Green = 3,
          EMPTY = 0;
using namespace std;
int n, f[20], s[1 << 6], tot, nxt[mod + 1], from[mod + 1], t;
long double ans[mod + 1];
unsigned long long w[mod + 1];
inline char read() {
  char ccc;
  while (isspace(ccc = getchar()))
    ;
  return ccc;
}
inline int Read(char ccc) {
  if (ccc == 'R') return Red;
  if (ccc == 'B') return Blue;
  if (ccc == 'G') return Green;
  return EMPTY;
}
inline void add(unsigned long long u, double v) {
  int x = u & mod;
  ans[++t] = v;
  nxt[t] = from[x];
  from[x] = t;
  w[t] = u;
}
inline unsigned long long HASH(int *a, int k, int up) {
  unsigned long long sum = 0;
  static int g[20];
  int h = 0;
  for (int i = 1; i <= k; ++i)
    if (a[i]) g[++h] = a[i];
  sort(g + 1, g + 1 + h);
  for (int i = 1; i <= h; ++i) sum = sum * Base + g[i];
  sum = sum * Base + up;
  return sum;
}
inline double query(int *a, int k, int up) {
  up = s[up];
  unsigned long long op = HASH(a, k, up);
  for (int i = from[op & mod]; i; i = nxt[i])
    if (w[i] == op) return ans[i];
  double v[4] = {inf, inf, inf, inf};
  int oto = k, D = 6;
  if ((up & 3) && ((up >> 2) & 3) && ((up >> 4) & 3)) f[++oto] = up, up = 0;
  for (int i = 1; i <= k; ++i) {
    int c1 = f[i] & 3, c2 = (f[i] >> 2) & 3, c3 = (f[i] >> 4) & 3, opp = f[i];
    if (c1 && c2 && c3 && v[c2] > eps) {
      f[i] = 0;
      if (!(up & 3))
        v[c2] = min(v[c2], query(f, oto, up | c2));
      else if (!(up >> 4 & 3))
        v[c2] = min(v[c2], query(f, oto, up | c2 << 4));
      if (!(up >> 2 & 3)) v[c2] = min(v[c2], query(f, oto, up | c2 << 2));
      f[i] = opp;
    }
    if (c1 && v[c1] > eps) {
      f[i] = c3;
      if (!(up & 3))
        v[c1] = min(v[c1], query(f, oto, up | c1));
      else if (!(up >> 4 & 3))
        v[c1] = min(v[c1], query(f, oto, up | c1 << 4));
      if (!(up >> 2 & 3)) v[c1] = min(v[c1], query(f, oto, up | c1 << 2));
      f[i] = opp;
    }
    if (c3 && v[c3] > eps) {
      f[i] = c1;
      if (!(up & 3))
        v[c3] = min(v[c3], query(f, oto, up | c3));
      else if (!(up >> 4 & 3))
        v[c3] = min(v[c3], query(f, oto, up | c3 << 4));
      if (!(up >> 2 & 3)) v[c3] = min(v[c3], query(f, oto, up | c3 << 2));
      f[i] = opp;
    }
  }
  double sum = 0;
  if (v[1] != inf) sum += v[1], D--;
  if (v[2] != inf) sum += v[2] * 2, D -= 2;
  if (v[3] != inf) sum += v[3] * 2, D -= 2;
  sum = (D == 6 ? 0 : (sum + 6) / (6 - D));
  add(op, sum);
  return sum;
}
int main() {
  n = read() ^ '0';
  for (int i = 0; i <= 3; ++i)
    for (int j = 0; j <= 3; ++j)
      for (int k = 0; k <= 3; ++k)
        s[i | j << 2 | k << 4] =
            i < k ? (i | j << 2 | k << 4) : (k | j << 2 | i << 4);
  for (int i = 1; i <= n; ++i) {
    f[i] |= Read(read());
    f[i] |= Read(read()) << 2;
    f[i] |= Read(read()) << 4;
    f[i] = s[f[i]];
  }
  tot = n;
  printf("%.15f", query(f, tot - 1, f[tot]));
  return 0;
}
