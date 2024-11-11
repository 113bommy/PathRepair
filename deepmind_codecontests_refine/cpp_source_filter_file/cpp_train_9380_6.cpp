#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-13;
const long double PI = acos(-1);
const int INF = (int)2e9;
const long long INFF = (long long)2e18 + 7;
const int mod = (int)1e9 + 7;
const int MXN = (int)1e5 + 7;
struct Pt {
  long double x, y;
  Pt(){};
  Pt(long double _x, long double _y) { x = _x, y = _y; }
  void read() { scanf("%Lf %Lf", &x, &y); }
  long double dis() { return (x * x + y * y); }
  Pt operator-(const Pt &p2) { return Pt(x - p2.x, y - p2.y); }
  Pt operator+(const Pt &p2) { return Pt(x + p2.x, y + p2.y); }
  Pt operator*(const long double &p2) { return Pt(x * p2, y * p2); }
};
Pt a[MXN], b[MXN];
inline long double d(long double p, int pp) {
  Pt p1 = a[pp] * p + a[pp + 1] * (1 - p);
  Pt p2 = b[pp] * p + b[pp + 1] * (1 - p);
  return (p1 - p2).dis();
}
int main(void) {
  int n;
  scanf("%d", &n);
  long double d1, d2;
  scanf("%Lf %Lf", &d1, &d2);
  d1 *= d1;
  d2 *= d2;
  int ans = 0;
  for (int i = 1; i < n + 1; i++) a[i].read(), b[i].read();
  Pt p1 = a[1], p2 = b[1];
  bool gg = 0;
  for (int i = 1; i < n; i++) {
    long double ll = 0, rr = 1, mxn = INFF;
    for (int i = 0; i < 30; i++) {
      long double md = ll + (rr - ll) / 3;
      long double mmd = ll + (rr - ll) / 3 * 2;
      long double d1 = d(md, i);
      long double d2 = d(mmd, i);
      if (d1 < d2) {
        rr = mmd;
        mxn = min(mxn, d1);
      } else {
        ll = md;
        mxn = min(mxn, d2);
      }
    }
    if (mxn <= d1 && !gg) {
      gg = 1;
      ans++;
    }
    if ((a[i + 1] - b[i + 1]).dis() > d2) gg = 0;
  }
  printf("%d\n", ans);
  return 0;
}
