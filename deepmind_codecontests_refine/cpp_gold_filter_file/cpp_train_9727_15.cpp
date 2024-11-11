#include <bits/stdc++.h>
using namespace std;
const long long NR = 1005;
long long mod;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
long long n, m, k;
bool flag;
long long ksm(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
long long cnt[NR], num[NR];
long long ans;
signed main() {
  n = read(), m = read(), k = read();
  if (n < m) {
    swap(n, m);
    flag = 1;
  }
  for (long long i = 1; i <= k; i++) {
    long long x = read(), y = read(), w = read();
    if (flag) swap(x, y);
    cnt[x]++;
    num[x] ^= (w == -1);
  }
  mod = read();
  if (m - n & 1) {
    puts("0");
    return 0;
  }
  for (long long i = 1; i <= n; i++) {
    if (cnt[i] == m) {
      if (!num[i]) {
        puts("0");
        return 0;
      }
      continue;
    }
    ans += m - cnt[i] - 1;
  }
  ans -= m - 1;
  printf("%lld\n", ksm(2ll, ans));
  return 0;
}
