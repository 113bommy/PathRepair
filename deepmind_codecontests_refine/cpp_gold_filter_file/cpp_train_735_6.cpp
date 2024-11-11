#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int INF = 1 << 30;
const int mod = 1000000009;
int lowbit(int x) { return x & (-x); }
int fast_power(int a, int b) {
  int x;
  for (x = 1; b; b >>= 1) {
    if (b & 1) x = 1ll * x * a % mod;
    a = 1ll * a * a % mod;
  }
  return x % mod;
}
int is_not_prime[MAXN], prime[MAXN], d[MAXN], sum[MAXN];
int gcd(int x, int y) {
  if (!x) return y;
  return gcd(y % x, x);
}
int main() {
  int n;
  scanf("%d", &n);
  int cnt = 0;
  d[1] = 1;
  for (int i = 2; i <= 1e5; i++) {
    if (!is_not_prime[i]) {
      prime[++cnt] = i;
      d[i] = 2;
      sum[i] = 1;
    }
    for (int j = 1; j <= cnt; j++) {
      if (i * prime[j] > 1e5) break;
      is_not_prime[i * prime[j]] = 1;
      if (i % prime[j] == 0) {
        d[i * prime[j]] = d[i] / (sum[i] + 1) * (sum[i] + 2);
        sum[i * prime[j]] = sum[i] + 1;
        break;
      } else {
        d[i * prime[j]] = d[i] * 2;
        sum[i * prime[j]] = 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int A = gcd(b, c), B = gcd(a, c), C = gcd(a, b), x = gcd(a, gcd(b, c));
    long long ans =
        1ll * d[a] * d[b] * d[c] - 1ll * d[a] * d[A] * (d[A] - 1) / 2 -
        d[b] * d[B] * (d[B] - 1) / 2 - d[c] * d[C] * (d[C] - 1) / 2 +
        4ll * d[x] * (d[x] - 1) * (d[x] - 2) / 6 +
        1ll * d[x] * (d[x] - 1) *
            (d[A] - d[x] + d[B] - d[x] + d[C] - d[x] + 2) / 2 -
        1ll * (d[A] - d[x]) * (d[B] - d[x]) * (d[C] - d[x]);
    printf("%lld\n", ans);
  }
  return 0;
}
