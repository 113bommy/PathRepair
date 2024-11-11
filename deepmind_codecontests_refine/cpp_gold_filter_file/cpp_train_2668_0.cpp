#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const long long ooo = 9223372036854775807ll;
const int _cnt = 1000 * 1000 + 7;
const int _p = 1000 * 1000 * 1000 + 7;
const int N = 1000105;
const double PI = acos(-1.0);
const double eps = 1e-6;
int o(int x) { return x % _p; }
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
void file_put() {
  freopen("filename.in", "r", stdin);
  freopen("filename.out", "w", stdout);
}
long long f, t, t0, a1, t1, p1, a2, t2, p2, _f, _t, x, ans = ooo;
int main() {
  scanf("%I64d%I64d%I64d", &f, &t, &t0);
  scanf("%I64d%I64d%I64d", &a1, &t1, &p1);
  scanf("%I64d%I64d%I64d", &a2, &t2, &p2);
  if (t1 > t2) swap(t1, t2), swap(a1, a2), swap(p1, p2);
  for (long long i = 0; i * a1 < f; i++) {
    _f = f - i * a1, _t = t - i * a1 * t1;
    if (_f * ((t2) < (t0) ? (t2) : (t0)) > _t) continue;
    x = (_f * t0 <= _t || t0 <= t2)
            ? 0
            : ceil(ceil((_f * t0 - _t) * 1.0 / (t0 - t2)) / a2);
    ans = ((ans) < (i * p1 + x * p2) ? (ans) : (i * p1 + x * p2));
  }
  if (f * t1 <= t)
    ans = ((ans) < ((long long)ceil(f * 1.0 / a1) * p1)
               ? (ans)
               : ((long long)ceil(f * 1.0 / a1) * p1));
  printf("%I64d\n", ans == ooo ? ans = -1 : ans);
  return 0;
}
