#include <bits/stdc++.h>
using namespace std;
struct Pt {
  long long x, y;
  Pt() {}
  Pt(long long _x, long long _y) : x(_x), y(_y) {}
  Pt operator+(const Pt &p) const { return Pt(x + p.x, y + p.y); }
  Pt operator-(const Pt &p) const { return Pt(x - p.x, y - p.y); }
  Pt operator*(long long c) const { return Pt(x * c, y * c); }
  Pt operator/(long long c) const { return Pt(x / c, y / c); }
  long long abs2() { return x * x + y * y; }
};
inline long long dist2(Pt a, Pt b) {
  long long dx = a.x - b.x;
  long long dy = a.y - b.y;
  return dx * dx + dy * dy;
}
inline long long cross(Pt a, Pt b) { return a.x * b.y - a.y * b.x; }
long long dot(Pt a, Pt b) { return a.x * b.x + a.y * b.y; }
inline int ccw(Pt p, Pt q, Pt r) {
  long long v = cross(p - q, p - r);
  if (v < 0) return -1;
  if (v > 0) return 1;
  return 0;
}
vector<Pt> convexHull(vector<Pt> &P) {
  sort(P.begin(), P.end(), [](const Pt &a, const Pt &b) {
    if (a.x != b.x) return a.x < b.x;
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
vector<long long> getdata(int n) {
  vector<Pt> A(n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld%lld", &A[i].x, &A[i].y);
  }
  A = convexHull(A);
  if (A.size() == 2) return {(A[1] - A[0]).abs2()};
  n = A.size();
  vector<long long> data;
  for (int i = 0; i < n; ++i) {
    int a = (i + n - 1) % n, b = (i + 1) % n;
    Pt aa = A[a] - A[i], bb = A[b] - A[i];
    long long ang = dot(aa, bb);
    data.push_back(aa.abs2());
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
const int MAXH = 3;
long long P[MAXH] = {998244353, 1000000007, 1000000009};
long long Q[MAXH] = {10000103, 10000079, 10000019};
const int MAXN = 200005;
long long pw[MAXH][MAXN];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  auto a = getdata(n);
  auto b = getdata(m);
  if (a.size() > b.size()) swap(a, b);
  if (a.size() == 1) {
    if (b.size() > 1) no();
    if (a[0] != b[0]) no();
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
  auto aa = a;
  aa.resize(2 * n);
  copy_n(aa.begin(), n, aa.begin() + n);
  long long val[3] = {};
  for (int i = 0; i < 2 * n; i += 2) {
    for (int h = 0; h < 3; ++h) {
      val[h] = (val[h] * Q[h] + aa[i]) % P[h];
      if (i >= n) val[h] = (val[h] - aa[i - n] % P[h] * pw[h][n]) % P[h];
      val[h] = (val[h] * Q[h] + aa[i + 1]) % P[h];
      if (i >= n) val[h] = (val[h] - aa[i + 1 - n] % P[h] * pw[h][n]) % P[h];
      if (val[h] < 0) val[h] += P[h];
    }
    if (i >= n) {
      has.insert({val[0], val[1], val[2]});
    }
  }
  memset(val, 0, sizeof(val));
  for (int i = 0; i < n; i += 2) {
    for (int h = 0; h < 3; ++h) {
      val[h] = (val[h] * Q[h] + b[i]) % P[h];
      val[h] = (val[h] * Q[h] + b[i + 1]) % P[h];
      if (val[h] < 0) val[h] += P[h];
    }
  }
  if (has.count({val[0], val[1], val[2]}))
    yes();
  else
    no();
}
