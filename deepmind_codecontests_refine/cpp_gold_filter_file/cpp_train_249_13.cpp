#include <bits/stdc++.h>
using namespace std;
map<pair<long long, long long>, long long> dp;
long long A, B, N, win = -1;
bool larger_n(long long x, long long y) {
  long long res = 1;
  while (y--) {
    res *= x;
    if (res >= N) return 1;
  }
  return 0;
}
long long dfs(long long a, long long b) {
  if (dp[make_pair(a, b)])
    return dp[make_pair(a, b)];
  else if (larger_n(a, b))
    return dp[make_pair(a, b)] = 1;
  else if (larger_n(a + 1, b) && larger_n(a, b + 1))
    return dp[make_pair(a, b)] = 1;
  else {
    if (a > 100000) {
      if ((N - a + 1) % 2 == 1)
        return dp[make_pair(a, b)] = 2;
      else
        return dp[make_pair(a, b)] = 1;
    }
    if (dfs(a + 1, b) == 1 && larger_n(a + 1, b) == 0)
      return dp[make_pair(a, b)] = 2;
    if (dfs(a, b + 1) == 1 && larger_n(a, b + 1) == 0)
      return dp[make_pair(a, b)] = 2;
    return dp[make_pair(a, b)] = 1;
  }
}
signed main() {
  cin >> A >> B >> N;
  if (A == 1) {
    if (larger_n(A + 1, B)) {
      puts("Missing");
      return 0;
    }
  }
  if (B == 1) {
    if (A * A >= N) {
      long long now = N - A + 1;
      if (now % 2 == 0)
        puts("Stas");
      else
        puts("Masha");
      return 0;
    }
  }
  win = dfs(A, B);
  if (win == 2)
    puts("Masha");
  else
    puts("Stas");
  return 0;
}
