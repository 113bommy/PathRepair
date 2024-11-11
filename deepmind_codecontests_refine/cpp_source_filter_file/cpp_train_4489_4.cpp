#include <bits/stdc++.h>
static long long gcd(long long x, long long y) {
  return y == 0 ? x : gcd(y, x % y);
}
static long long pwm(long long x, long long n, long long m) {
  long long r = 1;
  while (n) {
    if (n & 1) r = r * x % m;
    x = x * x % m;
    n >>= 1;
  }
  return r;
}
int n;
std::vector<int> g[1 << 18];
std::vector<long long> cnt;
long long ans, s[2];
void dfs(int x, int p = 0, int deep = 0) {
  cnt[x] = 1;
  for (int e : g[x]) {
    if (e == p) continue;
    dfs(e, x, deep ^ 1);
    cnt[x] += cnt[e];
  }
  ++s[deep];
  if (p) {
    ans += cnt[x] * (n - cnt[x]);
  }
}
int solve() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  cnt.resize(n + 1);
  dfs(1);
  ans = (ans + s[0] + s[1]) / 2;
  printf("%lld\n", ans);
  return 0;
}
int main(int argc, char* argv[]) {
  ::std::ios::sync_with_stdio(false);
  ::std::cin.tie(0);
  ::std::cout.tie(0);
  solve();
}
