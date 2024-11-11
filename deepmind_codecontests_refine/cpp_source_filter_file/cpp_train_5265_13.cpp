#include <bits/stdc++.h>
using namespace std;
long long n, x, dp[1005], sum(2), jum;
vector<long long> v;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    dp[i] = 1e18;
  }
  while (jum <= 10) {
    vector<long long> v;
    jum++;
    for (int i = 1; i <= n; i++) {
      if ((i % sum) < (sum / 2)) {
        v.push_back(i);
      }
    }
    cout << v.size() << '\n';
    for (int i = 0; i < v.size(); i++) {
      cout << v[i] << " ";
    }
    cout << '\n';
    fflush(stdout);
    for (int i = 1; i <= n; i++) {
      cin >> x;
      if (i % sum >= sum / 2) {
        dp[i] = min(dp[i], x);
      }
    }
    if (n > v.size()) {
      cout << n - v.size() << '\n';
      for (int i = 1; i <= n; i++) {
        if (i % sum >= sum / 2) {
          cout << i << " ";
        }
      }
      cout << '\n';
      fflush(stdout);
      for (int i = 1; i <= n; i++) {
        cin >> x;
        if (i % sum < sum / 2) {
          dp[i] = min(dp[i], x);
        }
      }
    }
    sum *= 2;
  }
  cout << -1 << '\n';
  for (int i = 1; i <= n; i++) {
    cout << dp[i] << " ";
  }
  cout << '\n';
}
