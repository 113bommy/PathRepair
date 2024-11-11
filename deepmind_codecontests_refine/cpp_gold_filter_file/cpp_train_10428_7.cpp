#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
const int p = 998244353;
int dp[maxn][maxn];
int n, k;
int a[maxn];
int s[maxn][maxn];
int ans;
int solve(int x) {
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = 0;
      s[i][j] = 0;
    }
  }
  for (int j = 1; j <= n; j++) dp[1][j] = 1;
  for (int i = 1; i <= k; i++) {
    int l = 1;
    for (int j = 1; j <= n; j++) {
      while (a[j] - a[l] >= x) l++;
      dp[i][j] = (dp[i][j] + s[i - 1][l - 1]) % p;
      s[i][j] = (s[i][j - 1] + dp[i][j]) % p;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) ans = (ans + dp[k][i]) % p;
  return ans;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= (a[n]) / (k - 1); i++) {
    ans = (ans + solve(i)) % p;
  }
  cout << ans << endl;
  return 0;
}
