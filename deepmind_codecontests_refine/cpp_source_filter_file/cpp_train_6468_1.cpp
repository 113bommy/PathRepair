#include <bits/stdc++.h>
using namespace std;
long long fpow(long long a, long long b, long long p = 1000000007) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % p;
    a = (a * a) % p;
    b /= 2;
  }
  return b;
}
string s;
long long n, a[105];
long long dp[105][105][105];
long long rec(long long start, long long end, long long prefix) {
  if (start >= end) return 0;
  if (end == start + 1) {
    dp[start][end][prefix] = a[prefix + 1];
    return a[prefix + 1];
  }
  if (dp[start][end][prefix] != 0) return dp[start][end][prefix];
  long long ans = a[1] + rec(start + 1, end, 0);
  for (int i = start + 1; i < end; i++) {
    if (s[i] == s[start]) {
      ans = max(ans, rec(start + 1, i, 0) + rec(i, end, prefix + 1));
    }
  }
  dp[start][end][prefix] = ans;
  return ans;
}
int main() {
  memset(dp, sizeof(dp), 0);
  cin >> n;
  cin >> s;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cout << rec(0, n, 0);
}
