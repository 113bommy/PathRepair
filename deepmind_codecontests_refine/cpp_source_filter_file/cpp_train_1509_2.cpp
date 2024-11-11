#include <bits/stdc++.h>
using namespace std;
template <class G, class I, class F>
bool dijkstra(G &g, const I &start, const F &f) {
  typedef decltype(g[start].d) T;
  set<pair<T, I>> s;
  s.insert(make_pair(0, start));
  g[start].d = 0;
  while (!s.empty()) {
    I a = s.begin()->second;
    s.erase(s.begin());
    if (f(a)) return 1;
    T da = g[a].d;
    g.forEachEdge(a, [&](const typename G::E &e) {
      auto &n = g[e.b];
      T db = da + e.c;
      if (db < n.d) {
        s.erase(make_pair(n.d, e.b));
        n.d = db;
        s.insert(make_pair(n.d, e.b));
      }
    });
  }
  return 0;
}
template <class T>
T sgn(T x) {
  return x < 0 ? -1 : 0 < x;
}
using namespace std;
const int MAXN = 2000;
int n, m;
int s[2];
struct graph {
  struct E {
    int b, c;
  };
  struct N {
    int p;
    vector<E> ls;
    long long d;
    int o[2];
  };
  N &operator[](int id) { return t[id]; }
  template <class F>
  void forEachEdge(int a, const F &f) {
    for (E &e : t[a].ls) f(e);
  }
  void input() {
    cin >> n >> m;
    cin >> s[0] >> s[1];
    for (int i = 1; i <= n; ++i) cin >> t[i].p;
    while (m--) {
      int a, b, c;
      cin >> a >> b >> c;
      t[a].ls.push_back(E{b, c});
      t[b].ls.push_back(E{a, c});
    }
  }
  N t[MAXN + 1];
} g;
map<int, vector<int>> ni[2];
vector<vector<int>> vi[2];
long long memo[MAXN][MAXN][2];
long long f(int a, int b, bool t) {
  long long &r = memo[a][b][t];
  if (r < 63ll << 8 * 7) return r;
  bool u = 0;
  long long s = 0;
  for (int i : vi[t][a]) {
    if (g[i].o[!t] >= b) {
      u = 1;
      s += g[i].p;
    }
  }
  ++a;
  if (a == vi[t].size()) return r = s;
  long long mx = f(a, b, t);
  if (u) mx = max(mx, -f(b, a, !t));
  return r = s + mx;
}
int main() {
  ios::sync_with_stdio(0);
  memset(memo, 63, sizeof memo);
  g.input();
  for (int k = 0; k < 2; ++k) {
    for (int i = 1; i <= n; ++i) g[i].d = 1ll << 60;
    dijkstra(g, s[k], [](int) { return 0; });
    for (int i = 1; i <= n; ++i) ni[k][g[i].d].push_back(i);
    int i = 0;
    for (auto &e : ni[k]) {
      for (int a : e.second) g[a].o[k] = i;
      vi[k].push_back(e.second);
      ++i;
    }
  }
  cout << (string[]){"Cry", "Flowers", "Break a heart"}[sgn(f(0, 0, 0)) + 1]
       << endl;
  return 0;
}
