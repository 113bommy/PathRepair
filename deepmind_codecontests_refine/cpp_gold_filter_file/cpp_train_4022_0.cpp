#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const long long ooo = 9223372036854775807ll;
const int _cnt = 1000 * 1000 + 7;
const int _p = 1000 * 1000 * 1000 + 7;
const int N = 300005;
const double PI = acos(-1.0);
const double eps = 1e-9;
int o(int x) { return x % _p; }
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
void file_put() {
  freopen("filename.in", "r", stdin);
  freopen("filename.out", "w", stdout);
}
int n, m;
long long a, d, t[N], step, r = 0, ans = 0, num, p, q, need;
int main() {
  scanf("%d%d%I64d%I64d", &n, &m, &a, &d);
  for (int i = (1); i <= (m); ++i) scanf("%I64d", &t[i]);
  t[++m] = ooo;
  num = d / a + 1;
  for (int i = (1); i <= (m); ++i) {
    if (t[i] <= r) continue;
    p = ((t[i] / a) < (n) ? (t[i] / a) : (n)),
    q = ((r / a) < (n) ? (r / a) : (n)), need = p - q;
    ans += ceil(need * 1.0 / num);
    if (need) r = (p - (need - 1) % num) * a + d;
    if (r < t[i]) r = t[i] + d, ans++;
  }
  printf("%I64d\n", ans - 1);
  return 0;
}
