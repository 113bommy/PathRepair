#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n, m, sum, a[N];
vector<int> g[N];
bool ok(int mid) {
  int pay[N];
  memset(pay, 0, sizeof pay);
  for (int i = 1; i <= n; i++) {
    int mx = -1;
    for (int j = 0; j < g[i].size(); j++) {
      if (g[i][j] <= mid) mx = max(mx, g[i][j]);
    }
    if (mx != -1) {
      pay[mx] += a[i];
    }
  }
  int has = 0, saved = 0;
  for (int i = 1; i <= mid; i++) {
    has++;
    int can = min(has, pay[i]);
    has -= can;
    saved += can;
  }
  return (2 * sum) - saved <= mid;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  for (int x, y, i = 1; i <= m; i++) {
    cin >> x >> y;
    g[y].push_back(x);
  }
  int l = 0, r = sum * 2, mid, ans;
  while (l <= r) {
    mid = (l + r) / 2;
    if (ok(mid)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << ans << '\n';
  return 0;
}
