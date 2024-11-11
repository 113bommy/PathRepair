#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const int INF = 2e9;
const long long INFLL = 1e18;
const int MAX_N = 1000000;
long long gcd(long long x, long long y) { return (x == 0) ? y : gcd(y % x, x); }
int N;
long long v[MAX_N + 1];
vector<int> gp[MAX_N + 1];
int p[MAX_N + 1];
long long SUM;
vector<pair<long long, long long> > vt;
vector<pair<long long, long long> > vt2;
long long sum[MAX_N + 1];
int cnt[MAX_N + 1];
void dfs(int x) {
  sum[x] = v[x];
  for (int i : gp[x]) {
    dfs(i);
    sum[x] += sum[i];
  }
  long long S = gcd(sum[x], SUM);
  if (SUM / S <= N) cnt[(SUM / S)]++;
}
long long ans;
map<long long, int> mp;
long long dp[MAX_N + 1];
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%lld", &v[i]);
    SUM += v[i];
  }
  for (long long l = 1; l * l <= SUM; l++) {
    if (SUM % l == 0) {
      vt.push_back({l, 0});
      if (l * l != SUM) {
        vt.push_back({SUM / l, 0});
      }
    }
  }
  sort(vt.begin(), vt.end());
  for (int i = 2; i <= N; i++) {
    scanf("%d", &p[i]);
    gp[p[i]].push_back(i);
  }
  dfs(1);
  for (int i = 1; i <= N; i++) {
    for (int j = i * 2; j <= N; j += i) {
      cnt[j] += cnt[i];
    }
  }
  for (int i = N; i >= 1; i--) {
    if (cnt[i] == i) {
      dp[i] = 1;
      for (int j = i * 2; j <= N; j += i) {
        dp[i] = (dp[i] + dp[j]) % MOD;
      }
    }
  }
  printf("%lld", dp[1]);
  return 0;
}
