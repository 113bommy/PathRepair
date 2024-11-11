#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long T = 0;
  int f = 0;
  char c = getchar();
  for (; c < '0' || c > '9'; c = getchar()) f |= c == '-';
  for (; c >= '0' && c <= '9'; c = getchar()) T = T * 10 + c - '0';
  return f ? -T : T;
}
const double eps = 1e-7;
const int maxn = 1e5 + 233;
const double pi = acos(-1.0);
struct Vector {
  int x, y;
  double z;
} P, Q, p[maxn * 2];
int n, a;
double ans;
inline double calc(Vector x, Vector y) {
  double wx = P.x, wy = P.y;
  if (x.x == y.x)
    wx = 2 * x.x - wx;
  else {
    double k = 1.0 * (y.y - x.y) / (y.x - x.x), b = x.y - k * x.x,
           kk = -1.0 / k;
    double d = 2 * abs((P.x - x.x) * (P.y - y.y) - (P.y - x.y) * (P.x - y.x)) /
               sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y));
    double tx = d / sqrt(kk * kk + 1), ty = tx * kk;
    if ((k * wx + b > wy) ^ (k * (wx + tx) + b > (wy + ty)))
      wx = wx + tx, wy = wy + ty;
    else
      wx = wx - tx, wy = wy - ty;
  }
  return sqrt((Q.x - wx) * (Q.x - wx) + (Q.y - wy) * (Q.y - wy));
}
bool cmp(Vector aa, Vector bb) { return aa.z < bb.z; }
int main() {
  n = read(), a = read();
  P.x = a;
  P.y = 0;
  Q.x = -a;
  Q.y = 0;
  ans = 2 * a;
  for (register int i = (1); i <= (n); ++i)
    p[i].x = read(), p[i].y = read(),
    p[i].z = fabs(sqrt(((p[i].x - a) * (p[i].x - a)) + ((p[i].y) * (p[i].y))) -
                  sqrt(((p[i].x + a) * (p[i].x + a)) + ((p[i].y) * (p[i].y))));
  sort(p + 1, p + 1 + n, cmp);
  n = min(n, 2000);
  for (register int i = (1); i <= (n); ++i)
    for (register int j = (i + 1); j <= (n); ++j)
      ans = min(ans, calc(p[i], p[j]));
  printf("%.10lf\n", ans);
  return 0;
}
