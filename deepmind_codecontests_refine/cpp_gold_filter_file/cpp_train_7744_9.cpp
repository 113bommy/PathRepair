#include <bits/stdc++.h>
using namespace std;
const int N(4010), K(805), INF(999999999);
char str[2 * N];
int s[N][N];
int f[K][N];
inline int sum(int a, int b, int c, int d) {
  return s[c][d] - s[a - 1][d] - s[c][b - 1] + s[a - 1][b - 1];
}
inline int calc(int k, int x, int y) {
  return f[k - 1][x] + sum(x + 1, x + 1, y, y);
}
void dp(int k, int l, int r, int optL, int optR) {
  int mid = (l + r) / 2, optM;
  f[k][mid] = INF;
  for (int i = optL; i <= optR && i < mid; ++i)
    if (f[k][mid] > calc(k, i, mid)) {
      f[k][mid] = calc(k, i, mid);
      optM = i;
    }
  if (l != mid) dp(k, l, mid - 1, optL, optM);
  if (mid != r) dp(k, mid + 1, r, optM, optR);
}
int main() {
  int n, k;
  gets(str);
  sscanf(str, "%d%d", &n, &k);
  for (int i = int(1); i < int(n + 1); ++i) {
    gets(str);
    for (int j = int(1); j < int(n + 1); ++j)
      s[i][j] +=
          s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + str[(j - 1) * 2] - '0';
  }
  for (int i = int(1); i < int(k + 1); ++i)
    if (i == 1)
      dp(1, 1, n, 0, 0);
    else
      dp(i, i, n, i - 1, n);
  printf("%d\n", f[k][n] / 2);
  return 0;
}
