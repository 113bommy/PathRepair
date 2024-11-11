#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
long long dp[200000][2];
long long n, k;
long long f(vector<int>& a) {
  int n = a.size();
  long long r = 1;
  dp[0][0] = 0;
  dp[0][1] = 1;
  for (int i = 1; i < n; i++) {
    dp[i][0] = dp[i - 1][0] * (k - 1) % mod;
    dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] * (k - 2)) % mod;
  }
  int negs = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != -1) break;
    r = r * (k - (i != n - 1)) % mod;
    negs++;
  }
  if (negs == n) return r;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] != -1) break;
    r = r * (k - 1) % mod;
  }
  int last = -1, split = 0;
  for (int i = negs; i < n; i++) {
    if (a[i] == -1)
      split++;
    else {
      r = r * dp[split][last != a[i]] % mod;
      last = a[i];
      split = 0;
    }
  }
  return r;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  vector<int> a[2];
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    a[i % 2].push_back(v);
  }
  cout << f(a[0]) * f(a[1]) % mod << endl;
}
