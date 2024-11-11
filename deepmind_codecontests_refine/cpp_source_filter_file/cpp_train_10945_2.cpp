#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1000000000;
vector<long long> adj[N];
long long n;
bool vis[N];
long long par[N];
signed main() {
  long long m;
  cin >> n >> m;
  for (long long i = 1; i <= m; i++) {
    long long u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  long long nd = -1, ma = 0;
  for (long long i = 1; i <= n; i++) {
    if ((long long)adj[i].size() > ma) {
      ma = (long long)adj[i].size();
      nd = i;
    }
  }
  vector<pair<long long, long long>> ans;
  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
                 greater<pair<long long, long long>>>
      pq;
  pq.push(make_pair(0, nd));
  while (!pq.empty()) {
    pair<long long, long long> u = pq.top();
    pq.pop();
    if (vis[u.second]) continue;
    vis[u.second] = true;
    if (par[u.second] != 0) ans.push_back(make_pair(par[u.second], u.second));
    for (auto v : adj[u.second]) {
      if (vis[v] == false) {
        long long dd = 1;
        if (u.second == nd) dd = 0;
        pq.push(make_pair(dd, v));
        par[v] = u.second;
      }
    }
  }
  for (auto x : ans) cout << x.first << " " << x.second << endl;
}
