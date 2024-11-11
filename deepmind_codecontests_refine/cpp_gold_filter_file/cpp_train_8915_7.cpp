#include <bits/stdc++.h>
using namespace std;
inline long long mod(long long n, long long m) {
  long long ret = n % m;
  if (ret < 0) ret += m;
  return ret;
}
long long gcd(long long a, long long b) {
  return (b == 0LL ? a : gcd(b, a % b));
}
long long exp(long long a, long long b, long long m) {
  if (b == 0LL) return 1LL;
  if (b == 1LL) return mod(a, m);
  long long k = mod(exp(a, b / 2, m), m);
  if (b & 1LL) {
    return mod(a * mod(k * k, m), m);
  } else
    return mod(k * k, m);
}
const int N = 200100;
const int inf = 1e9 + 7;
int a[N];
int dp[2][N];
int b_search(int l, int r, int val, int ar[]) {
  int m, ans = -1;
  while (l <= r) {
    m = (l + r) / 2;
    if (ar[m] <= val)
      ans = m, l = m + 1;
    else
      r = m - 1;
  }
  return ans + 1;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < N; i++) {
    dp[0][i] = dp[1][i] = inf;
  }
  dp[0][0] = a[0];
  dp[1][0] = inf;
  int last_val = a[0], last = 0;
  for (int i = 1; i < n; i++) {
    int pos = b_search(0, n, a[i] - i + 1, dp[1]);
    dp[1][pos] = min(dp[1][pos], a[i] - i + 1);
    dp[1][last] = min(dp[1][last], last_val);
    pos = b_search(0, n, a[i] - i, dp[0]);
    last_val = a[i] - i;
    last = pos;
    dp[0][pos] = min(dp[0][pos], a[i] - i);
  }
  int res = n - 1 - b_search(0, n, inf - 1, dp[1]);
  cout << res << "\n";
}
