#include <bits/stdc++.h>
using namespace std;
void prime(int a, vector<int> &v) {
  for (long long int i = 2; i * i <= a; i++) {
    if (a % i == 0) v.push_back(i);
    while (a % i == 0) {
      a = a / i;
    }
  }
  if (a > 1) v.push_back(a);
}
long long int mod;
long long int expmod(long long int a, long long int b) {
  if (b == 1) return a;
  if (b == 0) return 1;
  long long int m1 = expmod(a, b / 2) % mod;
  if (b % 2) return ((m1 * m1) % mod * a % mod) % mod;
  return (m1 * m1) % mod;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
int dp[100001][2];
int t;
int comp(int a[], int i, int j) {
  if (i >= t) return 0;
  if (dp[i][j] == -1) {
    if (j % 2 == 0) {
      if (i == t - 1)
        dp[i][j] = comp(a, i + 1, 1) + a[i];
      else
        dp[i][j] =
            min(comp(a, i + 2, 1) + a[i] + a[i + 1], comp(a, i + 1, 1) + a[i]);
    } else {
      if (i == t - 1)
        dp[i][j] = comp(a, i + 1, 0);
      else
        dp[i][j] = min(comp(a, i + 1, 0), comp(a, i + 2, 0));
    }
  }
  return dp[i][j];
}
int main() {
  int w;
  cin >> w;
  while (w--) {
    int n;
    cin >> n;
    int a[n];
    t = n;
    for (int i = 0; i < n; i++) cin >> a[i];
    memset(dp, -1, sizeof(dp));
    int r = comp(a, 0, 0);
    cout << r;
    cout << endl;
  }
}
