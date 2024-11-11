#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int N = 100010;
const int INF = 0x3f3f3f3f;
void MOD(long long &a) {
  if (a >= mod) a -= mod;
}
void MOD(long long &a, long long c) {
  if (a >= c) a -= c;
}
void ADD(long long &a, long long b) {
  a += b;
  MOD(a);
}
void ADD(long long &a, long long b, long long c) {
  a += b;
  MOD(a, c);
}
long long qpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b /= 2;
  }
  return ans;
}
long long qpow(long long a, long long b, long long c) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % c;
    a = a * a % c;
    b /= 2;
  }
  return ans;
}
int L, n, p, t;
int dp[N], g[N];
int main() {
  scanf("%d%d%d%d", &L, &n, &p, &t);
  g[0] = -t;
  for (int i = 1, j = 1; i <= n; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    g[i] = g[i - 1];
    dp[i] = dp[i - 1];
    for (j--; j <= i && t + g[j] <= r; j++) {
      if (dp[j] + (r - max(l, g[j] + t)) / p > dp[i] ||
          dp[j] + (r - max(l, g[j] + t)) / p == dp[i] &&
              (r - max(l, g[j] + t)) / p * p + max(l, g[j] + t) > g[i]) {
        dp[i] = dp[j] + (r - max(l, g[j] + t)) / p;
        g[i] = (r - max(l, g[j] + t)) / p * p + max(l, g[j] + t);
      }
    }
  }
  printf("%d\n", dp[n]);
}
