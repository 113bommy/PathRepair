#include <bits/stdc++.h>
using namespace std;
const int N_ = 3e5 + 10, N = 20;
double dp[N_][N], p[N][N];
int n;
void print(int x) {
  int stk[110], top = 0;
  memset(stk, 0, sizeof stk);
  while (x) {
    if (x & 1)
      stk[++top] = 1;
    else
      stk[++top] = 0;
    x >>= 1;
  }
  for (int i = n; i >= 1; i--) cout << stk[i];
  puts("");
}
double f(int s, int i) {
  if (!(s & (1 << i - 1))) puts("ERR");
  if (dp[s][i]) return dp[s][i];
  for (int j = 1; j <= n; j++)
    if ((j != i) && (s & (1 << j - 1))) {
      dp[s][i] = max(dp[s][i], f(s - (1 << j - 1), i) * p[i][j] +
                                   f(s - (1 << i - 1), j) * p[j][i]);
    }
  return dp[s][i];
}
int main() {
  cin >> n;
  n--;
  if (n == 0) {
    puts("1");
    return 0;
  }
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) cin >> p[i][j];
  for (int i = 1; i <= n; i++) {
    dp[1 << i - 1][i] = p[0][i];
  }
  double ans = 0;
  for (int i = 1; i <= n; i++) ans = max(ans, f((1 << n) - 1, i));
  printf("%.10lf\n", ans);
  return 0;
}
