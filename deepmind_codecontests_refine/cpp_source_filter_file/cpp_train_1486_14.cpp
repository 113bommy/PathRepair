#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const long long oo = INT_MAX;
const long long MOD = 1e9 + 7;
const long long sz = 1e6 + 5;
long long n, m;
string s[sz], tmp[sz];
long long cost(string str, long long val, long long c) {
  vector<long long> v(c);
  long long ind = 0;
  while (val && ind < c) {
    v[ind] = val % 2;
    val /= 2;
    ++ind;
  }
  long long ret = 0;
  for (long long i = 0; i < c; ++i) {
    if (str[i] - '0' != v[i]) ret++;
  }
  return ret;
}
long long solve1() {
  vector<vector<long long>> poss = {{1}, {0, 3}, {0, 3}, {1}};
  vector<vector<long long>> dp(n, vector<long long>((1 << 2), 0));
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < (1 << 2); ++j) {
      long long cst = cost(s[i], j, 2);
      dp[i][j] = cst;
      if (i) {
        long long val = INT_MAX;
        for (auto pos : poss[j]) {
          val = min(val, dp[i - 1][pos]);
        }
        dp[i][j] += val;
      }
    }
  }
  long long ret = INT_MAX;
  for (long long i = 0; i < (1 << 2); ++i) {
    ret = min(ret, dp[n - 1][i]);
  }
  return ret;
}
long long solve2() {
  vector<vector<long long>> poss = {{2, 5}, {3, 4}, {0, 7}, {1, 6},
                                    {1, 6}, {0, 7}, {3, 4}, {2, 5}};
  vector<vector<long long>> dp(n, vector<long long>((1 << 3), 0));
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < (1 << 3); ++j) {
      long long cst = cost(s[i], j, 3);
      dp[i][j] = cst;
      if (i) {
        long long val = INT_MAX;
        for (auto pos : poss[j]) {
          val = min(val, dp[i - 1][pos]);
        }
        dp[i][j] += val;
      }
    }
  }
  long long ret = INT_MAX;
  for (long long i = 0; i < (1 << 3); ++i) {
    ret = min(ret, dp[n - 1][i]);
  }
  return ret;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long tc = 1;
  while (tc--) {
    cin >> n >> m;
    for (long long i = 0; i < n; ++i) cin >> s[i];
    if (min(n, m) >= 4) return 0 * printf("-1\n");
    if (min(n, m) == 1) return 0 * printf("0\n");
    if (m > n) {
      for (long long i = 0; i < m; ++i) {
        tmp[i] = "";
        for (long long j = 0; j < n; ++j) tmp[i] += s[j][i];
      }
      for (long long i = 0; i < m; ++i) s[i] = tmp[i];
      swap(n, m);
    }
    if (n == 2)
      return 0 * printf("%lld\n", solve1());
    else
      return 0 * printf("%lld\n", solve2());
  }
}
