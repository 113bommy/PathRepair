#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 100005;
long long tot;
priority_queue<pair<long long, pair<long long, long long> > > PQ;
long long leaf[MAXN];
vector<pair<long long, long long> > adj[MAXN];
void dfs(long long now, long long par) {
  bool daun = true;
  leaf[now] = 0;
  for (auto nxt : adj[now]) {
    if (nxt.first == par) continue;
    dfs(nxt.first, now);
    tot += leaf[nxt.first] * nxt.second;
    PQ.push({leaf[nxt.first] * ((nxt.second + 1) / 2),
             {nxt.second / 2, leaf[nxt.first]}});
    leaf[now] += leaf[nxt.first];
    daun = false;
  }
  if (daun) leaf[now] = 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, n, s, u, v, w;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    tot = 0;
    while (!PQ.empty()) PQ.pop();
    for (long long i = 1; i <= n; i++) adj[i].clear();
    for (long long i = 1; i < n; i++) {
      cin >> u >> v >> w;
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }
    dfs(1, -1);
    long long ans = 0;
    while (tot > s) {
      pair<long long, pair<long long, long long> > ambil = PQ.top();
      PQ.pop();
      tot -= ambil.first;
      long long nxt = ambil.second.first;
      PQ.push({ambil.second.second * (nxt + 1) / 2,
               {nxt / 2, ambil.second.second}});
      ans++;
    }
    cout << ans << '\n';
  }
  return 0;
}
