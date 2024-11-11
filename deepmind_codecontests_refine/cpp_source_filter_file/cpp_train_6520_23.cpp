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
  void add(int s, edge e) { adj[s].push_back(e); }
  void del(int s, edge e) {
    adj[s].erase(find((adj[s]).begin(), (adj[s]).end(), e));
  }
  int deg(int v) { return adj[v].size(); }
  vector<edge> &operator[](int t) { return adj[t]; }
};
struct crd {
  long double x, y, z;
  void read() { cin >> x >> y >> z; }
  void out() { cerr << "(" << x << ", " << y << ", " << z << ")"; }
  crd operator^(crd &w) {
    return (crd){y * w.z - w.y * z, z * w.x - w.z * x, x * w.y - y * w.x};
  }
  long double operator*(crd &w) { return x * w.x + y * w.y + z * w.z; }
  crd operator+(crd &w) { return (crd){x + w.x, y + w.y, z + w.z}; }
  crd operator-(crd &w) { return (crd){x - w.x, y - w.y, z - w.z}; }
  crd operator*(long double &w) { return (crd){x * w, y * w, z * w}; }
  long double len() { return sqrt(x * x + y * y + z * z); }
};
crd A, p, O, v;
long double R, r;
long double sphere(crd o, long double r) {
  o = o - A;
  crd plane = o ^ v;
  crd vert = v ^ plane;
  long double mindis = o * vert / vert.len();
  if (mindis > R || o * v < 0) return 1e300;
  o.out(), vert.out(), plane.out(), ({});
  long double dist = o.len();
  long double run =
      sqrt(sqr(dist) - sqr(mindis)) - sqrt(sqr(R + r) - sqr(mindis));
  return run / v.len();
}
int main() {
  ios_base::sync_with_stdio(false);
  long double ans = 1e300;
  A.read(), v.read();
  v.out(), cerr << endl;
  int n, m;
  cin >> R >> n;
  for (int i = 1; i <= n; ++i) {
    O.read();
    cin >> r >> m;
    ans = min(ans, sphere(O, r));
    for (; m--;) p.read(), ans = min(ans, sphere(O + p, 0));
  }
  cout << setprecision(15) << (ans > 1e200 ? -1 : ans) << endl;
  return 0;
}
