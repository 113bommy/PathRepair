#include <bits/stdc++.h>
long long const MAX = 1e5 + 5;
using namespace std;
set<pair<long long, long long> > st;
vector<long long> adj[2001];
long long vis[2001];
vector<long long> visit;
void dfs(long long v) {
  vis[v] = 1;
  visit.push_back(v);
  for (auto i : adj[v]) {
    if (!vis[i]) dfs(i);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  for (long long i = 0; i < k; i++) {
    long long x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  long long m;
  cin >> m;
  for (long long i = 0; i < m; i++) {
    long long x, y;
    cin >> x >> y;
    if (x > y) swap(x, y);
    st.insert({x, y});
  }
  long long ans = 1;
  for (long long i = 1; i < n + 1; i++) {
    if (!vis[i]) {
      visit.clear();
      dfs(i);
      long long cnt = visit.size();
      int f = 0;
      for (long long j = 0; j < cnt; j++) {
        for (long long k = 0; k < cnt; k++) {
          if (st.find({min(visit[j], visit[k]), max(visit[j], visit[k])}) !=
              st.end())
            f = 1;
        }
      }
      if (f == 0) ans = max(ans, cnt);
    }
  }
  return cout << ans, 0;
  ;
}
