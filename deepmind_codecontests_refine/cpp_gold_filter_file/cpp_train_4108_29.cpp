#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 5;
int n;
long long cnt[N];
long long dp[N];
long long MaxPoint(long long i) {
  if (i >= N) return 0;
  if (dp[i] + 1) return dp[i];
  dp[i] = -1e18;
  return dp[i] = max(MaxPoint(i + 1), MaxPoint(i + 2) + i * cnt[i]);
}
int solve() {
  scanf("%d", &n);
  memset(dp, -1, sizeof dp);
  vector<long long> a(n);
  for (long long& x : a) scanf("%I64d", &x), cnt[x]++;
  printf("%I64d", MaxPoint(0));
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
}
