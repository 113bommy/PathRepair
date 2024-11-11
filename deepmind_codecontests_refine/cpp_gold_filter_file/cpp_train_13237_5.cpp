#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> col;
set<int> AdjList[100001];
int p[100001];
int anc(int x) {
  if (p[x] == x) return x;
  return p[x] = anc(p[x]);
}
void join(int x, int y) { p[anc(x)] = anc(y); }
struct Query {
  int type, u, v, c;
  Query() {}
  Query(int _type, int _u, int _v, int _c) {
    type = _type;
    u = _u;
    v = _v;
    c = _c;
  }
};
vector<Query> Q;
int n;
int m, C, q;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> C >> q;
  for (int i = 1; i <= m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    Q.push_back(Query(0, u, v, c));
  }
  for (int i = 1; i <= q; i++) {
    char z;
    cin >> z;
    if (z == '+') {
      int u, v, c;
      cin >> u >> v >> c;
      Q.push_back(Query(0, u, v, c));
    } else {
      int u, v;
      cin >> u >> v;
      Q.push_back(Query(1, u, v, -1));
    }
  }
  for (int i = 1; i <= n; i++) p[i] = i;
  for (int i = 0; i < Q.size(); i++) {
    if (!Q[i].type) {
      int u = Q[i].u;
      int v = Q[i].v;
      int c = Q[i].c;
      int anc_u = anc(u);
      int anc_v = anc(v);
      AdjList[anc_u].insert(v);
      AdjList[anc_v].insert(u);
      if (!col[pair<int, int>(u, c)]) col[pair<int, int>(u, c)] = v;
      if (!col[pair<int, int>(v, c)]) col[pair<int, int>(v, c)] = u;
      int z = col[pair<int, int>(v, c)];
      int anc_z = anc(z);
      if (anc_u != anc_z) {
        if (AdjList[anc_u].size() > AdjList[anc_z].size())
          swap(AdjList[anc_u], AdjList[anc_z]);
        while (!AdjList[anc_u].empty()) {
          AdjList[anc_z].insert(*AdjList[anc_u].begin());
          AdjList[anc_u].erase(AdjList[anc_u].begin());
        }
        p[anc_u] = anc_z;
      }
      z = col[pair<int, int>(u, c)];
      anc_z = anc(z);
      if (anc_v != anc_z) {
        if (AdjList[anc_v].size() > AdjList[anc_z].size())
          swap(AdjList[anc_v], AdjList[anc_z]);
        while (!AdjList[anc_v].empty()) {
          AdjList[anc_z].insert(*AdjList[anc_v].begin());
          AdjList[anc_v].erase(AdjList[anc_v].begin());
        }
        p[anc_v] = anc_z;
      }
    } else {
      int u = Q[i].u;
      int v = Q[i].v;
      int anc_u = anc(u);
      int anc_v = anc(v);
      if (anc_u == anc_v)
        cout << "Yes" << '\n';
      else if (AdjList[anc_u].find(v) != AdjList[anc_u].end())
        cout << "Yes" << '\n';
      else
        cout << "No" << '\n';
    }
  }
}
