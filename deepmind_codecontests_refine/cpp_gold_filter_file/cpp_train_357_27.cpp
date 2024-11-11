#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return (b != 0 ? gcd(b, a % b) : a); }
int lcm(int a, int b) { return (a / gcd(a, b) * b); }
int R[] = {1, -1, 0, 0, 1, -1, -1, 1};
int C[] = {0, 0, 1, -1, 1, -1, 1, -1};
int KR[] = {-2, -2, -1, 1, 2, 2, -1, 1};
int KC[] = {1, -1, 2, 2, 1, -1, -2, -2};
struct P {
  double x, y;
  P(double x = 0.0, double y = 0.0) {
    this->x = x;
    this->y = y;
  }
};
P mkv(P ae, P be) { return P(be.x - ae.x, be.y - ae.y); }
double dtp(P ae, P be) { return (ae.x * be.x + ae.y * be.y); }
double crp(P ae, P be) { return (ae.x * be.y - ae.y * be.x); }
double val(P ae) { return sqrt(dtp(ae, ae)); }
P vresize(P ae, double llen) {
  double v = val(ae);
  return P(ae.x * llen / v, ae.y * llen / v);
}
double ART(P ae, P be) { return crp(ae, be) / 2.0; }
P rot(P ae, double ang) {
  return P(ae.x * cos(ang) - ae.y * sin(ang),
           ae.y * cos(ang) + ae.x * sin(ang));
}
long long hpm, atkm, defm, hp;
long long check(long long atk, long long def) {
  long long rk, rm, mhp, r, zero = 0;
  rk = max(zero, atkm - def);
  rm = max(zero, atk - defm);
  mhp = hpm;
  if (rk == 0 && rm != 0)
    return 0;
  else if (rm == 0)
    return -1;
  else {
    if (mhp % rm == 0) {
      return max(zero, (mhp / rm) * rk - hp + 1);
    } else
      return max(zero, ((long long)(mhp / rm) + 1) * rk - hp + 1);
  }
}
int main() {
  long long b, c, d, h, m, n, p, x, y, i, j, k, l, q, r, t, cnt, sm, tmp, def,
      atk, vh, va, vd;
  scanf("%I64d %I64d %I64d", &hp, &atk, &def);
  scanf("%I64d %I64d %I64d", &hpm, &atkm, &defm);
  scanf("%I64d %I64d %I64d", &vh, &va, &vd);
  long long mx = 1e9;
  for (j = 0; j <= 200; j++) {
    for (k = 0; k <= 200; k++) {
      p = check(atk + j, def + k);
      if (p != -1) {
        if (mx > p * vh + j * va + k * vd) {
          tmp = p;
          sm = j;
          cnt = k;
        }
        mx = min(mx, p * vh + j * va + k * vd);
      }
    }
  }
  printf("%I64d\n", mx);
  return 0;
}
