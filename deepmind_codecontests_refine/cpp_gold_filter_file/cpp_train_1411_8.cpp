#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  char ch = getchar();
  bool positive = 1;
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') positive = 0;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return positive ? x : -x;
}
inline char RC() {
  char c = getchar();
  while (c == ' ' || c == '\n') c = getchar();
  return c;
}
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline long long lcm(long long a, long long b, long long MOD) {
  return a / gcd(a, b) * b % MOD;
}
inline long long Sub(long long x, long long y, long long mod) {
  long long res = x - y;
  while (res < 0) res += mod;
  return res;
}
inline long long Add(long long x, long long y, long long mod) {
  long long res = x + y;
  while (res >= mod) res -= mod;
  return res;
}
inline long long POW_MOD(long long x, long long y, long long mod) {
  long long ret = 1;
  while (y > 0) {
    if (y & 1) ret = ret * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ret;
}
const int N = 20 + 1;
;
const int inf = 2100000000;
const long long INF = 1LL << 60;
const double PI = 3.14159265358;
double dp[1 << N], ans[N], p[N];
int countBit(int n) {
  n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
  n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
  n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
  n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
  n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
  return n;
}
int main() {
  int n, k, cnt = 0;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    if (p[i] >= 1e-7) cnt++;
  }
  dp[0] = 1.0;
  k = min(k, cnt);
  for (int s = 0; s < (1 << n); ++s) {
    double fm = 1.0;
    for (int i = 0; i < n; ++i) {
      if (s & (1 << i)) {
        fm -= p[i];
        if (countBit(s) == k) {
          ans[i] += dp[s];
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      if (!(s & (1 << i))) {
        dp[s | (1 << i)] += dp[s] * p[i] / fm;
      }
    }
  }
  for (int i = 0; i < n; ++i) printf("%.7f ", ans[i]);
  puts("");
  return 0;
}
