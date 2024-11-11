#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long INF = 2e16;
const long long maxn = 1e6 + 5;
const double Pi = acos(-1.0);
double Exp = 1e-4;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
long long n, m, kk;
struct node {
  long long x;
  long long id;
} a[maxn];
long long tot = 0;
bool cmp(node a, node b) {
  if (a.x != b.x) return a.x < b.x;
  return a.id > b.id;
}
long long dp[265];
long long vis[8];
signed main() {
  n = read(), m = read(), kk = read();
  for (long long i = 1; i <= n; i++) {
    long long l = read(), r = read();
    tot++;
    a[tot].x = l, a[tot].id = i;
    tot++;
    a[tot].x = r + 1, a[tot].id = -i;
  }
  sort(a + 1, a + 1 + tot, cmp);
  for (long long i = 1; i < 256; i++) dp[i] = -INF;
  for (long long i = 1; i <= tot; i++) {
    long long k;
    long long len = 0;
    long long p = a[i].id;
    if (i != tot) {
      len = a[i + 1].x - a[i].x;
    }
    if (p > 0) {
      for (long long i = 0; i < 8; i++) {
        if (vis[i] == 0) {
          k = i;
          vis[i] = p;
          break;
        }
      }
      for (long long i = 255; i >= 0; i--) {
        if ((i >> k) & 1) {
          dp[i] = dp[i ^ (1 << k)] + len * __builtin_parity(i);
        } else {
          dp[i] = dp[i] + len * __builtin_parity(i);
        }
      }
    } else {
      for (long long i = 0; i < 8; i++) {
        if (vis[i] == -p) {
          k = i;
          vis[i] = 0;
          break;
        }
      }
      for (long long i = 0; i < 256; i++) {
        if ((i >> k) & 1) {
          dp[i] = -INF;
        } else {
          dp[i] = max(dp[i], dp[i ^ (1 << k)]) + len * __builtin_parity(i);
        }
      }
    }
  }
  printf("%lld\n", dp[0]);
  return 0;
}
