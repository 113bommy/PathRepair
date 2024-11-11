#include <bits/stdc++.h>
using namespace std;
int dp[100005], n;
string s;
int countStrings(int index) {
  if (index >= n - 1 && s[n - 1] != 'm' || s[n - 1] != 'w') return 1;
  if (dp[index] != -1) return dp[index];
  if (s[index] == 'm' || s[index] == 'w') return dp[index] = 0;
  if ((s[index] == 'n' && s[index + 1] == 'n') ||
      (s[index] == 'u' && s[index + 1] == 'u')) {
    return dp[index] = ((countStrings(index + 2)) % 1000000007 +
                        (countStrings(index + 1)) % 1000000007) %
                       1000000007;
  }
  return (dp[index] = countStrings(index + 1)) % 1000000007;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  n = s.size();
  for (int i = 0; i < n; ++i) dp[i] = -1;
  cout << countStrings(0) << "\n";
  return 0;
}
