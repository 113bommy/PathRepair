#include <bits/stdc++.h>
using namespace ::std;
const int maxn = 5003;
const int mod = 1e9 + 7;
const int inf = 1e9 + 500;
int dp[maxn][maxn];
int pr[maxn][maxn];
int p[maxn];
int s[maxn];
int a[maxn];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    dp[i][n - 1] = 1;
    int ss = 0;
    for (int j = i; j < n - 1; j++) {
      ss += a[i];
      while (p[j + 1] < n && s[j + 1] < ss) {
        p[j + 1]++;
        s[j + 1] += a[p[j + 1]];
      }
      if (p[j + 1] == n) {
        dp[i][j] = 1;
      } else {
        dp[i][j] = pr[j + 1][p[j + 1]] + 1;
      }
    }
    pr[i][n - 1] = 1;
    for (int j = n - 2; j >= i; j--) {
      pr[i][j] = max(pr[i][j + 1], dp[i][j]);
    }
    p[i] = i;
    s[i] = a[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, dp[0][i]);
  }
  cout << n - ans;
}
