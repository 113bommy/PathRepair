#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7fffffff;
const double eps = 1e-18;
const double pi = acos(-1.0);
inline int read() {
  int x = 0, f = 1;
  char ch;
  ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = 0;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch & 15);
    ch = getchar();
  }
  if (f)
    return x;
  else
    return -x;
}
const int N = 1e5 + 10;
double fabs(double a) {
  if (a < 0) return -a;
  return a;
}
struct point {
  double x, y;
} P[N];
int n, maxi;
bool f1, f2;
bool cheak(double r) {
  double L = -1e15, R = 1e15;
  for (int i = 1; i <= n; i++) {
    if (P[i].y > 2 * r) return 0;
    double c = sqrt(2.0 * r * P[i].y - P[i].y * P[i].y);
    L = max(L, P[i].x - c);
    R = min(R, P[i].x + c);
  }
  return L - R <= eps;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    P[i].x = read(), P[i].y = read();
    if (P[i].y < 0)
      f1 = 1;
    else
      f2 = 1;
    P[i].y = abs(P[i].y);
  }
  if (f1 && &f2) {
    printf("-1\n");
    return 0;
  }
  double l = 0, r = 1e14;
  for (int i = 1; i <= 500; i++) {
    double mid = (l + r) / 2.0;
    if (cheak(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.15lf\n", r);
  return 0;
}
