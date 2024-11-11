#include <bits/stdc++.h>
using namespace std;
short int dp[1005][30][30][2];
int N, p;
char S[1005];
bool duyet(int n, int p1, int p2, bool ok) {
  if (n == N) {
    dp[n][p1][p2][ok] = ok;
    return ok;
  }
  if (dp[n][p1][p2][ok] != -1) return dp[n][p1][p2][ok];
  for (int i = max(0, (int)(!ok) * (int)(S[n] - 'a')); i < p; i++)
    if (i != p1 && i != p2) {
      bool ok = duyet(n + 1, i, p1, ok | ((int)(S[n] - 'a') < i));
      if (ok) {
        dp[n][p1][p2][ok] = 1;
        return 1;
      }
    }
  dp[n][p1][p2][ok] = 0;
  return 0;
}
void truyvet(int n, int p1, int p2, bool ok) {
  if (n == N) return;
  for (int i = max(0, (int)(!ok) * (int)(S[n] - 'a')); i < p; i++)
    if (i != p1 && i != p2) {
      if (dp[n + 1][i][p1][ok | ((int)(S[n] - 'a') < i)]) {
        printf("%c", i + 'a');
        truyvet(n + 1, i, p1, ok | ((int)(S[n] - 'a') < i));
        return;
      }
    }
}
int main() {
  scanf("%d%d\n", &N, &p);
  for (int i = 0; i < N; i++) S[i] = getchar();
  memset(dp, 255, sizeof(dp));
  bool ok = duyet(0, p, p + 1, 0);
  if (!ok)
    printf("NO");
  else
    truyvet(0, p, p + 1, 0);
  return 0;
}
