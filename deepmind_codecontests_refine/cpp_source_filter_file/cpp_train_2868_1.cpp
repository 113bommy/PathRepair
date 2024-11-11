#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
bool lp(long long y) { return y % 400 == 0 || (y % 100 != 0 && y % 4 == 0); }
int md[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dm(long long y, long long m) {
  int r = 0;
  for (int i = 1; i <= m; ++i) r += md[i] + (lp(y) && i == 2);
  return r;
}
int fm(long long y, long long t) {
  int m = 1;
  while (dm(y, m) < t) ++m;
  return m;
}
long long dy(long long y) { return 365 * y + y / 4 - y / 100 + y / 400; }
long long fy(long long t) {
  long long l = 0, r = 1e12, m;
  while (l + 1 < r) {
    m = (l + r) >> 1;
    if (dy(m) >= t)
      r = m;
    else
      l = m;
  }
  return r;
}
int n;
long long s, m, h, w, d, M, t;
long long ts, tmd, th, tw, td, tM, ty;
void inc_M() {
  if (++tM > 12) {
    tM = 1;
    ++ty;
  }
}
void inc_d() {
  if (++td > md[tM] + (lp(ty) && tM == 2)) {
    td = 1;
    inc_M();
  }
  if (++tw > 7) tw = 1;
  if (h == -1) th = 0;
  if (m == -1) tmd = 0;
  if (s == -1) ts = 0;
}
void inc_h() {
  if (++th > 24) {
    th = 0;
    inc_d();
  }
  if (m == -1) tmd = 0;
  if (s == -1) ts = 0;
}
void inc_m() {
  if (++tmd == 60) {
    tmd = 0;
    inc_h();
  }
  if (s == -1) ts = 0;
}
void inc_s() {
  if (++ts == 60) {
    ts = 0;
    inc_m();
  }
}
int main() {
  while (cin >> s >> m >> h >> w >> d >> M) {
    cin >> n;
    while (n--) {
      cin >> t;
      ts = t % 60;
      t /= 60;
      tmd = t % 60;
      t /= 60;
      th = t % 24;
      t /= 24;
      t += 719162 + 1;
      tw = t % 7;
      if (tw == 0) tw = 7;
      ty = fy(t);
      t -= dy(ty - 1);
      tM = fm(ty, t);
      t -= dm(ty, tM - 1);
      td = t;
      inc_s();
      while (s != -1 && ts != s) inc_s();
      while (m != -1 && tmd != m) inc_m();
      while (h != -1 && th != h) inc_h();
      if (d != -1 && w != -1)
        while ((td != d && tw != w) || (M != -1 && tM != M)) inc_d();
      else if (d != -1)
        while (td != d || (M != -1 && tM != M)) inc_d();
      else if (w != -1)
        while (tw != w || (M != -1 && tM != M)) inc_d();
      else
        while (M != -1 && tM != M) inc_d();
      t = td + dm(ty, tM - 1) + dy(ty - 1);
      t -= 719162 + 1;
      t *= 24;
      t += th;
      t *= 60;
      t += tmd;
      t *= 60;
      t += ts;
      cout << t << endl;
    }
  }
  return 0;
}
