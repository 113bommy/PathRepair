#include <bits/stdc++.h>
using namespace std;
const int nax = 1e5;
long long counter[nax + 1];
long long dp[nax + 1];
int main(void) {
  int n;
  cin >> n;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    counter[x]++;
  }
  dp[0] = 0;
  dp[1] = counter[1];
  for (int i = 2; i <= nax; i++) {
    dp[i] = max(dp[i - 1], dp[i - 2] + counter[i] * i);
  }
  cout << dp[nax] << endl;
  return 0;
}
