#include <bits/stdc++.h>
using namespace std;
const int maxn = 6400 + 233;
struct Edge {
  int from, to, cap, flow, cost;
};
vector<Edge> edges;
vector<int> g[maxn];
queue<int> q;
int d[maxn], p[maxn];
bool inq[maxn];
void add_edge(int from, int to, int cap, int cost) {
  edges.push_back((Edge){from, to, cap, 0, cost});
  edges.push_back((Edge){to, from, 0, 0, -cost});
  int m = edges.size();
  g[from].push_back(m - 2);
  g[to].push_back(m - 1);
  return;
}
struct MCMF {
  int s, t;
  bool spfa() {
    for (int i = 0; i < maxn; i++) d[i] = 1 << 30;
    d[s] = 0;
    q.push(s);
    p[s] = -1;
    inq[s] = 1;
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      inq[x] = 0;
      for (int i = 0; i < g[x].size(); i++) {
        Edge e = edges[g[x][i]];
        if (e.flow == e.cap) continue;
        int y = e.to;
        if (d[y] > d[x] + e.cost) {
          d[y] = d[x] + e.cost;
          p[y] = g[x][i];
          if (!inq[y]) q.push(y);
          inq[y] = 1;
        }
      }
    }
    if (d[t] == (1 << 30)) return 0;
    return 1;
  }
  int mincost(int s, int t) {
    this->s = s;
    this->t = t;
    int cost = 0, flow = 0;
    while (spfa()) {
      int f = 1 << 30;
      for (int i = p[t]; i != -1; i = p[edges[i].from]) {
        Edge e = edges[i];
        f = min(f, e.cap - e.flow);
      }
      flow += f;
      for (int i = p[t]; i != -1; i = p[edges[i].from]) {
        Edge& e = edges[i];
        e.flow += f;
        edges[i ^ 1].flow -= f;
        cost += f * e.cost;
      }
    }
    return cost;
  }
} F;
int c[70][70];
int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int num(int x, int y) { return (x - 1) * m + y; }
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &c[i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (((i + j) & 1) == 0)
        for (int k = 0; k < 4; k++) {
          int x = i + dx[k];
          int y = j + dy[k];
          if (x < 1 || y < 1 || x > n || y > m) continue;
          int a = num(i, j), b = num(x, y);
          if (c[i][j] == c[x][y])
            add_edge(a, b, 1, 0);
          else
            add_edge(a, b, 1, 1);
        }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (((i + j) & 1) == 0)
        add_edge(0, num(i, j), 1, 0);
      else
        add_edge(num(i, j), n * m + 1, 1, 0);
  cout << F.mincost(0, n * m + 1) << endl;
  return 0;
}
