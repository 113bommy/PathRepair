#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int mod = 1e9 + 7;
long long pw(long long x, long long y) {
  long long ans = 1;
  while (y) {
    if (y & 1) {
      ans = ans * x;
      ans = ans % mod;
    }
    x = x * x;
    x = x % mod;
    y = y >> 1;
  }
  return ans;
}
long long fact[N];
long long md[N];
map<long long, long long> mp;
long long prm[N];
long long vis[N];
long long mark[N];
void init() {
  fact[0] = 1;
  for (long long i = 1; i < N; ++i) {
    fact[i] = fact[i - 1] * i;
    fact[i] = fact[i] % mod;
    md[i] = pw(fact[i], mod - 2);
  }
  memset(mark, 0, sizeof(mark));
  mark[0] = mark[1] = 1;
  for (int i = 2; i * i < N; ++i) {
    if (mark[i]) continue;
    for (int j = i * i; j < N; j = j + i) mark[j] = 1;
  }
}
void solve(long long x) {
  for (int i = 2; i * i <= x; ++i) {
    if (x % i) continue;
    if (mark[i]) continue;
    while (x % i == 0) {
      ++mp[i];
      x = x / i;
    }
  }
  if (x > 1) ++mp[x];
}
long long C(long long n, long long m) {
  if (m == 0) return 1LL;
  return (fact[n] * md[n - m] % mod) * (md[m] % mod);
}
int main(void) {
  long long n, x;
  init();
  mp.clear();
  scanf("%lld", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &x);
    solve(x);
  }
  long long ans = 1;
  for (auto it : mp) {
    x = it.second;
    ans = ans * C(x + n - 1, n - 1);
    ans = ans % mod;
  }
  printf("%lld\n", ans);
}
