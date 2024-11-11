#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int TMXN = 1e6 * 4 + 1;
const long long INF = 1e9 + 7;
int n;
int p[N];
long long dp[N];
int main() {
  scanf("%d", &n);
  dp[2] = 2;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
  }
  for (int i = 2; i <= n; i++) {
    dp[i + 1] = (2LL * dp[i]) - dp[p[i]] + 2LL;
    if (dp[i + 1] < 0) {
      dp[i + 1] += INF;
    }
    dp[i + 1] %= INF;
  }
  cout << dp[n + 1];
  return 0;
}
