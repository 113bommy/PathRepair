#include <bits/stdc++.h>
using namespace std;
#pragma optimize("gty", on);
const long long INF = 1e9;
const int maxn = 200000;
long long dp[200000], mas[200000];
int main() {
  long long n, k;
  cin >> n >> k;
  for (int i = 1; i < n + 1; i++) {
    cin >> mas[i];
    long long res = 0;
    if (mas[i] == 0) {
      res = min(k, (long long)i - 1) + 1 + min(k, n - i);
      dp[i] = res;
    } else {
      res = dp[mas[i]];
      res += max((long long)0,
                 min(k, (long long)i - 1) + 1 + min(k, n - i) -
                     max(min(n, mas[i] + k) - max((long long)0, i - k) + 1,
                         (long long)0));
      dp[i] = res;
    }
    cout << dp[i] << ' ';
  }
  return 0;
}
