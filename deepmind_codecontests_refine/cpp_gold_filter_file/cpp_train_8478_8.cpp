#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
using namespace std;
const long long N = 2e5 + 100, OO = 1e9 + 7, T = 1e6 + 10, mod = 1e9 + 7,
                M = 10301, P = 6151, SQ = 280, lg = 70;
long long nxt[N], v[N], b[N], sz[N], res;
bool is[N], mark[N];
pair<long long, long long> go(long long x, long long y) {
  if (x == OO || mark[x]) return {OO, OO};
  if (y <= 0) return {x, 0};
  if (!is[x]) {
    is[x] = true;
    res++;
  }
  mark[x] = true;
  y -= sz[x];
  pair<long long, long long> p = go(nxt[x], y);
  sz[x] += p.second, nxt[x] = p.first;
  mark[x] = false;
  return {nxt[x], sz[x]};
}
int32_t main() {
  long long n, m;
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    cin >> nxt[i];
    sz[i] = 1;
  }
  for (long long i = 1; i <= m; i++) cin >> v[i];
  for (long long i = 1; i <= m; i++) {
    cin >> b[i];
    long long x = ((v[i] + res - 1) % n) + 1;
    res = 0;
    go(x, b[i]);
    cout << res << endl;
  }
  return 0;
}
