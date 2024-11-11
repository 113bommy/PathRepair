#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10, MAXM = 2e6 + 10;
const int INF = INT_MAX, SINF = 0x3f3f3f3f;
const long long llINF = LLONG_MAX;
const int MOD = 1e9 + 7, mod = 998244353;
int n;
long long ksm(long long x, long long v) {
  long long ans = 1;
  while (v) {
    if (v & 1) (ans *= x) %= mod;
    (x *= x) %= mod;
    v >>= 1;
  }
  return ans;
}
vector<int> v[MAXN];
long long num[MAXN], inv[MAXN];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int k;
    scanf("%d", &k);
    for (int j = 1; j <= k; j++) {
      int tmp;
      scanf("%d", &tmp);
      v[i].push_back(tmp);
      num[tmp]++;
    }
  }
  for (int i = 1; i <= n; i++) inv[i] = ksm(((int)v[i].size()), mod - 2);
  long long ans = 0, p = ksm(n, mod - 2);
  for (int i = 1; i <= n; i++)
    for (auto j : v[i]) ans = (ans + num[j] * inv[i]) % mod;
  (ans *= p * p % mod) %= mod;
  printf("%lld", ans);
  return 0;
}
