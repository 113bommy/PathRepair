#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)1e18;
const long long mod = (long long)1e9 + 7;
const int inf = (int)1e9;
const double eps = (double)1e-9;
const double pi = acos(-1.0);
const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};
const int N = 300500;
int n, m, col[50], comp, F[3][(1 << 20)], cnt, sz;
long long ans, g[50];
bool type[3][(1 << 20)], type2[3][(1 << 20)];
void dfs(int v) {
  sz++;
  for (int i = 0; i < n; ++i)
    if (((g[v] >> i) & 1)) {
      if (!col[i]) {
        col[i] = 3 - col[v];
        dfs(i);
      }
    }
}
int main() {
  cin >> n >> m;
  if (m == 0) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x] ^= (1LL << y);
    g[y] ^= (1LL << x);
  }
  ans = (1LL << n);
  for (int i = 0; i < n; ++i)
    if (!col[i]) {
      col[i] = 1;
      comp++;
      sz = 0;
      dfs(i);
      if (sz == 1) cnt++;
    }
  bool ok = 1;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (((g[i] >> j) & 1) && col[i] == col[j]) ok = 0;
  if (ok) ans += (1LL << comp);
  ans += 2LL * (1LL << (cnt));
  ans -= (1LL << comp);
  m = min(20, n);
  for (int i = 0; i < (1 << m); ++i) {
    type[0][i] = type[1][i] = type[2][i] = 1;
    for (int x = 0; x < m; ++x)
      for (int y = x + 1; y < m; ++y)
        if (((g[x] >> y) & 1)) type[((i >> x) & 1) + ((i >> y) & 1)][i] = 0;
  }
  for (int i = 0; i < (1 << (n - m)); ++i) {
    for (int x = 0; x < n - m; ++x)
      for (int y = x + 1; y < n - m; ++y)
        if (((g[x + m] >> (y + m)) & 1))
          type2[((i >> x) & 1) + ((i >> y) & 1)][i] = 1;
  }
  for (int i = 0; i < (1 << m); ++i)
    F[0][i] = type[0][(i ^ ((1 << m) - 1))], F[2][i] = type[2][i];
  for (int j = 0; j < 3; ++j)
    for (int i = 0; i < m; ++i)
      for (int mask = 0; mask < (1 << m); ++mask) {
        if (mask & (1 << i)) F[j][mask] += F[j][mask ^ (1 << i)];
      }
  for (int j = 0; j < (1 << (n - m)); ++j) {
    long long cur = 0;
    for (int x = 0; x < (n - m); ++x)
      if (!((j >> x) & 1)) cur ^= g[x + m];
    cur &= ((1 << m) - 1);
    if (!type2[0][j]) {
      ans -= F[0][(cur ^ ((1 << m) - 1))];
    }
    cur = 0;
    for (int x = 0; x < (n - m); ++x)
      if (((j >> x) & 1)) cur ^= g[x + m];
    cur &= ((1 << m) - 1);
    if (!type2[2][j]) {
      ans -= F[2][(cur ^ ((1 << m) - 1))];
    }
  }
  cout << ans << endl;
  return 0;
}
