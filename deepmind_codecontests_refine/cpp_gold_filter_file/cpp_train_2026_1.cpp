#include <bits/stdc++.h>
using namespace std;
const int N = 2001;
int dp[N][N], n, k;
string s, p;
int getL(int pos) {
  int now = k - 1;
  for (int i = pos; i >= 0; i--)
    if (s[i] == p[now]) {
      if (now == 0) return i;
      now--;
    }
  return -1;
}
int main() {
  cin >> s >> p;
  n = s.size();
  k = p.size();
  for (int i = 0; i < n; i++) {
    int l = getL(i);
    int need = i - l + 1 - k;
    for (int j = 0; j <= i + 1; j++) {
      if (i > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
      if (i > 0 && j > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
      if (l != -1 && j >= need && j - need <= l)
        dp[i][j] = max(dp[i][j], (l ? dp[l - 1][j - need] : 0) + 1);
    }
  }
  for (int i = 0; i <= n; i++) cout << dp[n - 1][i] << ' ';
  cout << endl;
  return 0;
}
