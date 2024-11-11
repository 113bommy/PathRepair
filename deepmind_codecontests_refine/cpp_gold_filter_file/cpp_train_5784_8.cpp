#include <bits/stdc++.h>
using namespace std;
const int LEN = 1100;
const long long INF = 1e10;
struct Answer {
  long long cost;
  vector<int> edge;
  Answer() {
    cost = 0;
    edge.clear();
  }
  void print();
};
void Answer::print() {
  if (cost == INF)
    cout << -1;
  else {
    cout << cost << endl;
    cout << edge.size() << endl;
    for (int i = 0; i < edge.size(); i++) cout << edge[i] + 1 << " ";
  }
}
bool operator<(const Answer &a, const Answer &b) { return (a.cost < b.cost); }
struct Edge {
  int ind, u, v;
  long long cost = 0;
  int get(int a);
};
int Edge::get(int a) {
  if (a == v) return u;
  return v;
}
int n, second, t, m, a, b, eduse[30 * LEN];
vector<Edge> ed[LEN], edges;
vector<pair<int, int> > q, way, way1;
vector<int> use, fup, height;
Edge e;
long long cost;
Answer ans, ans1;
void get_way(int v, int first, int e, vector<pair<int, int> > &way) {
  use[v] = 1;
  q.push_back(make_pair(v, e));
  if (v == first) way = q;
  for (int i = 0; i < ed[v].size(); i++)
    if (!use[ed[v][i].get(v)] && !eduse[ed[v][i].ind])
      get_way(ed[v][i].get(v), first, ed[v][i].ind, way);
  q.pop_back();
}
void get_fup(int v, int p, int h) {
  use[v] = 1;
  height[v] = fup[v] = h;
  int u;
  for (int i = 0; i < ed[v].size(); i++) {
    if (ed[v][i].ind == p || eduse[ed[v][i].ind] || v == ed[v][i].get(v))
      continue;
    u = ed[v][i].get(v);
    if (!use[u]) get_fup(u, ed[v][i].ind, h + 1);
    if (use[u] == 1)
      fup[v] = min(fup[v], height[u]);
    else
      fup[v] = min(fup[v], fup[u]);
  }
  use[v] = 2;
}
int main() {
  cin >> n >> m;
  cin >> second >> t;
  second--;
  t--;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> cost;
    a--;
    b--;
    e.ind = i;
    e.cost = cost;
    e.v = a;
    e.u = b;
    ed[a].push_back(e);
    ed[b].push_back(e);
    edges.push_back(e);
  }
  use.resize(LEN, 0);
  get_way(second, t, -1, way);
  if (!use[t]) {
    cout << 0 << endl;
    cout << 0 << endl;
    return 0;
  }
  use.clear();
  use.resize(LEN, 0);
  fup.clear();
  fup.resize(LEN, 0);
  height.clear();
  height.resize(LEN, 0);
  get_fup(second, -1, 0);
  ans.cost = INF;
  for (int i = 1; i < way.size(); i++)
    if (fup[way[i].first] == height[way[i].first]) {
      ans1.cost = edges[way[i].second].cost;
      ans1.edge.clear();
      ans1.edge.push_back(way[i].second);
      ans = min(ans, ans1);
    }
  for (int i = 1; i < way.size(); i++) {
    eduse[way[i].second] = 1;
    q.clear();
    use.clear();
    use.resize(LEN, 0);
    way1.clear();
    get_way(second, t, -1, way1);
    if (!use[t]) {
      eduse[way[i].second] = 0;
      continue;
    }
    use.clear();
    use.resize(LEN, 0);
    fup.clear();
    fup.resize(LEN, 0);
    height.clear();
    height.resize(LEN, 0);
    get_fup(second, -1, 0);
    for (int j = 1; j < way1.size(); j++)
      if (fup[way1[j].first] == height[way1[j].first]) {
        ans1.cost = edges[way[i].second].cost + edges[way1[j].second].cost;
        ans1.edge.clear();
        ans1.edge.push_back(way[i].second);
        ans1.edge.push_back(way1[j].second);
        if (ans.cost > ans1.cost) {
          ans.cost = ans1.cost;
          ans.edge = ans1.edge;
        }
      }
    eduse[way[i].second] = 0;
  }
  ans.print();
  return 0;
}
