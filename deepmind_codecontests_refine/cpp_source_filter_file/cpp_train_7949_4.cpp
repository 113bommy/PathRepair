#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int c[20];
int f[20][20][2];
char s[20];
int cc;
int x[20];
void init() {
  int n = strlen(s);
  f[0][0][0] = 1;
  for (int i = 0; s[i]; ++i) {
    for (int j = 0; j < 10; ++j)
      if (f[i][j][0] + f[i][j][1]) {
        if (s[i] < '4') {
          f[i + 1][j][0] += f[i][j][0];
          if (s[i] > '0') f[i + 1][j][1] += f[i][j][0] * (s[i] - '0');
        } else if (s[i] == '4') {
          f[i + 1][j + 1][0] += f[i][j][0];
          f[i + 1][j][1] += f[i][j][0] * (s[i] - '0');
        } else if (s[i] < '7') {
          f[i + 1][j][0] += f[i][j][0];
          f[i + 1][j][1] += f[i][j][0] * (s[i] - '0' - 1);
          f[i + 1][j + 1][1] += f[i][j][0];
        } else if (s[i] == '7') {
          f[i + 1][j + 1][0] += f[i][j][0];
          f[i + 1][j][1] += f[i][j][0] * (s[i] - '0' - 1);
          f[i + 1][j + 1][1] += f[i][j][0];
        } else {
          f[i + 1][j][0] += f[i][j][0];
          f[i + 1][j][1] += f[i][j][0] * (s[i] - '0' - 2);
          f[i + 1][j + 1][1] += f[i][j][0] * 2;
        }
        f[i + 1][j][1] += f[i][j][1] * 8;
        f[i + 1][j + 1][1] += f[i][j][1] * 2;
      }
  }
  for (int i = 0; i < 10; ++i) c[i] += f[n][i][0] + f[n][i][1];
  --c[0];
}
void dfs(int d, int sum, int t, const int n) {
  if (sum >= n) return;
  if (d == 6) {
    if (sum < n) cc = (cc + t) % MOD;
    return;
  }
  for (int i = 0; i < 10; ++i)
    if (c[i] > x[i]) {
      ++x[i];
      dfs(d + 1, sum + i, (long long)t * (c[i] - x[i] + 1) % MOD, n);
      --x[i];
    }
}
int main() {
  int m;
  scanf("%s", s);
  init();
  int tot = 0;
  for (int i = 1; i < 10; ++i)
    if (c[i]) {
      cc = 0;
      memset(x, 0, sizeof(x));
      --c[i];
      dfs(0, 0, 1, c[i]);
      ++c[i];
      tot = (tot + (long long)c[i] * cc) % MOD;
    }
  printf("%d\n", tot);
  return 0;
}
