#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
const int maxn = 10000 + 5;
const long long inf = 1e18;
long long dp[2][maxn];
long long p[maxn], s[maxn];
int n, c;
int main() {
  cin >> n >> c;
  for (int i = 1; i <= n; i++) scanf("%lld", p + i);
  for (int i = 1; i <= n; i++) scanf("%lld", s + i);
  int pos = 0;
  for (int i = 1; i <= n; i++) {
    pos = pos ^ 1;
    for (int j = 0; j <= i; j++) dp[pos][j] = inf;
    for (int j = 0; j < i; j++) {
      dp[pos][j + 1] = min(dp[pos][j + 1], dp[pos ^ 1][j] + s[i]);
      dp[pos][j] = min(dp[pos][j], dp[pos ^ 1][j] + i * c + p[i]);
    }
  }
  long long ans = inf;
  for (int i = 0; i <= n; i++) ans = min(dp[pos][i], ans);
  cout << ans << endl;
  return 0;
}
