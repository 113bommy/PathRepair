#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 100 * 1000 + 23, MAXK = 10 + 3;
long long n, k, a, dp[MAXN][MAXK], jav, seg[MAXK][MAXN << 2], m;
long long ans(long long, long long, long long, long long, long long);
void add(long long, long long, long long);
int32_t main() {
  cin >> n >> k;
  m = (1 << ((long long)ceil(log2(n))));
  for (long long i = 0; i < n; i++) {
    cin >> a;
    for (long long j = 0; j <= k; j++)
      dp[i + 1][j + 1] = ((j == 0) ? 1 : ans(1, j, a, 0, m));
    for (long long j = 0; j < k; j++) add(i + 1, j + 1, a);
    jav += dp[i + 1][k + 1];
  }
  cout << jav;
  return 0;
}
long long ans(long long z, long long l, long long v, long long st,
              long long ed) {
  if (st >= v) return 0;
  if (ed == v) return seg[l][z];
  long long ret = 0;
  long long mid = ((st + ed) >> 1);
  ret += ans(z << 1, l, min(mid, v), st, mid);
  ret += ans((z << 1) + 1, l, v, mid, ed);
  return ret;
}
void add(long long q, long long l, long long v) {
  long long f = v + m - 1;
  while (f) {
    seg[l][f] += dp[q][l];
    f >>= 1;
  }
}
