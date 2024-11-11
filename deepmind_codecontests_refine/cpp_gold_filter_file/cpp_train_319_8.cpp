#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5;
inline long long read() {
  register long long s = 0;
  register bool neg = 0;
  register char c = getchar();
  for (; c < '0' || c > '9'; c = getchar()) neg |= (c == '-');
  for (; c >= '0' && c <= '9'; s = s * 10 + (c ^ 48), c = getchar())
    ;
  return (neg ? -s : s);
}
long long a, s[N + 10], sum[N + 10], cnt[2];
inline long long f(long long n) {
  long long res = 0;
  while (n) res++, n -= n & -n;
  return res;
}
signed main() {
  a = read();
  long long x;
  for (long long i = 1; i <= a; i++) {
    x = read();
    s[i] = f(x);
    sum[i] = s[i] + sum[i - 1];
  }
  long long ans = 0;
  cnt[0] = 1;
  for (long long i = 1; i <= a; i++) {
    ans += cnt[sum[i] & 1];
    long long mx = 0;
    for (long long j = i, k = 0; j >= 1 && k <= 128; j--) {
      mx = max(mx, s[j]);
      k += s[j];
      if (k < mx * 2 && (sum[j - 1] & 1) == (sum[i] & 1)) ans--;
    }
    cnt[sum[i] & 1]++;
  }
  printf("%lld", ans);
  return 0;
}
