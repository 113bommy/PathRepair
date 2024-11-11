#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 2;
const long long sta = 1000, ed = 10000000000000LL;
struct mix {
  long long a[M][M];
} fir, one, zero;
long long qcheng(long long a, long long b, long long p) {
  long long ret = 0;
  while (b) {
    if (b % 2) ret = (ret + a) % p;
    a = (a + a) % p;
    b /= 2;
  }
  return ret;
}
mix mcheng(mix a, mix b, long long p) {
  mix ret = zero;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++)
        ret.a[i][j] = (ret.a[i][j] + qcheng(a.a[i][k], b.a[k][j], p)) % p;
  return ret;
}
mix mpow(mix a, long long b, long long p) {
  mix ret = one;
  while (b) {
    if (b % 2) ret = mcheng(ret, a, p);
    a = mcheng(a, a, p);
    b /= 2;
  }
  return ret;
}
long long get_fib(long long n, long long p) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  return mpow(fir, n - 1, p).a[0][0];
}
long long ans[N], tep[N], cnt, tt;
int main() {
  long long f;
  fir.a[0][0] = 1, fir.a[0][1] = 1;
  fir.a[1][0] = 1, fir.a[1][1] = 0;
  one.a[0][0] = 1, one.a[1][1] = 1;
  scanf("%lld", &f);
  f %= ed;
  for (int i = 0; i <= 1500; i++)
    if (get_fib(i, sta) == f % sta) ans[++cnt] = i;
  for (long long i = sta * 10, xh = 1500; i <= ed; i *= 10, xh *= 10) {
    tt = 0;
    long long now = f % i;
    for (int j = 1; j <= cnt; j++) {
      for (int k = 0; k <= 9; k++) {
        if (get_fib(ans[j] + (k * xh), i) == now) tep[++tt] = ans[j] + (k * xh);
      }
    }
    cnt = 0;
    for (int j = 1; j <= tt; j++) ans[++cnt] = tep[j];
  }
  if (cnt == 0)
    puts("-1");
  else {
    long long pt = ans[1];
    for (int i = 2; i <= cnt; i++) pt = min(pt, ans[i]);
    printf("%lld\n", pt);
  }
  return 0;
}
