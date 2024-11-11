#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;
const long long LINF = 1ll * INF * INF;
int n, c, a[100000], b[100000];
int gao(long long x) {
  long long ret = 0;
  for (int i = 0; i < n; i++) {
    ret += a[i] * x / b[i];
    double c = a[i] * double(x);
    if (ret >= INF || c >= LINF) return INF;
  }
  return ret;
}
int main() {
  scanf("%d%d", &n, &c);
  for (int i = 0; i < n; i++) scanf("%d%d", a + i, b + i);
  if ((c -= n) < 0) return puts("0"), 0;
  if (!c && count(a, a + n, 0) == n) return puts("-1"), 0;
  long long lo = 1, hi = LINF;
  while (lo < hi) {
    long long x = (lo + hi) / 2;
    if (gao(x) < c)
      lo = x + 1;
    else
      hi = x;
  }
  long long LO = 1, HI = LINF;
  while (LO < HI) {
    long long x = (LO + HI + 1) / 2;
    if (gao(x) > c)
      HI = x - 1;
    else
      LO = x;
  }
  printf("%I64d\n", max(0ll, LO - lo + 1));
}
