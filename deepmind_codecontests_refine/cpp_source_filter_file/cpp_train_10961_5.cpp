#include <bits/stdc++.h>
using namespace std;
const int maxn = 233333;
const int mod = 1000000007;
long long f[maxn], tot[maxn];
int lt;
int a[maxn];
long long fact[maxn], afct[maxn];
map<int, int> lucky;
void dfs(int u, int stp) {
  if (u) lucky[u] = ++lt;
  if (stp == 9) return;
  dfs(u * 10 + 4, stp + 1);
  dfs(u * 10 + 7, stp + 1);
  return;
}
long long Pow(long long u, int v) {
  long long w = 1LL;
  for (; v; v >>= 1) {
    if (v & 1) w = w * u % mod;
    u = u * u % mod;
  }
  return w;
}
long long C(int u, int v) {
  if (v > u) return 0LL;
  return fact[u] * afct[v] % mod * afct[u - v] % mod;
}
int main() {
  fact[0] = 1LL;
  for (int i = 1; i <= 100000; ++i)
    fact[i] = fact[i - 1] * (long long)(i) % mod;
  afct[0] = 1LL;
  for (int i = 1; i <= 100000; ++i)
    afct[i] = afct[i - 1] * Pow(i, mod - 2) % mod;
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  dfs(0, 1);
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (lucky.find(a[i]) == lucky.end())
      ++cnt;
    else
      ++tot[lucky[a[i]]];
  }
  f[0] = 1;
  for (int i = 1; i <= lt; ++i)
    for (int j = lt; j > 0; --j)
      f[j] = (f[j] + (long long)(f[j - 1]) * (long long)(tot[i]) % mod) % mod;
  long long ans = 0;
  for (int i = 0; i <= lt && i <= m; ++i)
    ans = (ans + (long long)(f[i]) * (long long)(C(cnt, m - i)) % mod) % mod;
  ans %= mod;
  ans += mod;
  ans %= mod;
  printf("%d\n", (int)ans);
  return 0;
}
