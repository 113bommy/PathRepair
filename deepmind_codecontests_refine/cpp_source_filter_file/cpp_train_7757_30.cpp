#include <bits/stdc++.h>
inline void read(int& x) {
  char c;
  while ((c = getchar()) < '0' || c > '9')
    ;
  x = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
}
using namespace std;
const int maxn = 2050;
const long long max_num = 2e9 + 10;
const int M = 131;
const int inf = 0x7fffffff;
const long long INF = 9E18;
const long long mod = 1e9 + 7;
const int eps = 1e-7;
const double pi = 3.1415926535898;
long long dp[maxn][maxn];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  string s;
  cin >> s;
  int lcnt = 0, rcnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(')
      lcnt++;
    else {
      if (lcnt > 0)
        lcnt--;
      else
        rcnt++;
    }
  }
  dp[0][0] = 1LL;
  for (int i = 1; i <= n - m; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0) {
        dp[i][j] = dp[i - 1][j + 1];
        continue;
      }
      dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]);
    }
  }
  long long ans = 0;
  for (int i = 0; i <= n - m; i++) {
    for (int j = 0; j <= i; j++) {
      if (j >= rcnt && n - m - i >= (j - rcnt) + lcnt) {
        ans += (dp[i][j] * dp[n - m - i][(j - rcnt) + lcnt]);
        ans %= mod;
      }
    }
  }
  cout << ans << endl;
}
