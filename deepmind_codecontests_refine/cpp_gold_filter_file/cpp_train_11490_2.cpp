#include <bits/stdc++.h>
using namespace std;
void chkmax(long long &x, long long y) { x = x > y ? x : y; }
void chkmin(long long &x, long long y) { x = x < y ? x : y; }
const long long maxn = 2e5 + 50, inf = 1e15;
inline long long read() {
  char c = getchar();
  long long ans = 0, f = 0;
  for (; c < '0' || c > '9'; c = getchar()) f |= c == '-';
  for (; c >= '0' && c <= '9'; c = getchar()) (ans *= 10) += c - '0';
  return f ? -ans : ans;
}
long long n;
long long sum[maxn];
long long f[maxn], h[maxn];
int main() {
  n = read();
  for (long long i = 1; i <= n; i++) {
    sum[i] = read() + sum[i - 1];
    f[i] = h[i] = inf;
  }
  h[1] = sum[1];
  f[1] = 0;
  for (long long i = 2; i <= n; i++) {
    for (long long j = 0; j <= i - 1; j++) {
      if (sum[i] - sum[j] >= h[j] && f[j] + i - j - 1 <= f[i]) {
        f[i] = f[j] + i - j - 1;
        chkmin(h[i], sum[i] - sum[j]);
      }
    }
  }
  printf("%lld\n", f[n]);
  return 0;
}
