#include <bits/stdc++.h>
using namespace std;
int a[20][100];
int b[20][100];
int c[20][100];
int vis[200];
int n, m, k;
int getMoney(int x, int y) {
  memset(vis, sizeof(vis), 0);
  int last = k, i, j;
  int sum = 0;
  while (last) {
    int flag = 1;
    int maxc = 0;
    int maxm = 0;
    for (i = 0; i < m; i++) {
      if (vis[i]) continue;
      if (b[y][i] - a[x][i] > maxm) {
        maxm = b[y][i] - a[x][i];
        maxc = i;
        flag = 0;
      }
    }
    if (flag) break;
    int num = min(last, c[x][maxc]);
    sum += num * maxm;
    last -= num;
    vis[maxc] = 1;
  }
  return sum;
}
int main() {
  int i, j;
  int sum = 0;
  scanf("%d%d%d", &n, &m, &k);
  for (i = 0; i < n; i++) {
    char str[1000];
    scanf("%s", str);
    for (j = 0; j < m; j++) scanf("%d%d%d", &a[i][j], &b[i][j], &c[i][j]);
  }
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) sum = max(sum, getMoney(i, j));
  printf("%d", sum);
}
