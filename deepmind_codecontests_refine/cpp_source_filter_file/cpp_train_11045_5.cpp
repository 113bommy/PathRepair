#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &a) {
  T x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  a = x * f;
}
template <typename T, typename... Args>
void read(T &t, Args &...args) {
  read(t);
  read(args...);
}
const long long mod = 1e9 + 7;
long long n, k, a[100005], cnt = 0, dp[100005];
long long ksm(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
signed main() {
  read(n);
  for (long long i = 1; i <= n; i++) {
    long long x;
    read(x);
    if (x != -1) a[x]++;
  }
  long long res = 0;
  for (long long i = 1; i <= n; i++)
    if (a[i]) res = (res + ksm(2, a[i] - 1)) % mod;
  printf("%lld\n", (ksm(2, n - 1) - res - 1 + mod) % mod);
  return 0;
}
