#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
struct Sync_stdio {
  Sync_stdio() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
  }
} _sync_stdio;
long long n, a, b;
vector<long long> v;
long long solve(int x) {
  vector<int> sum(n, -1);
  for (int i = (0); i < (n); ++i) {
    if (v[i] % x == 0) {
      sum[i] = 0;
    } else if (v[i] % x == 1 || v[i] % x == x - 1) {
      sum[i] = b;
    }
  }
  int l = INT_MAX;
  int r = -1;
  for (int i = (0); i < (n); ++i) {
    if (sum[i] == -1) {
      r = i;
      if (l == INT_MAX) {
        l = i;
      }
    }
  }
  vector<vector<long long>> dp(n + 1, vector<long long>(3));
  dp[0][1] = dp[0][2] = 1e16;
  for (int i = (0); i < (n); ++i) {
    if (l <= i) {
      dp[i + 1][0] = 1e16;
    } else {
      dp[i + 1][0] = dp[i][0] + sum[i];
    }
    dp[i + 1][1] = min(dp[i][0], dp[i][1]) + a;
    if (i <= r) {
      dp[i + 1][2] = 1e16;
    } else {
      dp[i + 1][2] = min(dp[i][1], dp[i][2]) + sum[i];
    }
  }
  return *min_element(dp[n].begin(), dp[n].end());
}
int main() {
  scanf("%d%d%d", &n, &a, &b);
  v.resize(n);
  for (int i = (0); i < (n); ++i) {
    scanf("%d", &v[i]);
  }
  set<int> divs;
  for (int i = (v[0] - 1); i < (v[0] + 2); ++i) {
    if (i <= 1) {
      continue;
    }
    int x = i;
    for (int j = (2); j < (100000); ++j) {
      while (x % j == 0) {
        x /= j;
        divs.insert(j);
      }
    }
    if (x > 1) {
      divs.insert(x);
    }
  }
  for (int i = (v.back() - 1); i < (v.back() + 2); ++i) {
    if (i <= 1) {
      continue;
    }
    int x = i;
    for (int j = (2); j < (10000); ++j) {
      while (x % j == 0) {
        x /= j;
        divs.insert(j);
      }
    }
    if (x > 1) {
      divs.insert(x);
    }
  }
  long long res = LLONG_MAX;
  for (auto i : divs) {
    res = min(res, solve(i));
  }
  cout << res;
}
