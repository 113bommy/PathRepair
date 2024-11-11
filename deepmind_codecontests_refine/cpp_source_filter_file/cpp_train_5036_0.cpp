#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, m;
int a[N];
int b[N];
struct edge {
  int v, c, id;
  edge(int _v = 0, int _c = 0, int _id = 0) {
    v = _v;
    c = _c;
    id = _id;
  }
};
vector<int> g[N];
vector<edge> Edges;
queue<int> qq;
int flows[N];
int out[N];
void bfs() {
  qq.push(0);
  while (!qq.empty()) {
    int u = qq.front();
    qq.pop();
    for (int i = 0; i < (int)(g[u]).size(); ++i) {
      int e = g[u][i];
      int v = Edges[e].v;
      int c = Edges[e].c;
      int id = Edges[e].id;
      if (out[id] != -1) continue;
      if (b[id] == u)
        out[id] = 0;
      else
        out[id] = 1;
      flows[v] -= c;
      if (!flows[v]) {
        qq.push(v);
      }
    }
  }
  for (int i = 0; i < m; ++i) cout << out[i] << endl;
}
int main() {
  cin >> n >> m;
  memset(out, 0xff, sizeof out);
  for (int i = 0; i < m; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    u--;
    v--;
    flows[u] += c;
    flows[v] += c;
    b[i] = u;
    g[u].push_back((int)(Edges).size());
    Edges.push_back(edge(v, c, i));
    g[v].push_back((int)(Edges).size());
    Edges.push_back(edge(u, c, i));
  }
  for (int i = 0; i < n; ++i) flows[i] /= 2;
  flows[0] = 0;
  bfs();
  return 0;
}
