#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000003, MAX = 200001, INF = 1 << 30;
long long rui(long long a, long long b) {
  if (b == 1)
    return a % mod;
  else if (b == 0)
    return 1;
  else if (b % 2 == 0)
    return (rui(a, b / 2) * rui(a, b / 2)) % mod;
  else
    return (rui(a, b - 1) * a) % mod;
}
int main() {
  vector<long long> A(11), ans(11);
  for (int i = 0; i < 11; i++) {
    cout << "? " << i << endl;
    cin >> A[i];
  }
  for (int i = 0; i < 11; i++) {
    vector<vector<long long>> dp(12, vector<long long>(11));
    dp[0][0] = 1;
    for (int j = 0; j < 11; j++) {
      if (i == j) {
        for (int k = 0; k < 11; k++) {
          dp[j + 1][k] = dp[j][k];
        }
      } else {
        long long b = i - j;
        b = (mod + abs(b) / b * rui(abs(b), mod - 2)) % mod;
        for (int k = 0; k < 10; k++) {
          dp[j + 1][k + 1] += dp[j][k] * b;
          dp[j + 1][k] += dp[j][k] * b * (mod - j);
          dp[j + 1][k + 1] %= mod;
          dp[j + 1][k] %= mod;
        }
      }
    }
    for (int k = 0; k < 11; k++) {
      ans[k] += dp[11][k];
      ans[k] %= mod;
    }
  }
  long long x = -1;
  for (long long i = 0; i < mod; i++) {
    long long sum = 0;
    for (int j = 0; j < 11; j++) {
      sum += ans[j] * rui(i, j);
      sum %= mod;
    }
    if (sum == 0) x = i;
  }
  cout << "! " << x << endl;
}
