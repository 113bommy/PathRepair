#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFLL = 1e18;
const int MOD = 998244353;
const int MAXN = 5e5 + 5;
long long dp[MAXN][32];
long long suf[MAXN][32];
vector<tuple<int, int, int>> conditions;
int n, m, k;
void mnze(int& a, int b) { a = min(a, b); }
void mnze(long long& a, long long b) { a = min(a, b); }
void mod(long long& a) { a = (a % MOD + MOD) % MOD; }
long long solve(int j) {
  vector<int> v0(n, INF);
  vector<int> v1(n, 0);
  for (auto& [l, r, x] : conditions) {
    if (x >> j & 1) {
      v1[r]++;
      if (l) v1[l - 1]--;
    } else
      mnze(v0[l], r);
  }
  int mn = n, cnt = 0;
  dp[n][j] = 1;
  suf[n][j] = 1;
  for (int i = n - 1; i > (int)-1; i--) {
    cnt += v1[i];
    if (cnt > 0)
      dp[i][j] = 0;
    else
      dp[i][j] = suf[i + 1][j] - suf[mn + 1][j];
    mod(dp[i][j]);
    suf[i][j] = suf[i + 1][j] + dp[i][j];
    mod(suf[i][j]);
    mnze(mn, v0[i]);
  }
  return suf[0][j] - suf[mn + 1][j];
}
int main() {
  scanf("%d", &n), scanf("%d", &k), scanf("%d", &m);
  for (int i = 0; i < (int)m; i++) {
    int l, r, x;
    scanf("%d", &l), scanf("%d", &r), scanf("%d", &x);
    conditions.push_back({l - 1, r - 1, x});
  }
  long long ans = 1;
  for (int i = 0; i < (int)k; i++) {
    ans *= solve(i);
    mod(ans);
  }
  printf("%lld\n", ans);
  return 0;
}
