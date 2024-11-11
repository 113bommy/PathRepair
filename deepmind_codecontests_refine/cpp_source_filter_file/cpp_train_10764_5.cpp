#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9, mxn = 1000;
struct circle {
  long long r, x, y;
  circle() {}
  circle(long long _r, long long _x, long long _y) : r(_r), x(_x), y(_y) {}
  bool operator<(const circle &o) const { return r < o.r; }
};
int dist[mxn];
vector<int> g[mxn];
int bfs(int s, int t) {
  memset(dist, -1, sizeof dist);
  dist[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (u == t) return dist[t];
    for (int i = (0); i < (g[u].size()); ++i) {
      int v = g[u][i];
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<circle> knights(n), fences(m);
  for (int i = (0); i < (n); ++i) {
    long long x, y;
    cin >> x >> y;
    knights[i] = circle(0, x, y);
  }
  for (int i = (0); i < (m); ++i) {
    long long r, x, y;
    cin >> r >> x >> y;
    fences[i] = circle(r, x, y);
  }
  sort(fences.rbegin(), fences.rend());
  vector<int> cc(n, -1), p(m, -1);
  for (int i = (0); i < (m); ++i) {
    for (int j = (i + 1); j < (m); ++j) {
      circle a = fences[i], b = fences[j];
      if ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) < (a.r) * (a.r))
        p[j] = i;
    }
    for (int j = (0); j < (n); ++j) {
      circle a = fences[i], b = knights[j];
      if ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) < (a.r) * (a.r))
        cc[j] = i;
    }
  }
  for (int i = (0); i < (m); ++i) {
    int u = p[i] + 1, v = i + 1;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  while (k--) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    int cca = cc[a] + 1, ccb = cc[b] + 1;
    int ans = bfs(cca, ccb);
    cout << ans << '\n';
  }
  return 0;
}
