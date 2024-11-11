#include <bits/stdc++.h>
using namespace std;
long long n, m, x, y, v[200005], dp[200005], s, ans;
vector<pair<long long, long long> > a[200005];
vector<long long> V;
void dfs(long long x, long long p, long long d) {
  if (v[x]) return;
  v[x] = 1;
  dp[x] = d;
  for (auto i : a[x]) {
    if (i.first != p) {
      s += i.second == -1;
      dfs(i.first, x, i.second + d);
    }
  }
}
void solve() {
  cin >> n;
  m = n - 1;
  while (m--) {
    cin >> x >> y;
    a[x].push_back({y, 1});
    a[y].push_back({x, -1});
  }
  dfs(1, -1, 0);
  ans = s;
  for (__typeof((n + 1)) i = (1); i < (n + 1); i++) {
    if (s + dp[i] < ans) {
      ans = s + dp[i];
      V.clear();
      V.push_back(i);
    } else if (s + dp[i] == ans)
      V.push_back(i);
  }
  cout << ans << "\n";
  for (auto i : V) cout << i << " ";
}
void prep() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  prep();
  cout << fixed << setprecision(12);
  while (t--) solve();
  return 0;
}
