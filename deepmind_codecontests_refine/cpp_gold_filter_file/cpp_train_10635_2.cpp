#include <bits/stdc++.h>
using namespace std;
const int M = 200005;
vector<vector<int>> G(M);
bool vis[M];
vector<int> ev, od;
queue<pair<int, bool>> q;
inline void bfs(int root, bool idx) {
  vis[root] = 1;
  q.push(make_pair(root, 0));
  while (q.size()) {
    int curnode = q.front().first;
    bool id = q.front().second;
    q.pop();
    if (id)
      od.push_back(curnode);
    else
      ev.push_back(curnode);
    for (int i = 0; i < G[curnode].size(); ++i) {
      int newnode = G[curnode][i];
      if (vis[newnode]) continue;
      vis[newnode] = 1;
      q.push({newnode, !id});
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    memset(vis, 0, sizeof vis);
    G.clear();
    G.resize(n + 1);
    ev.clear();
    od.clear();
    for (int i = 1; i <= m; ++i) {
      int x, y;
      cin >> x >> y;
      G[x].push_back(y);
      G[y].push_back(x);
    }
    bfs(1, 0);
    if (ev.size() > od.size()) {
      cout << od.size() << "\n";
      for (int i = 0; i < od.size(); ++i) cout << od[i] << " ";
      cout << "\n";
    } else {
      cout << ev.size() << "\n";
      for (int i = 0; i < ev.size(); ++i) cout << ev[i] << " ";
      cout << "\n";
    }
  }
  return 0;
}
