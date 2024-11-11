#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 3;
const int maxm = 1e7 + 3;
const int mod = 1e9 + 7;
const long long oo = 2e18 + 5;
const long double pi = 3.141592653589793238462643383279502884;
void input() {
  if (fopen("abc"
            ".inp",
            "r")) {
    freopen(
        "abc"
        ".inp",
        "r", stdin);
    freopen(
        "abc"
        ".out",
        "w", stdout);
  }
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int n, k;
string s;
int dp[maxn][maxn];
int main() {
  input();
  cin >> n >> k >> s;
  dp[0][k] = 1;
  s = " " + s;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < 2 * k; ++j) {
      if (dp[i - 1][j]) {
        if ((s[i] == 'L' || s[i] == '?') && (j > 1 || i == n)) dp[i][j - 1] = 1;
        if ((s[i] == 'W' || s[i] == '?') && (j < 2 * k - 1 || i == n))
          dp[i][j + 1] = 1;
        if (s[i] == 'D' || s[i] == '?') dp[i][j] = 1;
      }
    }
  }
  if (dp[n][0] || dp[n][2 * k]) {
    int i = n, j = dp[n][0] ? 0 : 2 * k;
    string ans = "";
    while (i) {
      if (s[i] == '?') {
        if (j > 1 && dp[i - 1][j - 1]) {
          ans += 'W';
          j--;
        } else if (j < 2 * k - 1 && dp[i - 1][j + 1]) {
          ans += 'L';
          j++;
        } else
          ans += 'D';
      } else {
        ans += s[i];
        if (s[i] == 'W')
          j--;
        else if (s[i] == 'L')
          j++;
      }
      i--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
  } else
    cout << "NO\n";
  return 0;
}
