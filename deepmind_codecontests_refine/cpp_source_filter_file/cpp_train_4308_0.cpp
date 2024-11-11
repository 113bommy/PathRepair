#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> adj[100005];
set<pair<int, int> > S;
bool vis[100005], sol[100005];
bool solve(int f, int s, int t, bool print, int depth = 0) {
  if (depth == n - 3) return 1;
  for (int i = 0; i < (int)adj[t].size(); i++) {
    if (S.count(make_pair(s, adj[t][i])) && f != adj[t][i] && !vis[adj[t][i]]) {
      vis[adj[t][i]] = 1;
      if (solve(s, t, adj[t][i], print, depth + 1)) {
        if (print) cout << " " << 1 + adj[t][i];
        return 1;
      }
    }
  }
  return 0;
}
int main() {
  int u, v;
  cin >> n;
  for (int i = 0; i < 2 * n; i++) {
    cin >> u >> v;
    --u;
    --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    S.insert(make_pair(u, v));
    S.insert(make_pair(v, u));
    sol[u] = adj[u].size() == 4;
    sol[v] = adj[v].size() == 4;
  }
  if (find(sol, sol + n, 0) != sol + n) {
    cout << "-1\n";
    return 0;
  }
  int f = 0, s, t;
  for (int i = 0; i < (int)adj[0].size(); i++) {
    s = adj[0][i];
    for (int j = 0; j < (int)adj[0].size(); j++)
      if (i != j) {
        t = adj[0][j];
        if (S.count(make_pair(s, t))) {
          memset(vis, 0, sizeof vis);
          vis[f] = vis[s] = vis[t] = 1;
          if (solve(f, s, t, 0)) {
            cout << f + 1 << " " << s + 1 << " " << t + 1;
            memset(vis, 0, sizeof vis);
            vis[f] = vis[s] = vis[t] = 1;
            solve(f, s, t, 1);
            cout << "\n";
            return 0;
          }
        }
      }
  }
  cout << "-1\n";
  return 0;
}
