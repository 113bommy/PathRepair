#include <bits/stdc++.h>
using namespace std;
vector<int> l[200005];
int n, dp[200005], r, x, y;
int dfs(int i, int p) {
  int add = 0;
  for (int j = 0; j < l[i].size(); j++) {
    int k = l[i][j];
    if (k != p) add += dfs(k, i);
  }
  if (add >= 2) {
    r += 2;
    return 0;
  }
  r += add;
  return 1;
}
int main() {
  cin >> n >> x >> y;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    l[a].push_back(b);
    l[b].push_back(a);
  }
  if (x >= y) {
    long long res = 1LL * (n - 1) * y;
    for (int i = 1; i <= n; i++) {
      if (l[i].size() == n - 1) {
        res += x - y;
        break;
      }
    }
    cout << res << '\n';
    return 0;
  }
  dfs(1, 0);
  cout << 1LL * r * x + 1LL * (n - 1 - r) * y << '\n';
  return 0;
}
