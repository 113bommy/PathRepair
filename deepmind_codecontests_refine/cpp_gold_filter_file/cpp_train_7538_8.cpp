#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int min(int a, int b) { return (a < b) ? a : b; }
int max(int a, int b) { return (a > b) ? a : b; }
const int N = 10005, M = 200005;
vector<array<int, 2>> v[N];
vector<int> edgeId(M), flow(M);
int n;
class Dinic {
 public:
  int src, des, n;
  vector<int> lvl, nxt;
  vector<array<int, 2>> path;
  Dinic() {
    lvl = vector<int>(N);
    nxt = vector<int>(N);
  }
  void init(int n1, int Src, int Des, int m1) {
    n = n1;
    src = Src;
    des = Des;
    for (int i = 0; i <= m1; i++) {
      edgeId[i] = 0;
      flow[i] = 0;
    }
    for (int i = 0; i <= n; i++) {
      v[i].clear();
    }
  }
  bool bfs() {
    queue<int> q;
    q.push(src);
    fill(lvl.begin(), lvl.end(), -1);
    lvl[src] = 0;
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      for (auto i : v[node]) {
        if (lvl[i[0]] != -1 || edgeId[i[1]] == 0) continue;
        q.push(i[0]);
        lvl[i[0]] = lvl[node] + 1;
      }
    }
    return lvl[des] != -1;
  }
  int dfs(int node, int push) {
    if (push == 0 || node == des) {
      if (node == des) path.push_back({des, -1});
      return push;
    }
    for (; nxt[node] < v[node].size(); nxt[node]++, path.clear()) {
      int id = v[node][nxt[node]][1];
      int y = v[node][nxt[node]][0];
      if (edgeId[id] == 0 || lvl[node] + 1 != lvl[y]) continue;
      int f = dfs(y, min(push, edgeId[id]));
      if (f == 0) continue;
      flow[id] += f;
      path.push_back({node, id});
      return f;
    }
    return 0;
  }
  int maxflow() {
    int mx = 0;
    while (bfs()) {
      fill(nxt.begin(), nxt.end(), 0);
      for (int f; f = dfs(src, INT_MAX);) {
        if (f == 0) {
          path.clear();
          break;
        }
        reverse(path.begin(), path.end());
        for (int j = 0; j < path.size() - 1; j++) {
          edgeId[path[j][1]] -= f;
          edgeId[path[j][1] ^ 1] += f;
        }
        mx += f;
        path.clear();
      }
    }
    return mx;
  }
};
int m1;
int N1 = 505;
vector<int> g[505];
Dinic d;
int solve(int c) {
  int ans = 0;
  int tot = m1;
  for (int i = 1; i <= n; i++) {
    if (i == c) {
      ans += (n - g[c].size());
      tot -= g[c].size();
    } else {
      int f = 0;
      for (auto j : g[i]) {
        if (j == c) {
          f = 1;
          break;
        }
      }
      if (f) {
        tot--;
      } else {
        ans++;
      }
    }
  }
  int src = 0;
  int des = 2 * n + 1;
  int id = 1;
  d.init(2 * n + 100, src, des, m1 + 2 * n + 1000);
  for (int i = 1; i <= n; i++) {
    if (i == c) continue;
    for (auto j : g[i]) {
      if (j == c) continue;
      v[i].push_back({j + n, ++id});
      edgeId[id] = 1;
      v[j + n].push_back({i, ++id});
    }
  }
  for (int i = 1; i <= n; i++) {
    v[src].push_back({i, ++id});
    edgeId[id] = 1;
    v[i].push_back({src, ++id});
  }
  for (int i = 1; i <= n; i++) {
    v[n + i].push_back({des, ++id});
    edgeId[id] = 1;
    v[des].push_back({n + i, ++id});
  }
  int x = d.maxflow();
  int y = tot - x + (n - 1 - x);
  ans += y;
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m1;
  int ans = 1e18;
  int x, y;
  for (int i = 1; i <= m1; i++) {
    cin >> x >> y;
    g[x].push_back(y);
  }
  for (int i = 1; i <= n; i++) {
    sort(g[i].begin(), g[i].end());
  }
  for (int i = 1; i <= n; i++) {
    ans = min(ans, solve(i));
  }
  cout << ans;
}
