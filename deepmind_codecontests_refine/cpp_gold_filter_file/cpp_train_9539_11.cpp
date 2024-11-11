#include <bits/stdc++.h>
const int inf = 0x3f3f3f3f;
using namespace std;
const int N = 2e6 + 5;
const double eps = 1e-9;
long long mod = 1e9 + 7;
long long n, a, b, c, d, st, len;
struct node {
  long long tim, tp;
} p[N];
long long calc1(long long x) {
  if (x == -1) return 0;
  return x ? a : -b;
}
long long calc2(long long x) { return x ? c : -d; }
long long tail = 0;
long long mi = inf;
long long res = 0;
long long sum = 0;
int main() {
  scanf("%d", &n), scanf("%d", &a), scanf("%d", &b), scanf("%d", &c),
      scanf("%d", &d), scanf("%d", &st), scanf("%d", &len);
  p[0].tim = -1, p[0].tp = -1;
  p[n + 1].tim = 1e18;
  for (int i = 1; i <= n; i++) scanf("%d", &p[i].tim), scanf("%d", &p[i].tp);
  for (int i = 0; i <= n; i++) {
    sum += calc1(p[i].tp);
    if (sum < -st) {
      cout << -1;
      return 0;
    }
    while (p[tail + 1].tim <= p[i].tim + len) {
      ++tail, res += calc2(p[tail].tp);
      (mi) = (mi) <= (res) ? (mi) : (res);
    }
    if (sum + mi >= -st) {
      cout << p[i].tim + 1;
      return 0;
    }
    mi -= calc2(p[i + 1].tp);
    res -= calc2(p[i + 1].tp);
  }
  return 0;
}
