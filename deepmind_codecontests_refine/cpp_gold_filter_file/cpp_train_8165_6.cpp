#include <bits/stdc++.h>
using namespace std;
int main() {
  const long size = 2e+5;
  vector<long long> v(size, 0), dp(size, 0);
  long n;
  cin >> n;
  long a, _min = size;
  for (long i = 0; i < n; ++i) {
    cin >> a;
    ++v[a];
  }
  dp[1] = v[1];
  for (long i = 2; i < size; ++i) {
    dp[i] = max(dp[i - 2] + v[i] * i, dp[i - 1]);
  }
  cout << dp[size - 1] << endl;
  return 0;
}
