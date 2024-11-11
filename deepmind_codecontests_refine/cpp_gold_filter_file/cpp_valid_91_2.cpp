#include <bits/stdc++.h>
using namespace std;
const unsigned MAX_N = 1E5 + 100;
class Edge {
 public:
  unsigned u, v, w;
  bool operator<(const Edge& x) const {
    return w != x.w ? w < x.w : u == x.u ? v < x.v : u < x.u;
  }
};
unsigned n, m, q;
map<unsigned, unsigned> G[MAX_N];
set<Edge> st[MAX_N], tot;
map<Edge, unsigned> vis;
void upd(unsigned u) {
  unsigned tmp = 0;
  for (auto it : st[u]) {
    if (1 == vis[it]++) tot.insert(it);
    if (3 == ++tmp) break;
  }
}
void rUpd(unsigned u) {
  unsigned tmp = 0;
  for (auto it : st[u]) {
    if (1 == --vis[it]) tot.erase(it);
    if (3 == ++tmp) break;
  }
}
void link(unsigned u, unsigned v, unsigned w) {
  rUpd(u), rUpd(v);
  if (u > v) swap(u, v);
  G[u][v] = w;
  st[u].insert({u, v, w});
  st[v].insert({u, v, w});
  upd(u), upd(v);
}
void cut(unsigned u, unsigned v) {
  rUpd(u), rUpd(v);
  if (u > v) swap(u, v);
  unsigned w = G[u][v];
  st[u].erase({u, v, w});
  st[v].erase({u, v, w});
  upd(u), upd(v);
}
bool chk(const Edge& x, const Edge& y) {
  return x.u == y.u || x.u == y.v || x.v == y.u || x.v == y.v;
}
bool chk(const Edge& x, const Edge& y, const Edge& z) {
  set<unsigned> st;
  st.insert(x.u), st.insert(x.v);
  st.insert(y.u), st.insert(y.v);
  st.insert(z.u), st.insert(z.v);
  return 3 == st.size();
}
unsigned ask() {
  vector<Edge> t;
  unsigned cnt = 0;
  for (auto it : tot) {
    t.push_back(it);
    if (6 == ++cnt) break;
  }
  unsigned ans = t[0].w + t[1].w + (chk(t[0], t[1], t[2]) ? t[3].w : t[2].w);
  for (unsigned i = 0; i < t.size(); ++i) {
    for (unsigned j = i + 1; j < t.size(); ++j) {
      if (!chk(t[i], t[j])) ans = min(ans, t[i].w + t[j].w);
    }
  }
  return ans;
}
signed main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  while (m--) {
    unsigned u, v, w;
    cin >> u >> v >> w;
    link(u, v, w);
  }
  cout << ask() << '\n';
  cin >> q;
  while (q--) {
    unsigned opt, u, v, w;
    cin >> opt >> u >> v;
    if (opt) {
      cin >> w;
      link(u, v, w);
    } else {
      cut(u, v);
    }
    cout << ask() << '\n';
  }
  return 0;
}
