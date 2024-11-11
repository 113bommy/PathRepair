#include <bits/stdc++.h>
using namespace std;
int n, m;
char mmap[1010][1010];
int r[1010][1010], c[1010][1010];
int getr(int u, int a, int b) {
  if (a > b) return 0;
  return r[u][b] - r[u][a - 1];
}
int getc(int u, int a, int b) {
  if (a > b) return 0;
  return c[u][b] - c[u][a - 1];
}
int main() {
  while (scanf("%d %d", &n, &m) != EOF) {
    for (int i = 1; i <= n; i++) scanf("%s", mmap[i] + 1);
    memset(r, 0, sizeof(r));
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        if (mmap[i][j] == '*') {
          r[i][j] = 1 + r[i][j - 1];
          c[j][i] = 1 + c[j][i - 1];
        } else {
          r[i][j] = r[i][j - 1];
          c[j][i] = c[j][i - 1];
        }
      }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (mmap[i][j] == '*') {
          int a = getr(i, 1, j - 1);
          int b = getr(i, j + 1, m);
          int c = getc(j, 1, i - 1);
          int d = getc(j, i + 1, n);
          ans += 1LL * a * c + 1LL * a * d + 1LL * d * b + 1LL * b * c;
        }
    cout << ans << endl;
  }
  return 0;
}
