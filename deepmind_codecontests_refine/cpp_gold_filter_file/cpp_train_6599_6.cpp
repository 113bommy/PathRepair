#include <bits/stdc++.h>
using namespace std;
const int NMax = 110000;
const long long INF = 4294967296LL;
int N, sum[NMax];
char A[NMax];
int S[NMax], L;
unsigned int dp[3][NMax];
int main() {
  scanf("%d %s", &N, A);
  if (N & 1) {
    puts("0");
    return 0;
  }
  int cur = 1, cnt = 0;
  dp[1][0] = 1;
  for (int i = 0; i < N; i++) {
    cur = 1 - cur;
    int start = 1 - (i & 1), end = min(N / 2, i + 1);
    if (A[i] == '?')
      for (int j = start; j <= end; j += 2)
        dp[cur][j] = dp[1 - cur][j + 1] + (j > 0 ? dp[1 - cur][j - 1] : 0);
    else {
      cnt++;
      for (int j = start; j <= end; j += 2)
        dp[cur][j] = j > 0 ? dp[1 - cur][j - 1] : 0;
    }
  }
  if (cnt > N / 2) {
    puts("0");
    return 0;
  }
  cnt = N / 2 - cnt;
  while (cnt--) dp[cur][0] *= 25;
  printf("%u\n", dp[cur][0]);
  return 0;
}
