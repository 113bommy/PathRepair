#include <bits/stdc++.h>
using namespace std;
const int M = 2020;
const double pi = acos(-1), eps = 1e-7;
int n;
long long ans;
struct Point {
  int x, y;
  double sl;
  void in() { scanf("%d%d", &x, &y); }
  Point() {}
  Point(int a, int b) : x(a), y(b) {}
  double Get(int a, int b) { return atan2(y - b, x - a); }
  double operator<(const Point &a) const { return sl < a.sl; }
} P[M];
double ang[M];
int tot;
long long Calc(long long a) { return ((a * (a - 1)) >> 1); }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) P[i].in();
  for (int i = 1, k; i <= n; i++) {
    tot = 0;
    k = 1;
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      ang[++tot] = P[j].Get(P[i].x, P[i].y);
    }
    sort(ang + 1, ang + tot + 1);
    for (int j = 1; j <= tot && ang[j] <= eps; j++) {
      while (k <= tot && ang[k] < ang[j] + pi) ++k;
      ans += 1ll * (k - j - 1) * (k - j - 2) * (tot - k + j) *
             (tot - k + j - 1) / 2;
    }
  }
  printf("%I64d\n", (ans >> 1));
  return 0;
}
