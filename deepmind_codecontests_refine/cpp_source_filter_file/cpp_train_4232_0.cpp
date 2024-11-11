#include <bits/stdc++.h>
using namespace std;
const int N = 5005, M = 1e9 + 7;
int dp[N][N], cs[N], ans, n;
char s[N];
void add(int &a, int b) {
  a += b;
  if (a < 0) a += M;
  if (a >= M) a -= M;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf(" %c", s + i);
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[i - 1] == 'f') add(dp[i + 1][j + 1], dp[i][j]);
      if (s[i - 1] != 'f') add(cs[0], dp[i][j]), add(cs[j + 1], -dp[i][j]);
    }
    for (int j = 1; j < n; j++) add(cs[j], cs[j - 1]);
    for (int j = 0; j < n; j++) add(dp[i + 1][j], cs[j]), cs[j] = 0;
  }
  for (int i = 0; i < n; i++) add(ans, dp[n - 1][i]);
  printf("%d\n", ans);
}
