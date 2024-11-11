#include <bits/stdc++.h>
using namespace std;
long long int dp[5005][5005] = {{0}};
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  long long int ans = 0;
  long long int n = s.length();
  for (long long int i = 1; i < n; i++) {
    long long int cnt = 0, k = 0;
    for (long long int j = i; j < n; j++) {
      if (s[j] == '(' || s[j] == '?')
        cnt++;
      else
        cnt--;
      if (cnt < 0) k = 1;
      if (k) dp[i][j] = 1;
    }
  }
  for (long long int i = 0; i < n; i++) {
    long long int cnt = 0, k = 0;
    for (long long int j = i; j >= 0; j--) {
      if (s[j] == ')' || s[j] == '?')
        cnt++;
      else
        cnt--;
      if (cnt < 0) k = 1;
      if (k) dp[j][i] = 1;
    }
  }
  for (long long int i = 0; i < n; i++) {
    for (long long int j = i + 1; j < n; j++) {
      if ((j - i + 1) % 2 == 0 && dp[i][j] == 0) ans++;
    }
  }
  cout << ans << endl;
}
