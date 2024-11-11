#include <bits/stdc++.h>
using namespace std;
const int lim = 3 * 1e5 + 5;
int n, m, s, visit[lim], ans = 1;
vector<vector<pair<int, int> > > adj(lim);
vector<pair<pair<int, int>, pair<int, int> > > ed;
void dfs_max(int u) {
  visit[u] = 1;
  for (int(i) = 0; (i) < int((adj[u]).size()); (i)++) {
    pair<int, int> p = adj[u][i];
    if (visit[p.first] == 0) {
      ans++;
      if (ed[p.second].second.first == 2) {
        if (ed[p.second].first.first == u)
          ed[p.second].second.second = 1;
        else
          ed[p.second].second.second = -1;
      }
      dfs_max(p.first);
    }
  }
}
void dfs_min(int u) {
  visit[u] = 1;
  for (int(i) = 0; (i) < int((adj[u]).size()); (i)++) {
    pair<int, int> p = adj[u][i];
    if (visit[p.first] == 0) {
      if (ed[p.second].second.first == 2) {
        if (ed[p.second].first.first == u)
          ed[p.second].second.second = -1;
        else
          ed[p.second].second.second = 1;
      } else {
        ans++;
        dfs_max(p.first);
      }
    }
  }
}
void solve(int test) {
  cin >> n >> m >> s;
  for (int i = 0, t, u, v; i < m; i++) {
    cin >> t >> u >> v;
    if (t == 1)
      adj[u].push_back(pair<int, int>(v, i));
    else
      adj[u].push_back(pair<int, int>(v, i)),
          adj[v].push_back(pair<int, int>(u, i));
    ed.push_back(make_pair(pair<int, int>(u, v), pair<int, int>(t, 0)));
  }
  dfs_max(s);
  cout << ans << endl;
  for (int(i) = 0; (i) < m; (i)++) {
    if (ed[i].second.first == 2) {
      if (ed[i].second.second == 1)
        cout << '+';
      else
        cout << '-';
    }
  }
  cout << endl;
  ans = 1;
  memset(visit, 0, sizeof(visit));
  dfs_min(s);
  cout << ans << endl;
  for (int(i) = 0; (i) < m; (i)++) {
    if (ed[i].second.first == 2) {
      if (ed[i].second.second == 1)
        cout << '+';
      else
        cout << '-';
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int test = 1;
  for (int(i) = 0; (i) < test; (i)++) {
    solve(i + 1);
  }
  return 0;
}
