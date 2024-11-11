#include <bits/stdc++.h>
int N, K, M;
long long dp[1000050];
char S[1000050];
int main(int argc, char *argv[]) {
  scanf("%d%d%s", &N, &K, S + 1);
  M = strlen(S + 1);
  int last[100], c, opt;
  memset(last, -1, sizeof(last));
  dp[0] = 1;
  for (int i = 1; i <= N + M; ++i) {
    if (i <= M)
      c = S[i] - 'a';
    else {
      opt = N + M + 1, c = 0;
      for (int j = 0; j < K; ++j) {
        if (opt > last[j]) {
          opt = last[j], c = j;
          if (opt == -1) break;
        }
      }
    }
    if (last[c] > 0)
      dp[i] = (dp[i - 1] * 2 % 10000000007 - dp[last[c] - 1] + 10000000007) %
              10000000007;
    else
      dp[i] = dp[i - 1] * 2 % 10000000007;
    last[c] = i;
  }
  printf("%I64\n", dp[M + N]);
  return 0;
}
