#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> adj[300001];
vector<pair<long long, long long> > q[300001];
vector<long long> ans(300001);
vector<int> mp(300001);
void dfs(long long x, long long e, long long sm, long long cnt) {
  for (long long o = 0; o < q[x].size(); o++) {
    if (cnt + q[x][o].first <= n) {
      mp[cnt + q[x][o].first] += q[x][o].second;
    }
    sm += q[x][o].second;
  }
  ans[x] += sm;
  sm -= mp[cnt];
  cnt++;
  for (long long next : adj[x]) {
    if (e == next) {
      continue;
    }
    dfs(next, x, sm, cnt);
  }
  cnt--;
  for (long long o = 0; o < q[x].size(); o++) {
    if (cnt + q[x][o].first <= n) {
      mp[cnt + q[x][o].first] -= q[x][o].second;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  long long m;
  for (long long i = 0; i < n - 1; i++) {
    long long x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  cin >> m;
  while (m--) {
    long long v, d, x;
    cin >> v >> d >> x;
    q[v].push_back({d, x});
  }
  dfs(1, -1, 0, 0);
  for (long long i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
}
