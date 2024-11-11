#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n;
vector<long long> vec[100005];
bool a[100005];
long long dp[100005][2];
long long kuaism(long long n, long long m, long long mod) {
  long long basic = n;
  long long ans = 1;
  while (m) {
    if (m & 1) {
      ans *= basic;
      ans %= mod;
    }
    m >>= 1;
    basic = basic * basic;
    basic = basic % mod;
  }
  return (long long)ans;
}
long long dfs(long long x, bool c) {
  if (dp[x][c] != -1) return dp[x][c];
  if (vec[x].size() == 0) {
    return dp[x][c] = (a[x] == c);
  }
  if (c == true && a[x] == false) {
    long long res = 0;
    long long k = 1;
    for (long long i = 0; i < vec[x].size(); i++) {
      k *= (dfs(vec[x][i], true) + dfs(vec[x][i], false) % mod) % mod;
      k %= mod;
    }
    long long t;
    for (long long i = 0; i < vec[x].size(); i++) {
      t = (dfs(vec[x][i], true) + dfs(vec[x][i], false));
      t %= mod;
      res +=
          ((1LL * k * kuaism(t, 1e9 + 5, mod)) % mod * dfs(vec[x][i], true)) %
          mod;
      res %= mod;
    }
    return dp[x][c] = res % mod;
  } else if (c == false && a[x] == false) {
    long long res = 1;
    for (long long i = 0; i < vec[x].size(); i++) {
      res *= (dfs(vec[x][i], false) + dfs(vec[x][i], true)) % mod;
      res %= mod;
    }
    return dp[x][c] = res % mod;
  } else if (a[x] == true && c == false) {
    return dp[x][c] = 0;
  } else if (a[x] == true && c == true) {
    long long res = 1;
    for (long long i = 0; i < vec[x].size(); i++) {
      res *= (dfs(vec[x][i], false) + dfs(vec[x][i], true)) % mod;
      res %= mod;
    }
    return dp[x][c] = res % mod;
  }
}
int main() {
  memset(dp, -1, sizeof(dp));
  cin >> n;
  long long t;
  for (long long i = 1; i < n; i++) {
    scanf("%I64d", &t);
    vec[t].push_back(i);
  }
  for (long long i = 0; i < n; i++) {
    scanf("%I64d", &t);
    a[i] = t;
  }
  cout << dfs(0, true) << endl;
  return 0;
}
