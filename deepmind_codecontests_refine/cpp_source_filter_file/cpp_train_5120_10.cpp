#include <bits/stdc++.h>
using namespace std;
const int N = 110;
const int M = 1e5 + 10;
struct node {
  int x, y;
} a[N], b[N];
int n, m, f[N][M];
int cnt1, cnt2, ans;
bool cmp(node x, node y) { return x.x < y.x; }
bool ys(node x, node y) { return x.x + x.y > y.x + y.y; }
int max_(int x, int y) { return x > y ? x : y; }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (y > 0)
      a[++cnt1] = (node){x, y};
    else
      b[++cnt2] = (node){x, y};
  }
  sort(a + 1, a + cnt1 + 1, cmp);
  for (int i = 1; i <= cnt1; i++) {
    if (m >= a[i].x)
      m += a[i].y, ans++;
    else
      break;
  }
  sort(b + 1, b + cnt2 + 1, ys);
  for (int i = 1; i <= cnt2; i++)
    if (m >= b[i].x && m + b[i].y >= 0) {
      f[i][m + b[i].y] = 1;
      for (int j = i - 1; j >= 1; j--)
        for (int k = max_(-b[i].y, b[i].x); k < N; k++)
          if (f[j][k]) f[i][k + b[i].y] = max_(f[i][k + b[i].y], f[j][k] + 1);
    }
  int jys = 0;
  for (int i = 1; i <= cnt2; i++)
    for (int j = 0; j < M; j++) jys = max_(jys, f[i][j]);
  printf("%d", ans + jys);
  return 0;
}
