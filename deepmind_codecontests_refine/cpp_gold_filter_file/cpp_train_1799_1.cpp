#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int t;
  cin >> t;
  for (; t; --t) {
    ll n;
    cin >> n;
    vector<ll> dp(10000, 0);
    dp[1] = 1;
    int i = 2;
    int countt = 1;
    n -= 1;
    ll sideLength = 2;
    while (n >= 0) {
      dp[i] = sideLength * sideLength + 2 * dp[i - 1];
      sideLength *= 2;
      n -= dp[i];
      i++;
      if (n >= 0) countt++;
    }
    cout << countt << '\n';
  }
  return 0;
}
