#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
pair<long long, long long> dp[1500][15][2];
bool vis[1500][15][2];
int bit[20], b;
long long cnt[1500];
long long pw10[20];
long long A, B, k;
pair<long long, long long> get(int sta, int d, bool st, bool flag) {
  if (cnt[sta] > k) return {0, 0};
  if (d == -1) return {1, 0};
  if (!flag && vis[sta][d][st]) return dp[sta][d][st];
  vis[sta][d][st] = true;
  long long res0 = 0, res1 = 0;
  int lim = flag ? bit[d] : 9;
  for (int i = 0; i <= lim; i++) {
    auto p = get((st || (i != 0) ? (sta | (1 << i)) : 0), d - 1, st || (i != 0),
                 flag && lim == i);
    res0 = (res0 + p.first) % mod;
    res1 = (res1 + i * pw10[d] % mod * p.first % mod + p.second) % mod;
  }
  if (!flag) dp[sta][d][st].first = res0, dp[sta][d][st].second = res1;
  return {res0, res1};
}
long long solve(long long x) {
  memset(vis, 0, sizeof(vis));
  b = 0;
  long long t = x;
  while (t > 0) {
    bit[b++] = (int)(t % 10);
    t /= 10;
  }
  return get(0, b - 1, false, true).second;
}
int main() {
  for (int i = 0; i < 1024; i++) {
    cnt[i] = 0;
    for (int j = 0; j < 10; j++) cnt[i] += ((i >> j) & 1);
  }
  pw10[0] = 1;
  for (int i = 1; i < 20; i++) pw10[i] = pw10[i - 1] * 10 % mod;
  cin >> A >> B >> k;
  cout << (solve(B) - solve(A - 1) + mod) % mod << endl;
}
