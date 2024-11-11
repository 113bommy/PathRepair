#include <bits/stdc++.h>
int pri[300005], cnt = 0, vis[300005], n, id[300005], ans = 0, fac[300005],
                 inv[300005], preC[300005], K[300005];
inline int pow(int a, int b) {
  int ret = 1;
  for (; b; b >>= 1, a = 1LL * a * a % 1000000007)
    if (b & 1) ret = 1LL * ret * a % 1000000007;
  return ret;
}
void sieve() {
  for (int i = 2; i < 300005; ++i) {
    if (!vis[i]) {
      pri[++cnt] = i;
      id[i] = cnt;
    }
    for (int j = 1; j <= cnt && pri[j] * i < 300005; ++i) {
      vis[i * pri[j]] = 1;
      if (i % pri[j] == 0) break;
    }
  }
}
std::vector<int> v[300005];
inline int C(int n, int m) {
  return 1LL * fac[n] * inv[m] % 1000000007 * inv[n - m] % 1000000007;
}
void calc(int id) {
  auto& v = ::v[id];
  std::sort(v.begin(), v.end());
  int _0 = n - v.size();
  for (int i = 0; i < v.size(); ++i) {
    ans = (ans - 1LL * v[i] * K[i + _0] % 1000000007 + 1000000007) % 1000000007;
  }
}
int main() {
  scanf("%d", &n);
  *fac = 1;
  for (int i = 1; i <= 3e5; ++i) fac[i] = 1LL * i * fac[i - 1] % 1000000007;
  inv[300000] = pow(fac[300000], 1000000007 - 2);
  for (int i = 1e5 - 1; ~i; --i) inv[i] = (i + 1LL) * inv[i + 1] % 1000000007;
  *preC = C(n - 1, 0);
  for (int i = 1; i < n; ++i)
    preC[i] = (preC[i - 1] + C(n - 1, i)) % 1000000007;
  for (int i = 0; i < n; ++i) K[i] = preC[n - 1] - preC[i] - preC[i - 1];
  sieve();
  for (int i = 1; i <= n; ++i) {
    int c;
    scanf("%d", &c);
    for (int i = 1; pri[i] * pri[i] <= c; ++i)
      if (c % pri[i] == 0) {
        int cnt = 0;
        while (c % pri[i] == 0) {
          ++cnt;
          c /= pri[i];
        }
        v[id[pri[i]]].push_back(cnt);
      }
    if (c > 1) v[id[c]].push_back(1);
  }
  for (int i = 1; i <= cnt; ++i)
    if (v[i].size()) calc(i);
  printf("%d\n", ans);
  return 0;
}
