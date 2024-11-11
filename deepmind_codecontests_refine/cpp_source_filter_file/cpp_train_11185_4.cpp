#include <bits/stdc++.h>
using namespace std;
int i, j, a[1111][1111], k, task, y, x, a1[1111][1111], a2[1111][1111],
    a3[1111][1111], a4[1111][1111], g[1111], f[1111][1111], l[1111], r[1111], n,
    m, head, tail, q[1111], ans;
char c;
void get() {
  for (i = 1; i <= n; i++) g[i] = a4[i][y];
  head = tail = 1;
  q[1] = 1;
  for (j = 2; j <= m; j++) {
    for (; head <= tail && g[j] < g[q[tail]]; tail--) r[q[tail]] = j - 1;
    q[++tail] = j;
  }
  for (j = head; j <= tail; j++) r[q[j]] = n;
  head = tail = 1;
  q[1] = n;
  for (j = n - 1; j; j--) {
    for (; head <= tail && g[j] < g[q[tail]]; tail--) l[q[tail]] = j + 1;
    q[++tail] = j;
  }
  for (j = head; j <= tail; j++) l[q[j]] = 1;
  ans = max(g[y] * (r[y] - l[y] + 1), ans);
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) a1[i][j] = a[i][j] * (a1[i - 1][j] + 1);
  for (i = n; i; i--)
    for (j = 1; j <= m; j++) a2[i][j] = a[i][j] * (a2[i + 1][j] + 1);
  for (j = 1; j <= m; j++)
    for (i = 1; i <= n; i++) a3[i][j] = a[i][j] * (a3[i][j - 1] + 1);
  for (j = m; j; j--)
    for (i = 1; i <= n; i++) a4[i][j] = a[i][j] * (a4[i][j + 1] + 1);
  for (; k--;) {
    scanf("%d%d%d", &task, &x, &y);
    if (task == 1) {
      a[x][y] ^= 1;
      j = y;
      for (i = 1; i <= n; i++) a1[i][j] = a[i][j] * (a1[i - 1][j] + 1);
      j = y;
      for (i = n; i; i--) a2[i][j] = a[i][j] * (a2[i + 1][j] + 1);
      i = x;
      for (j = 1; j <= m; j++) a3[i][j] = a[i][j] * (a3[i][j - 1] + 1);
      i = x;
      for (j = m; j; j--) a4[i][j] = a[i][j] * (a4[i][j + 1] + 1);
    } else {
      ans = 0;
      for (j = 1; j <= m; j++) g[j] = a1[x][j];
      head = tail = 1;
      q[1] = 1;
      for (j = 2; j <= m; j++) {
        for (; head <= tail && g[j] < g[q[tail]]; tail--) r[q[tail]] = j - 1;
        q[++tail] = j;
      }
      for (j = head; j <= tail; j++) r[q[j]] = m;
      head = tail = 1;
      q[1] = m;
      for (j = m - 1; j; j--) {
        for (; head <= tail && g[j] < g[q[tail]]; tail--) l[q[tail]] = j + 1;
        q[++tail] = j;
      }
      for (j = head; j <= tail; j++) l[q[j]] = 1;
      for (i = 1; i <= m; i++)
        if (l[i] <= y && y <= r[i]) ans = max(ans, g[i] * (r[i] - l[i] + 1));
      for (j = 1; j <= m; j++) g[j] = a2[x][j];
      head = tail = 1;
      q[1] = 1;
      for (j = 2; j <= m; j++) {
        for (; head <= tail && g[j] < g[q[tail]]; tail--) r[q[tail]] = j - 1;
        q[++tail] = j;
      }
      for (j = head; j <= tail; j++) r[q[j]] = m;
      head = tail = 1;
      q[1] = m;
      for (j = m - 1; j; j--) {
        for (; head <= tail && g[j] < g[q[tail]]; tail--) l[q[tail]] = j + 1;
        q[++tail] = j;
      }
      for (j = head; j <= tail; j++) l[q[j]] = 1;
      for (i = 1; i <= m; i++)
        if (l[i] <= y && y <= r[i]) ans = max(ans, g[i] * (r[i] - l[i] + 1));
      for (i = 1; i <= n; i++) g[i] = a3[i][y];
      head = tail = 1;
      q[1] = 1;
      for (j = 2; j <= m; j++) {
        for (; head <= tail && g[j] < g[q[tail]]; tail--) r[q[tail]] = j - 1;
        q[++tail] = j;
      }
      for (j = head; j <= tail; j++) r[q[j]] = n;
      head = tail = 1;
      q[1] = n;
      for (j = n - 1; j; j--) {
        for (; head <= tail && g[j] < g[q[tail]]; tail--) l[q[tail]] = j + 1;
        q[++tail] = j;
      }
      for (j = head; j <= tail; j++) l[q[j]] = 1;
      for (i = 1; i <= n; i++)
        if (l[i] <= x && x <= r[i]) ans = max(ans, g[i] * (r[i] - l[i] + 1));
      for (i = 1; i <= n; i++) g[i] = a4[i][y];
      head = tail = 1;
      q[1] = 1;
      for (j = 2; j <= m; j++) {
        for (; head <= tail && g[j] < g[q[tail]]; tail--) r[q[tail]] = j - 1;
        q[++tail] = j;
      }
      for (j = head; j <= tail; j++) r[q[j]] = n;
      head = tail = 1;
      q[1] = n;
      for (j = n - 1; j; j--) {
        for (; head <= tail && g[j] < g[q[tail]]; tail--) l[q[tail]] = j + 1;
        q[++tail] = j;
      }
      for (j = head; j <= tail; j++) l[q[j]] = 1;
      for (i = 1; i <= n; i++)
        if (l[i] <= x && x <= r[i]) ans = max(ans, g[i] * (r[i] - l[i] + 1));
      printf("%d\n", ans);
    }
  }
}
