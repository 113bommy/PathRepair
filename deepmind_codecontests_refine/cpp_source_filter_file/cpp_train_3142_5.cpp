#include <bits/stdc++.h>
using namespace std;
const int N_MAX = 19;
int f[1 << N_MAX][N_MAX];
long long a[N_MAX][N_MAX];
int n;
long long solve(int mask, int v) {
  if (f[mask][v] != -1) return f[mask][v];
  long long ret = 0;
  int ctz = __builtin_ctz(mask);
  if (__builtin_popcount(mask) == 1) {
    ret = (ctz == v);
  } else {
    if (v != ctz) {
      for (int i = 0; i < n; ++i)
        if (a[i][v] && (mask & (1 << i))) {
          ret += solve(mask ^ (1 << v), i);
        }
    }
  }
  f[mask][v] = ret;
  return ret;
}
int main() {
  memset(f, -1, sizeof(f));
  cin >> n;
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    a[u][v] = a[v][u] = 1;
  }
  long long ans = 0;
  for (int mask = 0; mask < (1 << n); ++mask) {
    if (__builtin_popcount(mask) >= 3)
      for (int i = 0; i < n; ++i)
        if ((mask & (1 << i)) != 0 && __builtin_ctz(mask) != i &&
            a[i][__builtin_ctz(mask)])
          ans += solve(mask, i);
  }
  cout << ans / 2 << '\n';
  return 0;
}
