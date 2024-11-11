#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
double fRand(double fMin, double fMax) {
  double f = (double)rand() / RAND_MAX;
  return fMin + f * (fMax - fMin);
}
template <class T>
T min(T a, T b, T c) {
  return min(a, min(b, c));
}
template <class T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
const double EPS = 1e-9;
struct pt {
  double x, y;
  bool operator==(pt p) { return abs(x - p.x) < EPS && abs(y - p.y) < EPS; }
  pt operator+(pt p) { return {x + p.x, y + p.y}; }
  pt operator-(pt p) { return {x - p.x, y - p.y}; }
  pt operator*(double k) { return {x * k, y * k}; }
  pt operator/(double k) { return {x / k, y / k}; }
  double operator*(pt p) { return x * p.y - y * p.x; }
  double operator%(pt p) { return x * p.x + y * p.y; }
  friend istream &operator>>(istream &is, pt &p) {
    is >> p.x >> p.y;
    return is;
  }
  friend ostream &operator<<(ostream &os, pt &p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
  }
};
struct Edge {
  int u, v;
  double w;
};
double mag(pt v) { return hypot(v.x, v.y); }
double dist(pt a, pt b) { return mag(b - a); }
double orient(pt a, pt b, pt c) { return (b - a) * (c - a); }
int sign(double x) { return (x > EPS) - (x < -EPS); }
bool onSegment(pt a, pt b, pt p) {
  return (sign(orient(a, b, p)) == 0 && (a - p) % (b - p) < 0);
}
bool properInter(pt a, pt b, pt c, pt d, pt &out) {
  double oa = orient(c, d, a), ob = orient(c, d, b);
  double oc = orient(a, b, c), od = orient(a, b, d);
  if (sign(oa) * sign(ob) < 0 && sign(oc) * sign(od) < 0) {
    out = (a * ob - b * oa) / (ob - oa);
    return true;
  }
  return false;
}
vector<pt> inter(pt a, pt b, pt c, pt d) {
  pt out;
  if (properInter(a, b, c, d, out)) return {out};
  vector<pt> res;
  if (onSegment(c, d, a)) res.push_back(a);
  if (onSegment(c, d, b)) res.push_back(b);
  if (onSegment(a, b, c)) res.push_back(c);
  if (onSegment(a, b, d)) res.push_back(d);
  return res;
}
bool cmpProj(pt a, pt b, pt p, pt q) {
  pt v = b - a;
  return v % p < v % q;
}
const int MAXN = 105;
const double INF = 1e9;
double shortestPath(vector<Edge> &e, int s, int t) {
  int n = max(s, t) + 1;
  for (int i = (0); i <= ((int)e.size() - 1); ++i)
    n = max(n, max(e[i].u, e[i].v) + 1);
  vector<vector<int> > g(n, vector<int>());
  for (int i = (0); i <= ((int)e.size() - 1); ++i) {
    g[e[i].u].push_back(i);
    g[e[i].v].push_back(i);
  }
  vector<double> d(n, INF);
  d[s] = 0;
  vector<bool> avail(n, true);
  priority_queue<pair<double, int>, vector<pair<double, int> >,
                 greater<pair<double, int> > >
      pq;
  pq.push(make_pair(d[s], s));
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    avail[u] = false;
    for (int i : g[u]) {
      int v = e[i].u + e[i].v - u;
      double w = e[i].w;
      if (avail[v] && d[v] > d[u] + w) {
        d[v] = d[u] + w;
        pq.push(make_pair(d[v], v));
      }
    }
  }
  return d[t];
}
pt a, b, po[MAXN];
int n;
vector<Edge> e;
int main() {
  cout << setprecision(50);
  cin >> a >> b;
  cin >> n;
  for (int i = (0); i <= (n - 1); ++i) cin >> po[i];
  int id = n;
  for (int i = (0); i <= (n - 1); ++i) {
    vector<pt> p = inter(a, b, po[i], po[(i + 1) % n]);
    if ((int)p.size() == 1) {
      bool dup = false;
      for (int j = (n); j <= (id - 1); ++j)
        if (po[j] == p[0]) dup = true;
      if (dup) continue;
      po[id] = p[0];
      e.push_back({i, id, dist(po[id], po[i])});
      e.push_back({(i + 1) % n, id, dist(po[id], po[(i + 1) % n])});
      ++id;
    }
  }
  if (id == n) {
    cout << dist(a, b);
    return 0;
  }
  for (int i = (0); i <= (n - 1); ++i)
    e.push_back({i, (i + 1) % n, dist(po[(i + 1) % n], po[i])});
  e.push_back({n, n + 1, 2 * dist(po[n], po[n + 1])});
  if (cmpProj(a, b, po[n], po[n + 1])) {
    e.push_back({n, n + 2, dist(a, po[n])});
    e.push_back({n + 1, n + 3, dist(b, po[n + 1])});
  } else {
    e.push_back({n, n + 3, dist(b, po[n])});
    e.push_back({n + 1, n + 2, dist(a, po[n + 1])});
  }
  cout << shortestPath(e, n + 2, n + 3);
  return 0;
}
