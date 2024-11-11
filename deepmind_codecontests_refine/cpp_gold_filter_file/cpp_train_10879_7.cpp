#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 1000000007;
long long dp[3][maxn];
pair<int, int> pp[maxn];
map<int, int> mp1, mp2;
long long fastpow(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) {
      res = res * x % mod;
    }
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}
int main() {
  int n, k;
  long long l;
  scanf("%d%I64d%d", &n, &l, &k);
  long long p = l / n, q = l % n;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &pp[i].first);
    pp[i].second = i;
    ++mp1[pp[i].first];
    if (i < q) {
      ++mp2[pp[i].first];
    }
  }
  long long ans = 0;
  sort(pp, pp + n);
  long long *now = dp[0], *nxt = dp[1];
  dp[0][0] = dp[1][0] = 1;
  for (int i = 0; i < n; ++i) {
    if (i && pp[i].first == pp[i - 1].first) continue;
    for (int j = 1; j <= min(p + 1, (long long)k); ++j) {
      nxt[j] = nxt[j - 1] * mp1[pp[i].first] % mod;
      if (p >= j) {
        ans = (ans + (p - j + 1) % mod * nxt[j] % mod) % mod;
      }
      if (p >= j - 1 && pp[i].second < q) {
        ans = (ans + nxt[j - 1] * mp2[pp[i].first] % mod) % mod;
      }
      nxt[j] = (nxt[j] + now[j]) % mod;
    }
    swap(now, nxt);
  }
  printf("%I64d\n", ans);
  return 0;
}
