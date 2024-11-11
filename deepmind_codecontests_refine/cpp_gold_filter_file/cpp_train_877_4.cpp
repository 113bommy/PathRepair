#include <bits/stdc++.h>
using namespace std;
long long int x, y;
long long int gcd(long long int a, long long int b) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long int gc = gcd(b % a, a);
  long long int temp;
  temp = x;
  x = y - (b / a) * temp;
  y = temp;
  return gc;
}
vector<pair<int, int> > tree[3 * 200005];
vector<pair<int, pair<int, int> > > edges;
int dp[3 * 200005];
int second[3 * 200005];
int pre[3 * 200005];
int t[3 * 200005];
int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int i;
  int u, v, w;
  for (i = 0; i < m; i++) {
    cin >> u >> v >> w;
    tree[u].push_back(make_pair(v, w));
    edges.push_back(make_pair(w, make_pair(v, u)));
  }
  sort(edges.begin(), edges.end());
  for (i = 0; i < m; i++) {
    if (t[edges[i].second.first] != edges[i].first) {
      t[edges[i].second.first] = edges[i].first;
      pre[edges[i].second.first] = dp[edges[i].second.first];
    }
    if (dp[edges[i].second.first] < dp[edges[i].second.second] + 1) {
      if (second[edges[i].second.second] != edges[i].first) {
        dp[edges[i].second.first] = dp[edges[i].second.second] + 1;
        second[edges[i].second.first] = edges[i].first;
      } else {
        dp[edges[i].second.first] =
            max(dp[edges[i].second.first], pre[edges[i].second.second] + 1);
        second[edges[i].second.first] = edges[i].first;
      }
    }
  }
  int ans = 0;
  for (i = 1; i <= n; i++) ans = max(ans, dp[i]);
  cout << ans << endl;
}
