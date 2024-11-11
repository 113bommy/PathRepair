#include <bits/stdc++.h>
using namespace std;
long long fib[100];
void got() {
  fib[1] = fib[0] = 1;
  for (int i = 2; i < 88; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
}
int dp[88][2];
int main() {
  got();
  int T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    vector<int> id;
    for (int i = 87; i > 0 && n != 0; i--) {
      if (n >= fib[i]) {
        n = n - fib[i];
        id.push_back(i);
      }
    }
    reverse(id.begin(), id.end());
    dp[0][1] = 1;
    dp[0][0] = (id[0] - 1) / 2;
    for (int i = 1; i < id.size(); i++) {
      dp[i][1] = dp[i - 1][1] + dp[i - 1][0];
      dp[i][0] = dp[i - 1][1] * ((id[i] - id[i - 1]) / 2) +
                 dp[i - 1][0] * ((id[i] - id[i - 1] + 1) / 2);
    }
    cout << dp[id.size() - 1][1] + dp[id.size() - 1][0] << endl;
  }
  return 0;
}
