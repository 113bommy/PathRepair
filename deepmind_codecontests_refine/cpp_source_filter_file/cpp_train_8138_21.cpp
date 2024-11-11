#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1000000001, INF = (ll)1e18 + 1;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> x(m);
  for (int i = 0; i < m; i++) {
    cin >> x[i];
  }
  vector<int> pre(n + 1, 0);
  for (int i = 0; i < m - 1; i++) {
    if (x[i] == x[i + 1]) continue;
    pre[min(x[i], x[i + 1]) + 1]++;
    pre[max(x[i], x[i + 1])]--;
  }
  for (int i = 1; i < n + 1; i++) {
    pre[i] += pre[i - 1];
  }
  vector<vector<int> > adj(n + 1);
  for (int i = 1; i < m - 1; i++) {
    if (x[i] != x[i + 1]) adj[x[i]].push_back(x[i + 1]);
    if (x[i] != x[i - 1]) adj[x[i]].push_back(x[i - 1]);
  }
  if (m > 1)
    if (x[0] != x[1]) adj[x[0]].push_back(x[1]);
  if (m > 1)
    if (x[m - 1] != x[m - 2]) adj[x[m - 1]].push_back(x[m - 2]);
  int basic = 0;
  for (int i = 1; i < m; i++) {
    basic += abs(x[i] - x[i - 1]);
  }
  for (int i = 1; i <= n; i++) {
    int ans = basic - pre[i];
    for (int j : adj[i]) {
      ans -= abs(i - j);
      if (j > i)
        ans += j - 1;
      else
        ans += j;
    }
    cout << ans << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
