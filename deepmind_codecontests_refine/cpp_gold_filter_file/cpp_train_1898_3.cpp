#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g;
vector<int> special;
int n, m, k;
vector<int> Bfs(int s) {
  vector<int> dis(n, -1);
  queue<int> q;
  q.push(s);
  dis[s] = 0;
  while (q.size() > 0) {
    int x = q.front();
    q.pop();
    for (int y : g[x])
      if (dis[y] == -1) {
        q.push(y);
        dis[y] = 1 + dis[x];
      }
  }
  return dis;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k;
  g.assign(n, vector<int>{});
  special.resize(k);
  for (int i = 0; i < k; i++) {
    cin >> special[i];
    special[i]--;
  }
  for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;
    from--, to--;
    g[from].push_back(to);
    g[to].push_back(from);
  }
  vector<int> d0 = Bfs(0);
  vector<int> dn = Bfs(n - 1);
  sort(special.begin(), special.end(),
       [&](int i, int j) { return d0[i] < d0[j]; });
  int ans = 0;
  for (int i = 0; i + 1 < k; i++) {
    int s = special[i], t = special[i + 1];
    ans = max(ans, d0[s] + dn[t] + 1);
  }
  cout << min(ans, d0[n - 1]) << '\n';
  return 0;
}
