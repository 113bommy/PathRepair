#include <bits/stdc++.h>
using namespace std;
long long dp[500009], n, sum, x = 1, y;
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  dp[n] = 10;
  x = 1;
  for (int i = n - 2; i >= 1; i--) {
    sum = (n - i - 1) * (81) * (x);
    sum %= 998244353;
    x *= 10;
    x %= 998244353;
    dp[i] = sum;
  }
  x = 1;
  for (int i = n - 1; i >= 1; i--) {
    x *= 10;
    x %= 998244353;
    sum = 2 * (18) * (x);
    sum %= 998244353;
    dp[i] += sum;
    dp[i] %= 998244353;
  }
  for (int i = 1; i <= n; i++) {
    cout << dp[i] << " ";
  }
  cout << endl;
  return 0;
}
