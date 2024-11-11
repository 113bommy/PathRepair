#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 3;
const int MAXM = 53e4;
const long long INF = 1e3;
long long dp[MAXM];
void zepchnij(int v) {
  dp[v * 2] = min(dp[v * 2], dp[v]);
  dp[v * 2 + 1] = min(dp[v * 2 + 1], dp[v]);
}
long long wez(int v, int x, int y, int a) {
  if (x == y) return dp[v];
  zepchnij(v);
  if ((x + y) / 2 >= a) return wez(v * 2, x, (x + y) / 2, a);
  return wez(v * 2 + 1, (x + y) / 2 + 1, y, a);
}
void ustaw(int v, int x, int y, int a, int b, long long war) {
  if (y < a || x > b) return;
  if (x >= a && y <= b) {
    dp[v] = min(dp[v], war);
    return;
  }
  zepchnij(v);
  ustaw(v * 2, x, (x + y) / 2, a, b, war);
  ustaw(v * 2 + 1, (x + y) / 2 + 1, y, a, b, war);
}
int main() {
  int n, k;
  char ch;
  int pot = 1;
  long long dod;
  scanf("%d %d ", &n, &k);
  while (pot < n) pot *= 2;
  for (int i = 1; i < 2 * pot; i++) dp[i] = INF;
  for (int i = 1; i <= n; i++) {
    scanf("%c", &ch);
    if (i == 1)
      dp[i + pot - 1] = 1LL;
    else
      dp[i + pot - 1] =
          min(dp[i + pot - 1], wez(1, 1, pot, i - 1) + (long long)(i));
    if (ch == '1') {
      if (i <= k + 1)
        dod = 0;
      else
        dod = wez(1, 1, pot, i - k - 1);
      ustaw(1, 1, pot, max(i - k, 1), min(i + k, n), dod + (long long)(i));
    }
  }
  printf("%lld", wez(1, 1, pot, n));
  return 0;
}
