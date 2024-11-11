#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int maxn = 1000005;
vector<int> v[maxn];
int cnt[maxn];
int k[maxn];
long long qp(long long x, long long p) {
  long long res = 1;
  while (p) {
    if (p & 1) res = res * x % mod;
    x = x * x % mod;
    p >>= 1;
  }
  return res % mod;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &k[i]);
    v[i].resize(k[i] + 1);
    for (int j = 1; j <= k[i]; j++) {
      scanf("%d", &v[i][j]);
      cnt[v[i][j]]++;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    long long tmp = 0;
    for (int j = 1; j <= k[i]; j++) {
      tmp += 1ll * cnt[v[i][j]];
    }
    ans = (ans + tmp * qp(k[i], mod - 2) % mod) % mod;
  }
  ans = ans * qp(1ll * n * n, mod - 2) % mod;
  printf("%lld\n", ans);
  return 0;
}
