#include <bits/stdc++.h>
using namespace std;
const long double INF = 1e100;
const long double EPS = 1e-12;
bool eq(long double a, long double b) { return abs(a - b) < EPS; }
struct Pt {
  long double x, y;
  Pt() {}
  Pt(long double x, long double y) : x(x), y(y) {}
  Pt(const Pt &p) : x(p.x), y(p.y) {}
  Pt operator+(const Pt &p) const { return {x + p.x, y + p.y}; }
  Pt operator-(const Pt &p) const { return {x - p.x, y - p.y}; }
  Pt operator*(const long double c) const { return {x * c, y * c}; }
  Pt operator/(const long double c) const { return {x / c, y / c}; }
  bool operator==(const Pt &p) const { return eq(x, p.x) && eq(y, p.y); }
  bool operator!=(const Pt &p) const { return !(*this == p); }
  bool operator<(const Pt &p) const {
    return eq(x, p.x) ? y < p.y - EPS : x < p.x;
  }
  Pt rot() { return {-y, x}; }
  inline long double abs() const { return hypotl(x, y); }
};
inline long double dot(Pt p, Pt q) { return p.x * q.x + p.y * q.y; }
inline long double cross(Pt p, Pt q) { return p.x * q.y - p.y * q.x; }
inline long double dist2(Pt p, Pt q) { return dot(p - q, p - q); }
inline long double dist(Pt p, Pt q) {
  long double dx = p.x - q.x, dy = p.y - q.y;
  return sqrt(dx * dx + dy * dy);
}
int ccw(Pt p, Pt q, Pt r) {
  long double v = cross(p - q, p - r);
  if (v < -EPS) return -1;
  if (v > EPS) return 1;
  return 0;
}
vector<Pt> convexHull(vector<Pt> &P) {
  sort(P.begin(), P.end(), [](const Pt &a, const Pt &b) {
    if (!eq(a.x, b.x)) return a.x < b.x;
    return a.y < b.y;
  });
  vector<Pt> up, dn, hull;
  for (int i = 0; i < P.size(); ++i) {
    while (up.size() > 1 && ccw(up[up.size() - 2], up.back(), P[i]) >= 0)
      up.pop_back();
    while (dn.size() > 1 && ccw(dn[dn.size() - 2], dn.back(), P[i]) <= 0)
      dn.pop_back();
    up.push_back(P[i]);
    dn.push_back(P[i]);
  }
  hull = up;
  for (int i = (int)dn.size() - 2; i > 0; --i) hull.push_back(dn[i]);
  reverse(hull.begin(), hull.end());
  return hull;
}
vector<long double> getdata(int n) {
  vector<Pt> A(n);
  for (int i = 0; i < n; ++i) {
    scanf("%Lf%Lf", &A[i].x, &A[i].y);
  }
  A = convexHull(A);
  if (A.size() == 2) return {(A[1] - A[0]).abs()};
  n = A.size();
  vector<long double> data;
  for (int i = 0; i < n; ++i) {
    int a = (i + n - 1) % n, b = (i + 1) % n;
    Pt aa = A[a] - A[i], bb = A[b] - A[i];
    long double ang = acos(dot(aa, bb) / aa.abs() / bb.abs());
    data.push_back(aa.abs());
    data.push_back(ang);
  }
  return data;
}
void no() {
  printf("NO\n");
  exit(0);
}
void yes() {
  printf("YES\n");
  exit(0);
}
vector<long long> conv(vector<long double> a) {
  vector<long long> ret;
  for (int i = 0; i < a.size(); i += 2) {
    long long av = llround(a[i]);
    long long aw = llround(a[i + 1] * 1e8);
    ret.push_back(av);
    ret.push_back(aw);
  }
  auto add = ret;
  ret.insert(ret.end(), add.begin(), add.end());
  return ret;
}
const int MAXH = 3;
long long P[MAXH] = {998244353, 1000000007, 1000000009};
long long Q[MAXH] = {400009, 400031, 400033};
const int MAXN = 100005;
long long pw[MAXH][MAXN];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  auto a = getdata(n);
  auto b = getdata(m);
  if (a.size() > b.size()) swap(a, b);
  if (a.size() == 1) {
    if (b.size() > 1) no();
    if (!eq(a[0], b[0])) no();
    yes();
  }
  n = a.size();
  m = b.size();
  if (n != m) no();
  for (int h = 0; h < 3; ++h) {
    pw[h][0] = 1;
    for (int i = 1; i < MAXN; ++i) {
      pw[h][i] = pw[h][i - 1] * Q[h] % P[h];
    }
  }
  set<vector<long long>> has;
  auto aa = conv(a);
  long long val[3] = {};
  for (int i = 0; i < 2 * n; i += 2) {
    for (int h = 0; h < 3; ++h) {
      val[h] = (val[h] * Q[h] + aa[i]) % P[h];
      if (i >= n) val[h] = (val[h] - aa[i - n] * pw[h][n]) % P[h];
      val[h] = (val[h] * Q[h] + aa[i + 1]) % P[h];
      if (i >= n) val[h] = (val[h] - aa[i + 1 - n] * pw[h][n]) % P[h];
      if (val[h] < 0) val[h] += P[h];
    }
    if (i >= n - 2) {
      has.insert({val[0], val[1], val[2]});
    }
  }
  auto bb = conv(b);
  memset(val, 0, sizeof(val));
  for (int i = 0; i < n; i += 2) {
    for (int h = 0; h < 3; ++h) {
      val[h] = (val[h] * Q[h] + bb[i]) % P[h];
      val[h] = (val[h] * Q[h] + bb[i + 1]) % P[h];
    }
  }
  if (has.count({val[0], val[1], val[2]}))
    yes();
  else
    no();
}
