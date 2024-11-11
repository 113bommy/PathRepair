#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long inf = 1e17;
const int MAXM = 2e3 + 6;
const int MAXN = 2e2 + 4;
long long b[MAXM];
long long a[MAXM];
long long su[MAXM];
set<long long> s;
int n, k;
long long dp[MAXM][MAXM];
vector<int> v[MAXM];
long long solve(int idx, int prev) {
  if (idx == k) return 1;
  if (dp[idx][prev] != -1) return dp[idx][prev];
  long long ret = 0;
  if (prev == 0) {
    for (int i = 1; i <= n; i++) {
      ret += solve(idx + 1, i);
      if (ret >= 1000000007) ret %= 1000000007;
    }
  } else {
    for (int i = prev; i <= n; i += prev) {
      ret += solve(idx + 1, prev);
      if (ret >= 1000000007) ret %= 1000000007;
    }
  }
  return dp[idx][prev] = ret;
}
int main() {
  memset(dp, -1, sizeof(dp));
  int i, j;
  scanf("%d", &n);
  scanf("%d", &k);
  printf("%lld\n", solve(0, 0));
  return 0;
}
