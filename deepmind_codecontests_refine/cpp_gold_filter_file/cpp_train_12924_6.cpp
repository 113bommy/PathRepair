#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10, mod = 1e9 + 7;
const long long inf = 1e18;
int dp[12][maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  long long ans = 0;
  for (int i = 1; i <= int((s).size()); i++) {
    int x = s[i - 1] - '0';
    for (int j = x + 1; j < 11; j++) {
      dp[(j * (j - 1) * 6 + x + 10) % 11][i] += dp[j][i - 1];
    }
    if (x != 0) {
      dp[x][i]++;
    }
    for (int j = 0; j < 11; j++) {
      ans += dp[j][i];
    }
  }
  return cout << ans << endl, 0;
}
