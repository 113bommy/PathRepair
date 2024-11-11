#include <bits/stdc++.h>
int MOD = int(1e9) + 7;
inline int add(int a, int b) {
  return (a + b >= MOD) ? (a + b - MOD) : (a + b);
}
inline void inc(int &a, int b) { a = add(a, b); }
inline int sub(int a, int b) { return (a - b < 0) ? (a - b + MOD) : (a - b); }
inline void dec(int &a, int b) { a = sub(a, b); }
inline int mul(int a, int b) { return (a * 1ll * b) % MOD; }
using namespace std;
const int N = 345678;
const long double PI = acosl(-1), EPS = 1e-16;
long double ang[2 * N];
long long f(int from, int to) {
  return 1LL * (to - from) * (to - from - 1) / 2;
}
int main() {
  int n, c, d;
  scanf("%d %d %d", &n, &c, &d);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    ang[i] = atan2l(y - d, x - c);
  }
  sort(ang, ang + n);
  for (int i = n; i < 2 * n; i++) ang[i] = ang[i - n] + 2 * PI;
  long long ans = 1LL * n * (n - 1) * (n - 2) / 6;
  int from = 0, to = 0;
  for (int i = 0; i < n; i++) {
    while (ang[from] - ang[i] < PI - EPS) from++;
    while (ang[to + 1] - ang[i] < PI + EPS) to++;
    ans += f(from, to + 1) - f(i, to);
  }
  printf("%lld\n", ans);
  return 0;
}
