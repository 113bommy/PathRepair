#include <bits/stdc++.h>
using namespace std;
const int NMAX = 6000, MOD = 1000000007, ALPHA = 26;
int N, T, ans;
int f[NMAX][NMAX], prefix[NMAX], g[NMAX][ALPHA];
char type[NMAX];
int main() {
  int i, j;
  char c, pre = 0;
  scanf("%d", &N);
  for (i = 1; i <= N; i += 1) {
    scanf(" %c", &c);
    if (c != pre) type[++T] = c;
    pre = c;
  }
  for (i = 1; i <= N; i += 1) {
    if (i == 1) prefix[i] = 1;
    for (j = 1; j <= T; j += 1) {
      (prefix[i] += f[i - 1][j]) %= MOD;
      (f[i][j] += prefix[i]) %= MOD;
      ((f[i][j] -= g[i][type[j] - 'a']) += MOD) %= MOD;
      (g[i][type[j] - 'a'] += f[i][j]) %= MOD;
    }
  }
  for (j = 1; j <= T; j += 1) (ans += f[N][j]) %= MOD;
  printf("%d\n", ans);
  exit(0);
}
