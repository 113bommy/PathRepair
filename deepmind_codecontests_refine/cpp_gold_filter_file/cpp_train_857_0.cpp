#include <bits/stdc++.h>
using namespace std;
const int N = 70005;
struct node {
  int x, y;
} q[N];
int a[255][255], b[255][255];
bool r[N], c[N];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  for (int i = 1; i <= n; i++) {
    int mx = 0;
    for (int j = 1; j <= m; j++) mx = max(mx, a[i][j]);
    r[mx] = 1;
  }
  for (int i = 1; i <= m; i++) {
    int mx = 0;
    for (int j = 1; j <= n; j++) mx = max(mx, a[j][i]);
    c[mx] = 1;
  }
  int x = 0, y = 0, w = n * m, L = 1, R = 0;
  for (int i = n * m; i; i--) {
    x += r[i];
    y += c[i];
    if (!r[i] && !c[i]) {
      int ax = q[L].x, ay = q[L].y;
      ++L;
      b[ax][ay] = i;
    } else {
      b[x][y] = i;
      if (r[i])
        for (int j = y - 1; j; j--) q[++R] = (node){x, j};
      if (c[i])
        for (int j = x - 1; j; j--) q[++R] = (node){j, y};
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) printf("%d ", b[i][j]);
    puts("");
  }
  return 0;
}
