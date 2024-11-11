#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[2222][222], b[222][2222];
unsigned long long p[2], pw[2][200 * 200];
unsigned long long ph[2][222][2222], h[2][2222], ch[2], temp[2][2222];
void read() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) cin >> b[i][j];
}
void initHash() {
  p[0] = 29;
  p[1] = 31;
  pw[0][0] = pw[1][0] = 1;
  for (int i = 1; i <= m * m; i++) {
    pw[0][i] = pw[0][i - 1] * p[0];
    pw[1][i] = pw[1][i - 1] * p[1];
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      ph[0][i][m] = ph[0][i][m] * p[0] + (b[i][j] - 'a' + 1);
      ph[1][i][m] = ph[1][i][m] * p[1] + (b[i][j] - 'a' + 1);
    }
    for (int j = m + 1; j <= n; j++) {
      ph[0][i][j] =
          (ph[0][i][j - 1] - pw[0][m - 1] * (b[i][j - m] - 'a' + 1)) * p[0] +
          (b[i][j] - 'a' + 1);
      ph[1][i][j] =
          (ph[1][i][j - 1] - pw[1][m - 1] * (b[i][j - m] - 'a' + 1)) * p[1] +
          (b[i][j] - 'a' + 1);
    }
  }
  for (int j = m; j <= n; j++) {
    for (int i = 1; i <= m; i++) {
      h[0][j] = h[0][j] * pw[0][m] + ph[0][i][j];
      h[1][j] = h[1][j] * pw[1][m] + ph[1][i][j];
    }
  }
}
void solve() {
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= m; j++) {
      ch[0] = ch[0] * p[0] + (a[i][j] - 'a' + 1);
      ch[1] = ch[1] * p[1] + (a[i][j] - 'a' + 1);
      temp[0][i] = temp[0][i] * p[0] + (a[i][j] - 'a' + 1);
      temp[1][i] = temp[1][i] * p[1] + (a[i][j] - 'a' + 1);
    }
  for (int j = 1; j <= n; j++)
    if (ch[0] == h[0][j] && ch[1] == h[1][j]) {
      printf("%d %d\n", 1, j - m + 1);
      return;
    }
  for (int i = m + 1; i <= n; i++) {
    ch[0] = ch[0] - temp[0][i - m] * pw[0][m * (m - 1)];
    ch[1] = ch[1] - temp[1][i - m] * pw[1][m * (m - 1)];
    for (int j = 1; j <= m; j++) {
      ch[0] = ch[0] * p[0] + (a[i][j] - 'a' + 1);
      ch[1] = ch[1] * p[1] + (a[i][j] - 'a' + 1);
      temp[0][i] = temp[0][i] * p[0] + (a[i][j] - 'a' + 1);
      temp[1][i] = temp[1][i] * p[1] + (a[i][j] - 'a' + 1);
    }
    for (int j = 1; j <= n; j++)
      if (ch[0] == h[0][j] && ch[1] == h[1][j]) {
        printf("%d %d\n", i - m + 1, j - m + 1);
        return;
      }
  }
}
int main() {
  read();
  initHash();
  solve();
}
