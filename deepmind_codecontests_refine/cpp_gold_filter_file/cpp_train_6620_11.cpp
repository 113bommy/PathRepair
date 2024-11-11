#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 50;
const long long mod = 10007;
char s[maxn];
int dp[maxn][maxn];
int pre[maxn][maxn];
void prin(int pos, int val) {
  if (pos == 0) return;
  if (pre[pos][val] == 1) {
    prin(pos - 1, val - 1);
    cout << "W";
  } else if (pre[pos][val] == -1) {
    prin(pos - 1, val + 1);
    cout << "L";
  } else if (pre[pos][val] == 0) {
    prin(pos - 1, val);
    cout << "D";
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  cin >> s + 1;
  dp[0][k] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < k + k; j++) {
      if (!dp[i][j]) continue;
      if (s[i + 1] == 'W' || s[i + 1] == '?')
        dp[i + 1][j + 1] = 1, pre[i + 1][j + 1] = 1;
      if (s[i + 1] == 'L' || s[i + 1] == '?')
        dp[i + 1][j - 1] = 1, pre[i + 1][j - 1] = -1;
      if (s[i + 1] == 'D' || s[i + 1] == '?')
        dp[i + 1][j] = 1, pre[i + 1][j] = 0;
    }
  }
  if ((dp[n][0] | dp[n][k + k]) == 0) {
    cout << "NO" << endl;
    return 0;
  }
  if (dp[n][0]) {
    prin(n, 0);
  } else if (dp[n][k + k]) {
    prin(n, k + k);
  }
  return 0;
}
