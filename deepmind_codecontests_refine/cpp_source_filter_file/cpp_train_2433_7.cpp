#include <bits/stdc++.h>
using namespace std;
const long long N = 1505;
char en = '\n';
long long inf = 1e16;
long long mod = 1e9 + 7;
long long power(long long x, long long n, long long mod) {
  long long res = 1;
  x %= mod;
  while (n) {
    if (n & 1) res = (res * x) % mod;
    x = (x * x) % mod;
    n >>= 1;
  }
  return res;
}
long long n, k;
long long q[N];
long long s[N];
long long check[2 * N];
long long dp[N][2 * N];
long long offset = 102;
long long recur(long long k, long long rem) {
  if (k && check[rem]) return 0;
  if (k == 0) {
    return check[rem];
  }
  long long &ans = dp[k][rem];
  if (ans != -1) return ans;
  ans = recur(k - 1, rem - 1) or recur(k - 1, rem + 1);
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) {
    cin >> q[i];
  }
  for (long long i = 1; i <= n; i++) {
    cin >> s[i];
  }
  for (long long i = -k; i <= k; i++) {
    long long x = i;
    long long ogx = x;
    long long arr[n + 5];
    for (long long i = 1; i <= n; i++) arr[i] = i;
    while (x > 0) {
      long long temp[n + 5];
      for (long long i = 1; i <= n; i++) temp[i] = arr[i];
      for (long long i = 1; i <= n; i++) {
        arr[i] = temp[q[i]];
      }
      x--;
    }
    while (x < 0) {
      long long temp[n + 5];
      for (long long i = 1; i <= n; i++) temp[i] = arr[i];
      for (long long i = 1; i <= n; i++) {
        arr[q[i]] = temp[i];
      }
      x++;
    }
    long long flag = 0;
    for (long long i = 1; i <= n; i++) {
      if (arr[i] != s[i]) {
        flag = 1;
      }
    }
    if (flag == 0) {
      check[offset + i] = true;
    } else
      check[offset + i] = false;
  }
  memset(dp, -1, sizeof(dp));
  long long res = recur(k, offset + 0);
  if (res)
    cout << "Yes" << en;
  else
    cout << "No" << en;
  return 0;
}
