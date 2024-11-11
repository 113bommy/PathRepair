#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, q;
  std::cin >> n >> q;
  long long int a[n + 1];
  for (auto i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  set<int> s;
  long long int dp[n + 1];
  memset(dp, 0, sizeof(dp));
  dp[n] = 1;
  s.insert(a[n]);
  for (auto i = n - 1; i >= 1; i--) {
    if (s.find(a[i]) != s.end()) {
      dp[i] = dp[i + 1];
    } else {
      s.insert(a[i]);
      dp[i] = dp[i + 1] + 1;
    }
  }
  do {
    q--;
    int x;
    std::cin >> x;
    std::cout << dp[x] << " ";
  } while (q > 0);
}
