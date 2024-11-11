#include <bits/stdc++.h>
using namespace std;
long long n, a, b, k;
char buf[100010];
long long qp(long long x, long long p) {
  long long ret = 1;
  while (p) {
    if (p & 1) ret = ret * x % 1000000009;
    x = x * x % 1000000009;
    p >>= 1;
  }
  return ret;
}
long long rev(long long x) { return qp(x, 1000000009 - 2); }
int main() {
  scanf("%lld%lld%lld%lld", &n, &a, &b, &k);
  scanf("%s", buf + 1);
  long long num = qp(a, n);
  long long q = b * rev(a) % 1000000009;
  long long qq = qp(q, k);
  long long tmp = (n + 1) / k;
  long long ans = 0;
  for (long long i = 1; i <= k; i++) {
    long long cur = num;
    if (qq != 1) {
      cur = cur * rev((qq - 1 + 1000000009) % 1000000009) % 1000000009;
      cur = cur * ((qp(qq, tmp) - 1 + 1000000009) % 1000000009) % 1000000009;
    } else {
      cur = num * tmp % 1000000009;
    }
    if (buf[i] == '-')
      ans = (ans - cur + 1000000009) % 1000000009;
    else
      ans = (ans + cur) % 1000000009;
    num = num * q % 1000000009;
  }
  printf("%lld\n", ans);
}
