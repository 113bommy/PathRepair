#include <bits/stdc++.h>
using namespace std;
template <typename T>
string tostr(const T& t) {
  ostringstream os;
  os << t;
  return os.str();
}
inline double getdist(double x1, double y1, double x2, double y2) {
  double d1 = x1 - x2;
  double d2 = y1 - y2;
  return sqrt(d1 * d1 + d2 * d2);
}
int N;
double ax, ay, bx, by, tx, ty;
vector<pair<double, double> > pts;
const double BIG = (double)200000000000000;
double memo[100010][3][3];
double go(int at, bool flag0, bool flag1) {
  if (at == N) return flag0 && flag1 ? 0 : BIG;
  double& ref = memo[at][flag0][flag1];
  if (ref > -1.0) return ref;
  ref = BIG;
  double cx = pts[at].first;
  double cy = pts[at].second;
  if (!flag0) {
    ref = min(ref, getdist(ax, ay, cx, cy) + getdist(cx, cy, tx, ty) +
                       go(at + 1, true, flag1));
  }
  if (!flag1) {
    ref = min(ref, getdist(bx, by, cx, cy) + getdist(cx, cy, tx, ty) +
                       go(at + 1, flag0, true));
  }
  ref = min(ref, getdist(cx, cy, tx, ty) * 2.0 + go(at + 1, flag0, flag1));
  return ref;
}
int main() {
  cin >> ax >> ay >> bx >> by >> tx >> ty;
  cin >> N;
  for (int i = (int)(0); i <= (int)(N - 1); ++i) {
    pair<double, double> p;
    cin >> p.first >> p.second;
    pts.push_back(p);
  }
  memset(memo, -1, sizeof memo);
  double ans = go(0, 0, 0);
  printf("%.25lf", ans);
byebye:;
  return 0;
}
