#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
struct node {
  int op, x, y, w;
} s[10010];
int a[maxn][maxn], b[maxn][maxn];
int r[maxn], c[maxn];
int main() {
  int n, m, q;
  while (scanf("%d %d %d", &n, &m, &q) != EOF) {
    memset(a, 0, sizeof(a));
    memset(c, 0, sizeof(c));
    memset(r, 0, sizeof(r));
    for (int i = 1; i <= q; i++) {
      scanf("%d", &s[i].op);
      if (s[i].op == 1 || s[i].op == 2) {
        scanf("%d", &s[i].x);
        s[i].x--;
      } else {
        scanf("%d %d %d", &s[i].x, &s[i].y, &s[i].w);
        s[i].x--;
        s[i].y--;
      }
    }
    int b[maxn];
    for (int i = q; i > 0; i--) {
      if (s[i].op == 1) {
        for (int j = 0; j < m; j++) b[(j + 1) % m] = a[s[i].x][j];
        for (int j = 0; j < m; j++) a[s[i].x][j] = b[j];
      } else if (s[i].op == 2) {
        for (int j = 0; j < n; j++) b[(j + 1) % m] = a[j][s[i].x];
        for (int j = 0; j < m; j++) a[j][s[i].x] = b[j];
      } else {
        a[s[i].x][s[i].y] = s[i].w;
      }
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        printf("%d%c", a[i][j], j == m - 1 ? '\n' : ' ');
  }
  return 0;
}
