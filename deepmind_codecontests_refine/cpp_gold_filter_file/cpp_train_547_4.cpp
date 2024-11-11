#include <bits/stdc++.h>
const long long int M = 998244353;
const long long int inf = 1e18 + 5;
using namespace std;
long long int power(long long int a, long long int n, long long int p) {
  long long int res = 1;
  a = a % p;
  while (n > 0) {
    if (n & 1) res = (res * a) % p;
    n = n >> 1;
    a = (a * a) % p;
  }
  return res;
}
void sieve(vector<long long int>& v, long long int n) {
  v.push_back(n);
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      v.push_back(i);
      if (i != n / i) v.push_back(n / i);
    }
  }
}
long long int mm(long long int a, long long int b, long long int mod) {
  long long int res = 0;
  a %= mod;
  while (b) {
    if (b & 1) res = (res + a) % mod;
    a = (2 * a) % mod;
    b >>= 1;
  }
  return res;
}
bool dp[1003][1003];
int knapsack(int a[], int n, int k) {
  if (n < 0) return 0;
  if (k == 0) return 1;
  if (dp[n][k] != -1) return dp[n][k];
  if (a[n] > k) return dp[n][k] = knapsack(a, n - 1, k);
  return dp[n][k] = knapsack(a, n - 1, k - a[n]) || knapsack(a, n - 1, k);
}
void solve() {
  int n, m;
  cin >> n >> m;
  int a[n][m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((i + j) % 2 == 0) {
        if (a[i][j] % 2)
          cout << a[i][j] + 1 << " ";
        else
          cout << a[i][j] << " ";
      } else {
        if (a[i][j] % 2)
          cout << a[i][j] << " ";
        else
          cout << a[i][j] + 1 << " ";
      }
    }
    cout << "\n";
  }
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  ;
  long long int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
