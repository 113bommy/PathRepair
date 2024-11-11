#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long int LINF = 0x3f3f3f3f3f3f3f3fll;
const long double pi = acos(-1);
const int MOD = 1e9 + 7;
long long int min3(long long int a, long long int b, long long int c) {
  if (a <= b && a <= c) return a;
  if (b <= a && b <= c) return b;
  return c;
}
int main() {
  long long int n, i;
  scanf("%lld", &n);
  vector<int> vetor(n + 1, 0);
  vector<vector<long long int> > dp(n + 3, vector<long long int>(3, LINF));
  dp[0][0] = 0;
  dp[0][1] = 0;
  dp[0][2] = 0;
  for (i = 1; i <= n; i++) {
    scanf("%d", &vetor[i]);
    if (vetor[i] == 0) {
      dp[i][0] = min3(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]) + 1;
    }
    if (vetor[i] == 3) {
      dp[i][0] = min3(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]) + 1;
      dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
      dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
    }
    if (vetor[i] == 1) {
      dp[i][0] = min3(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]) + 1;
      dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
    }
    if (vetor[i] == 2) {
      dp[i][0] = min3(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]) + 1;
      dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
    }
  }
  printf("%lld\n", min3(dp[n][0], dp[n][1], dp[n][2]));
  return 0;
}
