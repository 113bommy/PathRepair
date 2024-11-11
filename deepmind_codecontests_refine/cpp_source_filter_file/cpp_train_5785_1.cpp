#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, m, K, s;
int log2s;
struct Node {
  int x, y;
} a[2003];
bool cmp(Node a, Node b) {
  if (a.x == b.x)
    return a.y < b.y;
  else
    return a.x < b.x;
}
long long ksm(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod, b >>= 1;
  }
  return res;
}
long long fact[200001], invfact[200001];
void init(int n) {
  fact[0] = 1;
  for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % mod;
  invfact[n] = ksm(fact[n], mod - 2);
  for (int i = n - 1; i >= 0; i--) invfact[i] = invfact[i + 1] * (i + 1) % mod;
  return;
}
long long C(int n, int m) {
  if (m == 0 || m == n) return 1;
  if (n < m) return 0;
  return fact[n] * invfact[n - m] % mod * invfact[m] % mod;
}
long long calc(Node p, Node q) { return C(q.x - p.x + q.y - p.y, q.x - p.x); }
long long dp[2003][21];
int main() {
  scanf("%d%d%d%d", &n, &m, &K, &s);
  init(n + m);
  for (int i = 1; i <= K; i++) scanf("%d%d", &a[i].x, &a[i].y);
  sort(a + 1, a + K + 1, cmp);
  if (a[1].x != 1 || a[1].y != 1) s *= 2, K++, a[K].x = 1, a[K].y = 1;
  if (a[K].x != n || a[K].y != m)
    K++, a[K].x = n, a[K].y = m;
  else
    s = (s + 1) / 2;
  log2s = log2(s) + 1;
  sort(a + 1, a + K + 1, cmp);
  dp[1][0] = 1;
  for (int i = 2; i <= K; i++) {
    dp[i][1] = calc(a[1], a[i]);
    for (int j = 2; j <= log2s; j++) {
      for (int k = 1; k < i; k++) {
        if (a[k].y <= a[i].y && a[k].x <= a[i].x) {
          dp[i][j] = ((dp[i][j] + dp[k][j - 1] * calc(a[k], a[i]) % mod) % mod -
                      dp[k][j] * calc(a[k], a[i]) % mod + mod) %
                     mod;
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= log2s; i++) {
    s = (s + 1) / 2;
    ans = (ans + (dp[K][i] - dp[K][i + 1] + mod) * s % mod) % mod;
  }
  ans = ans * ksm(calc(a[1], a[K]), mod - 2) % mod;
  printf("%lld", ans);
}
