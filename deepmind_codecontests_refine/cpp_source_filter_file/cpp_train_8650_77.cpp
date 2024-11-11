#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
long long int modInverse(long long int a, long long int m) {
  long long int m0 = m;
  long long int y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long int q = a / m;
    long long int t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
long long int dp[101][10001] = {0}, dp1[101][10001] = {0};
int f(int i, int j, int k, int n) {
  if (k > n / 2) {
    return 0;
  }
  long long int u = 1;
  for (int i = 1; i <= k; i++) {
    u *= i;
    u %= mod;
  }
  for (int i = 1; i <= j; i++) {
    u *= modInverse(i, mod);
    u %= mod;
  }
  for (int i = 1; i + j <= k; i++) {
    u *= modInverse(i, mod);
    u %= mod;
  }
  if (dp[j][i * j] != u) {
    return 1;
  }
  return 0;
}
void solve() {
  int n;
  cin >> n;
  int A[n];
  set<int> gg;
  int B[101] = {0};
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    gg.insert(A[i]);
    B[A[i]]++;
  }
  if (gg.size() <= 2) {
    cout << n;
    return;
  }
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= 5100; j++) {
      for (int k = 0; k <= 50; k++) {
        if (dp[k][j] && j + A[i] <= 5100) {
          dp1[k + 1][j + A[i]] += dp[k][j];
          dp1[k + 1][j + A[i]] %= mod;
        }
      }
    }
    for (int j = 0; j <= 5100; j++) {
      for (int k = 0; k <= 50; k++) {
        dp[k][j] += dp1[k][j];
        dp[k][j] %= mod;
        dp1[k][j] = 0;
      }
    }
  }
  int u = 0;
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= B[i]; j++) {
      if (f(i, j, B[i], n) == 0) {
        u = max(u, j);
      } else {
        break;
      }
    }
  }
  cout << u;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) solve();
}
