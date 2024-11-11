#include <bits/stdc++.h>
using namespace std;
const long double e = 1e-2;
int k;
long double R, r, l;
long double x, y, xl, yl, xr, yr;
long double a, b, c, S;
long double COS[12], SIN[12];
bool check(long double x, long double y) {
  long double s = 0;
  for (int i = 0; i < 12; i += 2)
    s = max(s, ((x + COS[i]) * (x + COS[i])) + ((y + SIN[i]) * (y + SIN[i])));
  return s <= l + e;
}
bool end(long double x, long double y) {
  long double s = 1e+60;
  for (int i = 0; i < 12; i += 2)
    s = min(s, ((x + COS[i]) * (x + COS[i])) + ((y + SIN[i]) * (y + SIN[i])));
  return s > S;
}
int main() {
  R = 1;
  r = sqrt(((R) * (R)) - ((0.5) * (0.5)));
  for (int i = 0; i < 12; i++) {
    COS[i] = cos(((i * 30) * M_PI / 180));
    SIN[i] = sin(((i * 30) * M_PI / 180));
  }
  scanf("%d", &k);
  l = k;
  l *= l;
  S = k + 3;
  S *= S;
  x = (k + 2) / 3 * 3 * COS[2];
  y = (k + 2) / 3 * 3 * SIN[2];
  xl = xr = x;
  yl = yr = y;
  long long ans = 0;
  do {
    long double s;
    s = y * xr - x * yr;
    while (s > 0 && abs(s) > e && !check(xr, yr)) {
      xr += 2 * r * COS[5];
      yr += 2 * r * SIN[5];
      s = y * xr - x * yr;
    }
    while (check(xr, yr)) {
      xr -= 2 * r * COS[5];
      yr -= 2 * r * SIN[5];
    }
    s = y * xl - x * yl;
    while (s < 0 && abs(s) > e && !check(xl, yl)) {
      xl += 2 * r * COS[11];
      yl += 2 * r * SIN[11];
      s = y * xl - x * yl;
    }
    while (check(xl, yl)) {
      xl -= 2 * r * COS[11];
      yl -= 2 * r * SIN[11];
    }
    long double L = sqrt(((xl - xr) * (xl - xr)) + ((yl - yr) * (yl - yr)));
    ans += max((long long)((L + r) / (2 * r)) - 1, 0LL);
    xl += 2 * r * COS[7];
    yl += 2 * r * SIN[7];
    xr += 2 * r * COS[9];
    yr += 2 * r * SIN[9];
  } while (!end(xr, yr) || !end(xl, yl));
  cout << ans << endl;
  return 0;
}
