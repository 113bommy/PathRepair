#include <bits/stdc++.h>
using namespace std;
vector<int> a[200010];
pair<int, int> b[200010];
int f[200010], vis[200010], ans[200010];
void dfs(int x, int fa) {
  f[x] = fa;
  b[x].first = b[fa].first - 1;
  for (int i : a[x]) {
    if (i == fa) continue;
    dfs(i, x);
  }
}
int go(int x) {
  if (vis[x] or x == 0) return 0;
  vis[x] = 1;
  return go(f[x]) + 1;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    b[i].second = i;
  }
  dfs(1, 0);
  sort(b + 1, b + 1 + n);
  int cnt = 0;
  for (int i = 1; i <= n; i++) ans[i] = go(b[i].second);
  sort(ans + 1, ans + 1 + n);
  int res = 0;
  long long Ans = 1ll * (n - n / 2) * (-n / 2);
  for (int i = n; i >= n - k + 1; i--) {
    res += ans[i];
    int blue = min(n - res, n / 2);
    int red = n - i + 1;
    long long A = 1ll * (n - blue - red) * (red - blue);
    Ans = max(Ans, A);
  }
  cout << Ans << '\n';
  return 0;
}
