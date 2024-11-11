#include <bits/stdc++.h>
using namespace std;
class BIT {
 public:
  int size;
  vector<long long> arr;
  BIT(int n) {
    size = n + 5;
    arr.resize(size);
  }
  void add(int i, long long v) {
    for (int x = i + 1; x < size; x += (x & (-x))) arr[x] += v;
  }
  long long sum(int i) {
    i = min(i, size - 2);
    long long res = 0;
    for (int x = i + 1; x > 0; x -= (x & (-x))) res += arr[x];
    return res;
  }
};
long long cal(vector<int> &a, vector<int> &b, vector<vector<int>> &dp) {
  int n = a.size();
  long long res = 0, mod = 998244353;
  vector<long long> imos(n);
  BIT bit(n + 2), lbit(n + 2);
  for (int i = 0; i < n; i++) {
    long long t = a[i] - bit.sum(a[i] - 1);
    if ((b[i] < a[i]) && (bit.sum(b[i]) - bit.sum(b[i] - 1)) == 0) t--;
    long long lt = lbit.sum(a[i] - 1), rt = t - lt;
    long long d = lbit.sum(n);
    if ((bit.sum(b[i]) - bit.sum(b[i] - 1)) == 0) d++;
    res = (res + dp[n - 1 - i][n - 1 - i - (d - 1)] * lt % mod) % mod;
    res = (res + dp[n - 1 - i][n - 1 - i - d] * rt % mod) % mod;
    bit.add(a[i], 1);
    if ((lbit.sum(a[i]) - lbit.sum(a[i] - 1)) != 0) lbit.add(a[i], -1);
    if ((bit.sum(b[i]) - bit.sum(b[i] - 1)) == 0) lbit.add(b[i], 1);
  }
  return res;
}
long long mod_pow(long long a, long long b, long long mod) {
  long long res = 1, c = a;
  while (b) {
    if (b & 1) res = res * c % mod;
    c = c * c % mod;
    b /= 2;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  long long mod = 998244353;
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  long long fact = 1;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0)
        dp[i][j] = fact;
      else {
        dp[i][j] = (mod + dp[i][j - 1] - dp[i - 1][j - 1]) % mod;
      }
    }
    fact = fact * (i + 1) % mod;
  }
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      a[i][j]--;
    }
  }
  long long res = 0;
  BIT bit(n);
  long long v = 0;
  for (int i = 0; i < n; i++) {
    int t = a[0][i] - bit.sum(a[0][i]);
    v = (v + t * dp[n - 1 - i][0] % mod) % mod;
    bit.add(a[0][i], 1);
  }
  res = v * mod_pow(dp[n][n], n - 1, mod) % mod;
  for (int i = 1; i < n; i++) {
    long long coef = cal(a[i], a[i - 1], dp);
    res = (res + coef * mod_pow(dp[n][n], n - 1 - i, mod) % mod) % mod;
  }
  cout << res << "\n";
  return 0;
}
