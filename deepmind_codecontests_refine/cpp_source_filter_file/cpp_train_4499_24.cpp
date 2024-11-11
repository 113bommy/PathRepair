#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
const int mod = 1e9 + 7;
long long t, tot, a[maxn], fib[maxn];
void init() {
  fib[1] = fib[0] = 1;
  for (int i = 2; fib[i - 1] <= 1e18; i++, tot++)
    fib[i] = fib[i - 1] + fib[i - 2];
}
int c = 1;
void split(long long n) {
  int li[maxn] = {0};
  for (int i = tot - 1; i >= 1; i--) {
    if (n >= fib[i])
      n -= fib[i], li[i] = 1;
    else
      li[i] = 0;
  }
  c = 1;
  for (int i = 1, cnt = 0; i < tot; i++) {
    if (li[i])
      a[c++] = cnt, cnt = 0;
    else
      cnt++;
  }
}
long long dp[maxn][2];
long long dfs(int pl, int st) {
  if (dp[pl][st] != -1) return dp[pl][st];
  long long ret = 0;
  if (pl == 1) {
    if (st == 0)
      ret = a[1] / 2;
    else
      ret = 1;
    dp[pl][st] = ret;
    return ret;
  }
  if (st)
    ret = dfs(pl - 1, 1) + dfs(pl - 1, 0);
  else
    ret = dfs(pl - 1, 0) * ((a[pl] + 1) / 2) + dfs(pl - 1, 1) * (a[pl] / 2);
  dp[pl][st] = ret;
  return ret;
}
void solve(long long n) {
  split(n);
  cout << dfs(c - 1, 0) + dfs(c - 1, 1) << "\n";
}
int main() {
  init();
  cin >> t;
  while (t--) {
    long long n;
    memset(dp, -1, sizeof dp);
    cin >> n;
    solve(n);
  }
}
