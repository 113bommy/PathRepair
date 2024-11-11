#include <bits/stdc++.h>
int n, m, k;
int dp[1000][1001];
long long stt(int l, int mv) {
  if (mv == k) return 1;
  if (dp[l][mv] != -1) return dp[l][mv];
  int i, j;
  long long sm = 0;
  for (i = l - 2; i > 0; i--) {
    sm += stt(i, mv + 1) * (l - 2 - i + 1);
    sm %= 1000000007;
  }
  dp[l][mv] = sm;
  return sm;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  int i, j, l;
  for (i = 0; i < 1000; i++)
    for (l = 0; l <= 1000; l++) dp[i][l] = -1;
  printf("%lld\n", (stt(n, 0) * stt(m, 0)) % 1000000007);
}
