#include <bits/stdc++.h>
using namespace std;
const int N = 105;
long long fib[N], dp[N][2];
int main() {
  fib[1] = 1;
  fib[2] = 2;
  for (int i = 3; i <= 88; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  long long n, t;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> v;
    v.clear();
    for (int i = 88; i >= 1; i--) {
      if (n >= fib[i]) {
        v.push_back(i);
        n -= fib[i];
      }
    }
    reverse(v.begin(), v.end());
    dp[0][0] = 1;
    dp[0][1] = (v[0] - 1) / 2;
    for (int i = 1; i < v.size(); i++) {
      dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
      dp[i][1] = dp[i - 1][0] * (v[i] - v[i - 1] - 1) / 2 +
                 dp[i - 1][1] * (v[i] - v[i - 1]) / 2;
    }
    cout << dp[v.size() - 1][0] + dp[v.size() - 1][1] << endl;
  }
  return 0;
}
