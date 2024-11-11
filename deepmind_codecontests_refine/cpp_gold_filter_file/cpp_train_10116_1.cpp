#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100005;
ll a[N];
int n, f[66][N], id[N];
int sum[2][N];
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) a[i] = a[n] - a[i], id[i] = i;
  memset(f, 63, sizeof(f));
  f[0][0] = 0;
  for (int k = 0; k <= 60; k++) {
    sort(id + 1, id + n + 1, [&](int x, int y) {
      return (a[x] & ((1ll << k) - 1)) < (a[y] & ((1ll << k) - 1));
    });
    for (int i = 1; i <= n; i++) {
      sum[0][i] = sum[0][i - 1];
      sum[1][i] = sum[1][i - 1];
      ++sum[(a[id[i]] >> k) & 1][i];
    }
    for (int i = 0; i <= n; i++) {
      int ww, tt;
      ww = sum[1][n - i] + sum[0][n] - sum[0][n - i];
      tt = sum[1][n] - sum[1][n - i];
      f[k + 1][tt] = min(f[k + 1][tt], f[k][i] + ww);
      ww = sum[0][n - i] + sum[1][n] - sum[1][n - i];
      tt = n - sum[0][n - i];
      f[k + 1][tt] = min(f[k + 1][tt], f[k][i] + ww);
    }
  }
  cout << f[61][0] << endl;
  return 0;
}
