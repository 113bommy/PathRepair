#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const long long N = 5e5 + 100, OO = 1e9 + 7, M = 998244353, P = 499122177,
                T = 2e3, SQ = 280, lg = 64, lg2 = 32;
vector<long long> v[N];
long long ex[N], pw[N], ans;
void dfs(long long x, long long y) {
  ex[x] = 1;
  for (auto u : v[x]) {
    if (u == y) continue;
    dfs(u, x);
    long long cnt = (ex[u] + P * (M - ex[u] + 1) % M) % M;
    ex[x] = (ex[x] * cnt % M + M) % M;
  }
  ex[x] = (M - ex[x] + 1 + M) % M;
  ans = (ans + ex[x]) % M;
}
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long n;
  cin >> n;
  pw[0] = 1;
  for (long long i = 1; i <= n; i++) pw[i] = (pw[i - 1] * 2) % M;
  for (long long i = 0; i < n - 1; i++) {
    long long x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs(1, 0);
  cout << (pw[n] * ans) % M << endl;
  return 0;
}
