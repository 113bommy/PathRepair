#include <bits/stdc++.h>
using namespace std;
int n, N;
int x[311];
int cost[311];
int ans = 1e9;
int m[301];
int dp[311][1 << 9];
int solve(int curr, int mask) {
  if (curr == n + 1) {
    if (mask == (1 << N) - 1) {
      return 0;
    }
    return 100000000;
  }
  int &ret = dp[curr][mask];
  if (ret != -1) return ret;
  ret = solve(curr + 1, mask);
  ret = min(ret, solve(curr + 1, mask | m[curr]) + cost[curr]);
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i += 1) {
    cin >> x[i];
  }
  for (int i = 1; i <= n; i += 1) {
    cin >> cost[i];
  }
  for (int i = 1; i <= n; i += 1) {
    vector<int> pFactors;
    int t = x[i];
    for (int j = 2; j * j <= t; j += 1) {
      if (t % j == 0) pFactors.push_back(j);
      while (t % j == 0) {
        t /= j;
      }
    }
    if (t > 1) {
      pFactors.push_back(t);
    }
    N = pFactors.size();
    for (int j = 1; j <= n; j += 1) {
      m[j] = 0;
      for (int k = 0; k < N; k += 1) {
        if (x[j] % pFactors[k] != 0) {
          m[j] |= (1 << k);
        }
      }
    }
    memset(dp, -1, sizeof(dp));
    ans = min(ans, cost[i] + solve(1, 0));
  }
  if (ans > 1e8) {
    cout << "-1";
  } else {
    cout << ans << endl;
  }
  return 0;
}
