#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100, K = 600, MOD = 1000 * 1000 * 1000 + 7;
int n, k, num, cnt_else, fac[N], dp[K][K];
unordered_map<int, int> cnt;
vector<int> vec;
int sum(int a, int b) {
  a += b;
  if (a < 0)
    a += MOD;
  else if (a >= MOD)
    a -= MOD;
  return a;
}
int mul(int a, int b) { return 1LL * a * b % MOD; }
int power(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = mul(res, a);
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
int c(int a, int b) {
  if (a > b || a < 0) return 0;
  return mul(fac[b], power(mul(fac[a], fac[b - a]), MOD - 2));
}
bool lucky(int num) {
  return (num == 0 ? true
                   : (num % 10 == 4 || num % 10 == 7) && lucky(num / 10));
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  fac[0] = 1;
  for (int i = 1; i < N; i++) fac[i] = mul(fac[i - 1], i);
  cin >> n >> k;
  while (n--) {
    cin >> num;
    if (lucky(num))
      cnt[num]++;
    else
      cnt_else++;
  }
  vec.push_back(0);
  for (auto p : cnt) vec.push_back(p.second);
  int m = vec.size();
  dp[0][0] = 1;
  for (int i = 1; i < m; i++)
    for (int j = 0; j < m; j++) {
      if (j == 0)
        dp[i][j] = 1;
      else
        dp[i][j] = sum(dp[i - 1][j], mul(dp[i - 1][j - 1], vec[i]));
    }
  int ans = 0;
  for (int i = 0; i <= k; i++)
    ans = sum(ans, mul(dp[m - 1][i], c(k - i, cnt_else)));
  cout << ans;
  return 0;
}
