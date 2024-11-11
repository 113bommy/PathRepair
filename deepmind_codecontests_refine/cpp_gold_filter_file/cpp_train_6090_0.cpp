#include <bits/stdc++.h>
using namespace std;
const int R = 100000;
const double eps = 1e-7;
int n;
int st1[2211111], st2[2211111], stn1, stn2;
int st[2211111], stn;
long long x3(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
  return (c.first - a.first) * 1ll * (b.second - a.second) -
         (c.second - a.second) * 1ll * (b.first - a.first);
}
struct pt {
  double x, y;
  pt() {}
  pt(double xx, double yy) : x(xx), y(yy) {}
};
struct line {
  double a, b, c;
  line() {}
  line(double aa, double bb, double cc) : a(aa), b(bb), c(cc) {}
};
inline line serper(pt p1, pt p2) {
  return line(2 * (p2.x - p1.x), 2 * (p2.y - p1.y),
              p1.x * p1.x + p1.y * p1.y - p2.x * p2.x - p2.y * p2.y);
}
inline double dist(pt p1, pt p2) {
  double dx = p1.x - p2.x;
  double dy = p1.y - p2.y;
  return sqrt(dx * dx + dy * dy);
}
inline pt intersect(line l1, line l2) {
  return pt((l1.b * l2.c - l1.c * l2.b) / (l1.a * l2.b - l1.b * l2.a),
            (l1.a * l2.c - l1.c * l2.a) / (l1.b * l2.a - l1.a * l2.b));
}
inline double getR(double x1, double y1, double x2, double y2, double x3,
                   double y3) {
  pt A = pt(x1, y1);
  pt B = pt(x2, y2);
  pt C = pt(x3, y3);
  line AB = serper(A, B);
  line BC = serper(C, B);
  pt O = intersect(AB, BC);
  double R = dist(A, O);
  assert(abs(dist(B, O) - R) < eps);
  assert(abs(dist(C, O) - R) < eps);
  return R;
}
int main() {
  cin >> n;
  vector<pair<int, int> > e;
  for (int i = 0; i < n; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    int xx = x - z;
    if (xx >= 0) {
      e.push_back(make_pair(xx, y));
    } else {
      int l = y - (-xx);
      int r = y + (-xx);
      l = max(0, l);
      r = min(r, R);
      e.push_back(make_pair(0, l));
      e.push_back(make_pair(0, r));
    }
    xx = x + z;
    if (xx <= R) {
      e.push_back(make_pair(xx, y));
    } else {
      int l = y - (xx - R);
      int r = y + (xx - R);
      l = max(0, l);
      r = min(r, R);
      e.push_back(make_pair(R, l));
      e.push_back(make_pair(R, r));
    }
    int yy = y - z;
    if (yy >= 0) {
      e.push_back(make_pair(x, yy));
    } else {
      int l = x - (-yy);
      int r = x + (-yy);
      l = max(0, l);
      r = min(r, R);
      e.push_back(make_pair(l, 0));
      e.push_back(make_pair(r, 0));
    }
    yy = y + z;
    if (yy <= R) {
      e.push_back(make_pair(x, yy));
    } else {
      int l = x - (yy - R);
      int r = x + (yy - R);
      l = max(0, l);
      r = min(r, R);
      e.push_back(make_pair(l, R));
      e.push_back(make_pair(r, R));
    }
  }
  sort(e.begin(), e.end());
  for (int i = 0; i < e.size(); i++) {
    while (stn1 > 1 && x3(e[st1[stn1 - 2]], e[st1[stn1 - 1]], e[i]) <= 0)
      stn1--;
    while (stn2 > 1 && x3(e[st2[stn2 - 2]], e[st2[stn2 - 1]], e[i]) >= 0)
      stn2--;
    st1[stn1++] = i;
    st2[stn2++] = i;
  }
  stn = 0;
  for (int i = 0; i < stn1; i++) st[stn++] = st1[i];
  for (int i = stn2 - 2; i > 0; i--) st[stn++] = st2[i];
  st[stn] = st[0];
  st[stn + 1] = st[1];
  pair<int, int> A, B, C;
  double ans = -1;
  for (int i = 0; i < stn; i++) {
    double s =
        getR(e[st[i]].first, e[st[i]].second, e[st[i + 1]].first,
             e[st[i + 1]].second, e[st[i + 2]].first, e[st[i + 2]].second);
    if (s > ans) {
      ans = s;
      A = e[st[i]];
      B = e[st[i + 1]];
      C = e[st[i + 2]];
    }
  }
  cout << A.first << " " << A.second << endl;
  cout << B.first << " " << B.second << endl;
  cout << C.first << " " << C.second << endl;
  return 0;
}
