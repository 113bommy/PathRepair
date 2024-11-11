#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, ans[1000010], d[110][110], p[1000010], dis;
bool a[110][110];
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -f;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    char ch[110];
    scanf("%s", ch + 1);
    for (int j = 1; j <= n; j++)
      a[i][j] = ch[j] - '0', d[i][j] = a[i][j] == 1 ? 1 : 0x3f3f3f3f;
  }
  m = read();
  for (int i = 1; i <= n; i++) d[i][i] = 0;
  for (int i = 1; i <= m; i++) p[i] = read();
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        if (d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];
      }
  ans[++cnt] = p[1];
  for (int i = 2; i <= m; i++) {
    dis += d[p[i - 1]][p[i]];
    if (dis > d[ans[cnt]][p[i]]) {
      ans[++cnt] = p[i - 1];
      dis = d[p[i - 1]][p[i]];
    }
  }
  ans[++cnt] = p[m];
  printf("%d\n", cnt);
  for (int i = 1; i <= cnt; i++) printf("%d ", ans[i]);
  return 0;
}
