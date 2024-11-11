#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 1;
const long long MOD = 998244353;
int a[N], n, sz, cnt[N];
long long fac[N], dp[N][N], ans;
struct Node {
  int x, y;
  bool operator<(const Node& p) const { return x < p.x; }
} b[N];
long long ksm(long long a, long long x) {
  long long b = a, res = 1;
  for (; x; x >>= 1) {
    if (x & 1) res = (res * b) % MOD;
    b = (b * b) % MOD;
  }
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), cnt[a[i]]++;
  for (int i = 1; i < N; i++)
    if (cnt[i]) b[++sz] = (Node){i, cnt[i]};
  sort(b + 1, b + 1 + sz);
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % MOD;
  for (int i = 0; i <= n; i++) dp[i][0] = 1;
  for (int i = 1; i <= sz; i++) {
    for (int j = 1; j <= i; j++)
      dp[i][j] = (dp[i - 1][j - 1] * b[i].y + dp[i - 1][j]) % MOD;
  }
  for (int i = 1; i <= sz; i++)
    if (b[i].y > 1) {
      for (int j = i; j; j--) {
        ans = (ans + dp[i - 1][j - 1] * b[i].y * (b[i].y - 1) % MOD *
                         fac[n - j - 1] % MOD) %
              MOD;
      }
    }
  ans = ans * ksm(fac[n], MOD - 2) % MOD;
  printf("%lld", ans);
}
