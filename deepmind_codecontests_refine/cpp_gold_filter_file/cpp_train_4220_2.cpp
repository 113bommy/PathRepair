#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0), eps = 1e-4;
const int inf = ~0U >> 2;
int mod = 1e9 + 7;
int Pow(int x, long long t) {
  int r = 1;
  for (; t; t >>= 1, x = (long long)x * x % mod)
    if (t & 1) r = (long long)r * x % mod;
  return r;
}
const long long linf = (long long)inf * inf;
const int N = 5, M = 101010;
int xcost[N][M], ycost[N][M];
int n, m;
long long f[2][1 << N];
void Update(long long &x, long long d) {
  if (x > d) x = d;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m - 1; ++i)
    for (int j = 0; j < n; ++j) scanf("%d", &xcost[j][i]);
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j) scanf("%d", &ycost[j][i]);
  int c = 0;
  for (int i = 0; i < 1 << n; ++i) f[c][i] = linf;
  f[c][(1 << n) - 1] = 0;
  for (int i = 1; i < m; ++i)
    for (int j = 0; j < n; ++j) {
      c ^= 1;
      for (int i = 0; i < 1 << n; ++i) f[c][i] = linf;
      for (int mask = 0; mask < 1 << n; ++mask) {
        int newmask = mask & (~(1 << j));
        long long Cost = 0;
        if (j >= 1) Cost += mask >> (j - 1) & 1 ? 0 : ycost[j - 1][i];
        if (j == n - 1) Cost += mask & 1 ? 0 : ycost[j][i];
        Update(f[c][newmask | (1 << j)], f[c ^ 1][mask] + Cost);
        Cost = mask >> j & 1 ? xcost[j][i - 1] : 0;
        if (j >= 1) Cost += mask >> (j - 1) & 1 ? ycost[j - 1][i] : 0;
        if (j == n - 1) Cost += mask & 1 ? ycost[j][i] : 0;
        Update(f[c][newmask], f[c ^ 1][mask] + Cost);
      }
    }
  cout << f[c][0] << endl;
  return 0;
}
