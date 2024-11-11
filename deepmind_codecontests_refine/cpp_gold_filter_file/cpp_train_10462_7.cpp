#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const double INF = DBL_MAX;
bool iszero(const double a) { return fabs(a) <= eps; }
double sqr(const double a) { return a * a; }
int sgn(const double a) {
  if (a < -eps) return -1;
  return (a > eps);
}
int cmp(const double a, const double b) { return sgn(a - b); }
int inint() {
  int t;
  scanf("%d", &t);
  return t;
}
int sgn(long long a) { return a > 0 ? 1 : (a < 0 ? -1 : 0); }
long long a, b, c, l;
long long solve1() {
  long long res = 0;
  for (long long i = 2; i <= l + 2; i++) {
    res += ((i * (i - 1)) >> 1);
  }
  return res;
}
long long solve2(long long a, long long b, long long c, long long l) {
  if (b + c > a) return 0;
  long long res = min(a - b - c, l) + 2;
  return (res * (res - 1)) >> 1;
}
void solve() {
  scanf("%lld%lld%lld%lld", &a, &b, &c, &l);
  long long ans = solve1();
  for (int i = 0; i <= l; i++) {
    ans -= solve2(a + i, b, c, l - i);
    ans -= solve2(b + i, a, c, l - i);
    ans -= solve2(c + i, b, a, l - i);
  }
  printf("%lld\n", ans);
}
int main() {
  solve();
  return 0;
}
