#include <bits/stdc++.h>
using namespace std;
long long fpm(long long b, long long e, long long m) {
  long long t = 1;
  for (; e; e >>= 1, b = b * b % m) e & 1 ? t = t * b % m : 0;
  return t;
}
template <class T>
inline bool chkmin(T &a, T b) {
  return a > b ? a = b, true : false;
}
template <class T>
inline bool chkmax(T &a, T b) {
  return a < b ? a = b, true : false;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class edge>
struct Graph {
  vector<vector<edge> > adj;
  Graph(int n) {
    adj.clear();
    adj.resize(n + 5);
  }
  Graph() { adj.clear(); }
  void resize(int n) { adj.resize(n + 5); }
  void adde(int s, edge e) { adj[s].push_back(e); }
  int deg(int v) { return adj[v].size(); }
  vector<edge> &operator[](int t) { return adj[t]; }
};
const int maxm = 55000, maxn = 220;
struct edge {
  int x, y, g, s;
};
edge E[maxm];
int f[maxn], g[maxn];
void mkrt(int x) {
  int y = f[x], t, w = g[x];
  f[x] = x, g[x] = 0x3F3F3F3F;
  for (; x != y;) t = g[y], g[y] = w, w = t, t = f[y], f[y] = x, x = y, y = t;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  long long ans = (long long)2e18, G, S;
  cin >> n >> m >> G >> S;
  for (int i = 1, x, y, g, s; i <= m; ++i)
    cin >> x >> y >> g >> s, E[i] = (edge){x, y, g, s};
  sort(E + 1, E + m + 1, [](edge a, edge b) -> bool { return a.s < b.s; });
  multiset<int> eg;
  for (int i = 1; i <= n; ++i) f[i] = i, g[i] = 0x3F3F3F3F;
  for (int i = 1; i <= m; ++i) {
    edge &e = E[i];
    if (e.x == e.y) continue;
    mkrt(e.x), mkrt(e.y);
    if (f[e.x] == e.x) {
      f[e.x] = e.y;
      g[e.x] = e.g;
      eg.insert(e.g);
    } else {
      pair<int, int> w = make_pair(0, 0);
      for (int x = e.x; x != e.y; x = f[x]) chkmax(w, make_pair(g[x], x));
      if (w.first > e.g && w.second) {
        f[w.second] = w.second, g[w.second] = 0x3F3F3F3F,
        eg.erase(eg.find(w.first));
        mkrt(e.x), f[e.x] = e.y, g[e.x] = e.g;
        eg.insert(e.g);
      }
    }
    if ((int)((eg).size()) == n - 1) ans = min(ans, *--eg.end() * G + e.s * S);
  }
  if ((int)((eg).size()) != n - 1) return cout << -1 << endl, 0;
  cout << ans << endl;
  return 0;
}
