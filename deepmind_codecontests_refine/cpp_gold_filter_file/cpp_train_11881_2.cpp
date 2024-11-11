#include <bits/stdc++.h>
using namespace std;
namespace acm {
const int N = 510;
const int M = 6;
const double eps = 1e-8;
int dcmp(double x) {
  if (x < -eps)
    return -1;
  else
    return x > eps;
}
struct cpoint {
  double x, y;
  cpoint() {}
  cpoint(double x, double y) : x(x), y(y) {}
  cpoint operator+(const cpoint& u) const { return cpoint(x + u.x, y + u.y); }
  cpoint operator-(const cpoint& u) const { return cpoint(x - u.x, y - u.y); }
  cpoint operator*(const double& s) const { return cpoint(x * s, y * s); }
  cpoint operator/(const double& s) const { return cpoint(x / s, y / s); }
  double operator*(const cpoint& u) const { return x * u.y - y * u.x; }
  double operator^(const cpoint& u) const { return x * u.x + y * u.y; }
  bool operator==(const cpoint& u) const {
    return dcmp(x - u.x) == 0 && dcmp(y - u.y) == 0;
  }
  bool operator<(const cpoint& u) const {
    if (dcmp(x - u.x))
      return x < u.x;
    else
      return dcmp(y - u.y) < 0;
  }
  void get() { scanf("%lf%lf", &x, &y); }
};
struct poly {
  int n;
  cpoint cp[M];
  void get() {
    n = 4;
    for (int i = 0; i < (int)(n); ++i) cp[i].get();
  }
  bool check() {
    cp[n] = cp[0];
    double area = 0;
    for (int i = 0; i < (int)(n); ++i) area += cp[i] * cp[i + 1];
    if (dcmp(area) == 0) return false;
    if (area < 0) reverse(cp, cp + n);
    cp[n] = cp[0];
    return true;
  }
} ply[N];
int n;
pair<cpoint, cpoint> seg1[N * M], seg2[N * M];
cpoint lin[N * M];
cpoint getline(cpoint u, cpoint v) {
  double k;
  if (dcmp(u.x - v.x) == 0)
    k = 1e200;
  else
    k = (u.y - v.y) / (u.x - v.x);
  return cpoint(k, u.y - k * u.x);
}
bool getcut(cpoint lin, cpoint a, cpoint b, cpoint& cp) {
  double t = lin.x * (a.x - b.x) - (a.y - b.y);
  if (dcmp(t) == 0) return false;
  double x = ((a * b) - (a.x - b.x) * lin.y) / t;
  cp = cpoint(x, lin.x * x + lin.y);
  return true;
}
double calc(pair<cpoint, cpoint> seg[], int m) {
  int ln = 0;
  double ans = 0;
  cpoint A, B, cp;
  for (int i = 0; i < (int)(m); ++i)
    lin[ln++] = getline(seg[i].first, seg[i].second);
  sort(lin, lin + ln);
  ln = unique(lin, lin + ln) - lin;
  for (int i = 0; i < (int)(ln); ++i) {
    vector<pair<double, int> > mark;
    for (int j = 0; j < (int)(n); ++j) {
      bool touch = 0;
      for (int k = 0; k < (int)(ply[j].n); ++k)
        if (lin[i] == getline(ply[j].cp[k], ply[j].cp[k + 1])) {
          touch = 1;
          break;
        }
      if (touch) continue;
      vector<cpoint> cut;
      for (int k = 0; k < (int)(ply[j].n); ++k) {
        A = ply[j].cp[k];
        B = ply[j].cp[k + 1];
        if (!getcut(lin[i], A, B, cp)) continue;
        if (dcmp((A - cp) ^ (B - cp)) <= 0) cut.push_back(cp);
      }
      sort(cut.begin(), cut.end());
      cut.resize(unique(cut.begin(), cut.end()) - cut.begin());
      if (((int)cut.size()) == 2) {
        mark.push_back(make_pair(cut[0].x, 0));
        mark.push_back(make_pair(cut[1].x, 1));
      }
    }
    for (int j = 0; j < (int)(m); ++j)
      if (lin[i] == getline(seg[j].first, seg[j].second)) {
        double mn = min(seg[j].first.x, seg[j].second.x);
        double mx = max(seg[j].first.x, seg[j].second.x);
        mark.push_back(make_pair(mn, 2));
        mark.push_back(make_pair(mx, 3));
      }
    sort(mark.begin(), mark.end());
    double last = mark[0].first;
    int in = 0, ct = 0;
    for (int j = 0; j < (int)(((int)mark.size())); ++j) {
      double y0 = lin[i].x * last + lin[i].y;
      double y1 = lin[i].x * mark[j].first + lin[i].y;
      if (!in && ct) ans += (y0 + y1) * (mark[j].first - last) / 2;
      last = mark[j].first;
      if (mark[j].second == 0) in++;
      if (mark[j].second == 1) in--;
      if (mark[j].second == 2) ct++;
      if (mark[j].second == 3) ct--;
    }
  }
  return ans;
}
double PolyUnion(poly ply[], int n) {
  int n1, n2, tot = n;
  n1 = n2 = 0;
  for (int i = 0; i < (int)(n); ++i)
    for (int j = 0; j < (int)(ply[i].n); ++j) {
      cpoint A = ply[i].cp[j];
      cpoint B = ply[i].cp[j + 1];
      if (dcmp(A.x - B.x) > 0) seg1[n1++] = make_pair(A, B);
      if (dcmp(A.x - B.x) < 0) seg2[n2++] = make_pair(A, B);
    }
  return calc(seg1, n1) - calc(seg2, n2);
}
void solve() {
  for (int i = 0; i < (int)(n); ++i) {
    ply[i].get();
    if (!ply[i].check()) --n, --i;
  }
  double area = PolyUnion(ply, n);
  double tot = 0;
  for (int i = 0; i < (int)(n); ++i)
    for (int j = 0; j < (int)(ply[i].n); ++j)
      tot += ply[i].cp[j] * ply[i].cp[j + 1];
  tot /= 2;
  printf("%.10f\n", tot / area);
}
void icpc() {
  while (~scanf("%d", &n)) {
    solve();
  }
}
}  // namespace acm
int main() {
  acm::icpc();
  return 0;
}
