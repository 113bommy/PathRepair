#include <bits/stdc++.h>
using namespace std;
int n, m, Q, deg[400], d[400], q[400];
long long T;
long long dp[3000000];
int a[400], b[400], w[400][400];
vector<int> vec[400];
int main() {
  for (int i = (0); i < (400); i++)
    for (int j = (0); j < (400); j++) w[i][j] = (1 << 28);
  for (int i = (0); i < (400); i++) w[i][i] = 0;
  scanf("%d%d%d", &n, &Q, &T);
  for (int i = (0); i < (n); i++) scanf("%d", a + i);
  for (int i = (0); i < (Q); i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    w[y][x] = -1;
  }
  for (int k = (0); k < (n); k++)
    for (int i = (0); i < (n); i++)
      for (int j = (0); j < (n); j++) w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
  for (int i = (0); i < (n); i++)
    if (w[i][i] < 0) {
      puts("0");
      return 0;
    }
  for (int i = (0); i < (n); i++) {
    for (int j = (0); j < (n); j++)
      if (w[i][j] <= 0) b[i] += a[j];
    for (int j = (0); j < (n); j++)
      if (w[j][i] < 0) {
        T -= b[i];
        break;
      }
  }
  if (T < 0) {
    puts("0");
    return 0;
  }
  dp[0] = 1;
  for (int i = (0); i < (n); i++)
    for (int j = (0); j <= (T - b[i]); j++)
      dp[j + b[i]] = (dp[j + b[i]] + dp[j]) % 1000000007;
  printf("%d\n", dp[T]);
  return 0;
}
