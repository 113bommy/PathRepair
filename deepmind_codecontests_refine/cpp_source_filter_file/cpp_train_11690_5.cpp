#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int INF = 1000000000;
const int MOD = 1000000007;
const int M = INF;
const double RRR = 180.0 / PI;
vector<vector<pair<int, int> > > g;
vector<int> used;
struct edge {
  int a, b, w;
};
int main() {
  int n, m, s;
  cin >> n >> m >> s;
  s--;
  g.resize(n);
  int a, b, w;
  vector<edge> edges(m);
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> w;
    a--;
    b--;
    g[a].push_back(make_pair(b, w));
    g[b].push_back(make_pair(a, w));
    edges[i].a = a;
    edges[i].b = b;
    edges[i].w = w;
  }
  int l;
  cin >> l;
  vector<int> d(n, INF);
  d[s] = 0;
  set<pair<int, int> > q;
  q.insert(make_pair(d[s], s));
  while (!q.empty()) {
    int v = q.begin()->second;
    q.erase(q.begin());
    for (int j = 0; j < g[v].size(); j++) {
      int to = g[v][j].first;
      int len = g[v][j].second;
      if (d[to] > d[v] + len) {
        q.erase(make_pair(d[to], to));
        d[to] = d[v] + len;
        q.insert(make_pair(d[to], to));
      }
    }
  }
  int k = 0;
  for (int j = 0; j < n; j++) {
    if (d[j] == l) {
      k++;
    }
  }
  set<pair<int, pair<int, int> > > buf;
  for (int i = 0; i < m; i++) {
    if (d[edges[i].a] < l && l < d[edges[i].a] + edges[i].w &&
        l <= d[edges[i].b] + edges[i].w - l + d[edges[i].a]) {
      buf.insert(
          make_pair(l - d[edges[i].a], make_pair(edges[i].a, edges[i].b)));
    }
  }
  for (int i = 0; i < m; i++) {
    if (d[edges[i].b] < l && l < d[edges[i].a] + edges[i].w &&
        l <= d[edges[i].a] + edges[i].w - l + d[edges[i].b]) {
      buf.insert(make_pair(edges[i].w - l + d[edges[i].b],
                           make_pair(edges[i].a, edges[i].b)));
    }
  }
  cout << k + buf.size();
  return 0;
}
