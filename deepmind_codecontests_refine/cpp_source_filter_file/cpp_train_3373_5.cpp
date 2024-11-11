#include <bits/stdc++.h>
using namespace std;
long long fpm(long long b, long long e, long long m) {
  long long t = 1;
  for (; e; e >>= 1, b = b * b % m) e & 1 ? t = t * b % m : 0;
  return t;
}
template <class T>
inline bool chkmin(T &a, T b) {
  return a < b ? a = b, true : false;
}
template <class T>
inline bool chkmax(T &a, T b) {
  return a > b ? a = b, true : false;
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
  void adde(int s, edge e) { adj[s].push_back(e); }
  typename vector<edge>::iterator operator[](int t) { return adj[t].begin(); }
};
const double eps = 1e-8;
struct crd {
  double x, y, z;
};
crd V, P, Wx, Wy, Mx, My;
crd operator^(crd a, crd b) {
  return (crd){a.y * b.z - a.z * b.y, a.z * b.x - b.z * a.x,
               a.x * b.y - a.y * b.x};
}
crd operator*(crd a, double b) { return (crd){a.x * b, a.y * b}; }
crd operator+(crd a, crd b) { return (crd){a.x + b.x, a.y + b.y}; }
crd operator-(crd a, crd b) { return (crd){a.x - b.x, a.y - b.y}; }
bool operator<(crd a, crd b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }
int sgn(double x) { return x > -eps ? x > eps : -1; }
int intersect(pair<crd, crd> a, pair<crd, crd> b, int cmp, int if2) {
  crd ca = a.first ^ a.second, cb = b.first ^ b.second, cx = ca ^ cb;
  if (!sgn(cx.x) && !sgn(cx.y) && !sgn(cx.z)) {
    if (a.second < a.first) swap(a.first, a.second);
    if (b.second < b.first) swap(b.first, b.second);
    return a.second < b.first || b.second < a.first ? 0 : if2;
  }
  if (!(sgn(((b.first - a.first) ^ (a.second - a.first)).z) *
            sgn(((a.second - a.first) ^ (b.second - a.first)).z) >=
        cmp))
    return 0;
  return sgn(((a.first - b.first) ^ (b.second - b.first)).z) *
             sgn(((b.second - b.first) ^ (a.second - b.first)).z) >=
         cmp;
}
crd reflect(pair<crd, crd> L, crd P) {
  crd x = L.second - L.first, y = P - L.first;
  double mid = atan2(x.y, x.x);
  double dff = atan2(y.y, y.x);
  double now = mid * 2 - dff, dist = hypot(y.x, y.y);
  return L.first + (crd){cos(now), sin(now)} * dist;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> V.x >> V.y >> P.x >> P.y >> Wx.x >> Wx.y >> Wy.x >> Wy.y >> Mx.x >>
      Mx.y >> My.x >> My.y;
  V.z = P.z = Wx.z = Wy.z = Mx.z = My.z = 1;
  pair<crd, crd> W = make_pair(Wx, Wy), M = make_pair(Mx, My);
  if (!intersect(W, make_pair(V, P), 0, 1) &&
      !intersect(M, make_pair(V, P), 0, 0))
    return cout << "YES" << endl, cerr << "case1" << endl, 0;
  crd Rp = reflect(M, P);
  if (intersect(M, make_pair(V, Rp), 0, 0)) {
    crd x = (V ^ Rp) ^ (Mx ^ My);
    x.y /= x.z, x.x /= x.z, x.z = 1;
    if (!intersect(W, make_pair(V, x), 0, 1) &&
        !intersect(W, make_pair(x, P), 0, 1))
      return cout << "YES" << endl, cerr << "case2" << endl, 0;
  }
  cout << "NO" << endl;
  return 0;
}
