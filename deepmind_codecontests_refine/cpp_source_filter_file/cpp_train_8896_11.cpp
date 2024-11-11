#include <bits/stdc++.h>
using namespace std;
const int maxN = 1010;
string a;
int n;
int dp[maxN][2];
int main() {
  cin >> n;
  cin >> a;
  if (a[0] == '1') {
    dp[0][1] = 0;
    dp[0][0] = 1;
  } else {
    dp[0][0] = 1;
    dp[0][1] = 0;
  }
  for (int i = 1; i <= n - 1; i++) {
    dp[i][0] = dp[i - 1][1] + (a[i] == '1');
    dp[i][1] = dp[i - 1][0] + (a[i] == '0');
  }
  cout << min(dp[n - 1][0], dp[n - 1][1]);
}
