#include <bits/stdc++.h>
using namespace std;
struct aaa {
  int x, y;
} b[100010];
int ans, n, m, i, j, sz, ha[2][2010][2010], li[2][2010][2010], a[2010][2010];
bool cmp(aaa a, aaa b) { return a.x > b.x; }
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) b[j].x = a[i][j], b[j].y = j;
    sort(b + 1, b + m + 1, cmp);
    sz = 0;
    for (j = 1; j <= m; j++) {
      if (j == 1 || b[j].x != b[j - 1].x) sz++;
      ha[0][i][b[j].y] = sz - 1;
    }
    sz = 0;
    for (j = m; j; j--) {
      if (j == m || b[j].x != b[j + 1].x) sz++;
      ha[1][i][b[j].y] = sz - 1;
    }
  }
  for (j = 1; j <= m; j++) {
    for (i = 1; i <= n; i++) b[i].x = a[i][j], b[i].y = i;
    sort(b + 1, b + n + 1, cmp);
    sz = 0;
    for (i = 1; i <= n; i++) {
      if (j == 1 || b[j].x != b[j - 1].x) sz++;
      li[0][b[i].y][j] = sz - 1;
    }
    sz = 0;
    for (i = n; i; i--) {
      if (i == n || b[j].x != b[j + 1].x) sz++;
      li[1][b[i].y][j] = sz - 1;
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      ans = max(ha[0][i][j], li[0][i][j]) + max(li[1][i][j], ha[1][i][j]);
      printf("%d ", ans + 1);
    }
    puts("");
  }
}
