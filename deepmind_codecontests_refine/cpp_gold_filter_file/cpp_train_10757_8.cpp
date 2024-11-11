#include <bits/stdc++.h>
using namespace std;
void inout() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  inout();
  long long int n, i, k;
  string s, e;
  cin >> s >> e >> k;
  n = s.length();
  long long int dp[100100][2];
  memset(dp, 0, sizeof(dp));
  if (s == e)
    dp[0][0] = 1;
  else
    dp[0][1] = 1;
  string s1 = s;
  long long int a = 0, b = 0;
  for (i = 0; i < n; i++) {
    if (s1 == e)
      a++;
    else
      b++;
    s1 = s.substr(0, i + 1);
    s1 = s.substr(i + 1, n - i) + s1;
  }
  for (i = 1; i <= k; i++) {
    dp[i][0] = ((dp[i - 1][0] * (a - 1)) % 1000000007 +
                (dp[i - 1][1] * a) % 1000000007) %
               1000000007;
    dp[i][1] = ((dp[i - 1][1] * (b - 1)) % 1000000007 +
                (dp[i - 1][0] * b) % 1000000007) %
               1000000007;
  }
  cout << dp[k][0] % 1000000007 << endl;
  return 0;
}
