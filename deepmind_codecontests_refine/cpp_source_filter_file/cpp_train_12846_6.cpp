#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int m, n, a[maxn][maxn];
int nz, z[maxn * maxn];
int timer, h[maxn][maxn], top[maxn];
int cnt[maxn][maxn];
void enter() {
  cin >> m >> n;
  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
      z[++nz] = a[i][j];
    }
  sort(z + 1, z + nz + 1);
  nz = unique(z + 1, z + nz + 1) - z;
}
bool check(int ret) {
  ++timer;
  for (int i = 1; i <= n; ++i) top[i] = 0;
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j)
      if (a[i][j] >= ret) {
        for (int k = 1; k <= top[j]; ++k) {
          if (cnt[h[j][k]][i] == timer) return 1;
          cnt[h[j][k]][i] = timer;
        }
        h[j][++top[j]] = i;
      }
  }
  return 0;
}
void solve() {
  int l = 1, r = nz, res = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(z[mid])) {
      res = z[mid];
      l = mid + 1;
    } else
      r = mid - 1;
  }
  cout << res;
}
int main() {
  ios_base ::sync_with_stdio(0);
  enter();
  solve();
}
