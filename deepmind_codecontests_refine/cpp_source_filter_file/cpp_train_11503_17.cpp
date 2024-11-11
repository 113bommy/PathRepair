#include <bits/stdc++.h>
using namespace std;
long kx[] = {2, -2, 2, -2, 1, -1, 1, -1};
long ky[] = {1, 1, -1, -1, 2, 2, -2, -2};
long dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
long dy[] = {0, 0, 1, -1, 1, 1, -1, -1};
const long INF = (1e9);
inline long MOD(long a, long b) {
  long res = a % b;
  return res < 0 ? res + abs(b) : res;
}
inline long Pow(long base, long exp) {
  long res = 1;
  while (exp > 0) {
    if (exp & 1) res *= base;
    exp >>= 1;
    base *= base;
  }
  return res;
}
inline long Log(long base, long n) {
  long ans = (long)(floor(log10((double)n) / log10((double)base)) + 1e-7);
  return ans;
}
inline long BigMod(long base, long exp, long M) {
  base = MOD(base, M);
  long res = 1;
  while (exp > 0) {
    if (exp & 1) res = MOD(res * base, M);
    exp >>= 1;
    base = MOD(base * base, M);
  }
  return res;
}
long d[100009], h[100009];
int main() {
  long g, x, y, z, i, j, k, l, m, n, p, q, r, u, v, w, t, cas, edge, node, a, b,
      c, e, f, ans, cnt, ass;
  while (scanf("%ld %ld", &n, &m) == 2) {
    for (i = 0; i < m; i++) scanf("%ld %ld", &d[i], &h[i]);
    long Max = 0;
    k = 0;
    for (i = 0; i < m - 1; i++) {
      g = d[i + 1] - d[i];
      if (h[i + 1] > h[i] + g || h[i + 1] < h[i] - g) {
        k = 1;
        break;
      }
      ans = min(h[i + 1], h[i]) + (g + abs(h[i + 1] - h[i])) / 2;
      Max = max(Max, ans);
    }
    if (k)
      puts("IMPOSSIBLE");
    else {
      if (d[0] > 1) {
        Max = max(Max, d[0] - 1 + h[0]);
      }
      if (d[m - 1] < n) {
        Max = max(Max, n - d[m - 1] + h[m - 1]);
      }
      printf("%ld\n", Max);
    }
  }
  return 0;
}
