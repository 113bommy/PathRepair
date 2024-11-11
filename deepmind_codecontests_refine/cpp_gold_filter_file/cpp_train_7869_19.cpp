#include <bits/stdc++.h>
using namespace std;
int n, m, q, G[666][666], R[666][666];
char s[666][666];
long long QM(long long a, long long b, long long c) {
  a %= c;
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % c;
    b >>= 1;
    a = a * a % c;
  }
  return ans;
}
void Gauss(int row, int col) {
  int i, j, k, MR, x, y, ta, tb;
  for (x = 1, y = 1; x <= row && y < col; x++, y++) {
    MR = x;
    for (i = x + 1; i <= row; i++)
      if (abs(G[i][y]) > abs(G[MR][y])) MR = i;
    if (MR != x) {
      for (i = 1; i < col; i++) swap(G[x][i], G[MR][i]);
      for (i = 1; i <= q; i++) swap(R[i][x], R[i][MR]);
    }
    if (!G[x][y]) {
      x--;
      continue;
    }
    for (i = x + 1; i <= row; i++)
      if (G[i][y]) {
        ta = G[x][y];
        tb = G[i][y];
        for (j = y; j < col; j++) G[i][j] = (G[i][j] * ta - G[x][j] * tb) % 5;
        for (j = 1; j <= q; j++) R[j][i] = (R[j][i] * ta - R[j][x] * tb) % 5;
      }
  }
  long long tmp = col - x;
  bool f;
  if (tmp)
    tmp = QM(5, tmp, 1000000007);
  else
    tmp = 1;
  for (i = 1; i <= q; i++) {
    f = 1;
    for (j = x; j <= row; j++)
      if (R[i][j]) {
        f = 0;
        break;
      }
    if (f)
      printf("%I64d\n", tmp);
    else
      printf("0\n");
  }
}
int main() {
  int i, j, k;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) scanf("%s", &s[i][1]);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) G[j][i] = s[i][j] - 'a';
  scanf("%d", &q);
  for (i = 1; i <= q; i++) scanf("%s", &s[i][1]);
  for (i = 1; i <= q; i++)
    for (j = 1; j <= m; j++) R[i][j] = s[i][j] - 'a';
  Gauss(m, n + 1);
}
