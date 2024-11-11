#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int inf = 1000000005;
const long long mod = 1000000007;
struct node {
  int x, y;
  int v;
} a[10000];
int b[10000];
int r[10000];
int c[100][100];
struct xxx {
  int a, b, c, d;
} x[10000];
bool cmp(node a, node b) { return a.v < b.v; }
int main() {
  int n, i, j;
  while (~scanf("%d", &n)) {
    for (i = 1; i <= n; ++i) {
      scanf("%d", &r[i]);
    }
    int tot = 0;
    for (i = 1; i <= n; ++i) {
      for (j = 1; j <= r[i]; ++j) {
        scanf("%d", &c[i][j]);
        a[tot].v = c[i][j];
        a[tot].x = i;
        a[tot++].y = j;
      }
    }
    sort(a, a + tot, cmp);
    int k = 0;
    int ans = 0;
    for (i = 1; i <= n; ++i) {
      for (j = 1; j <= r[i]; ++j) {
        if (a[k].v != c[i][j]) {
          x[ans].a = i;
          x[ans].b = j;
          x[ans].c = a[k].x;
          x[ans++].d = a[k].y;
          c[a[k].x][a[k].y] = c[i][j];
          for (int p = 0; p < tot; ++p) {
            if (a[p].v == c[i][j]) {
              a[p].x = a[k].x;
              a[p].y = a[k].y;
              break;
            }
          }
        }
        k++;
      }
    }
    printf("%d\n", ans);
    for (i = 0; i < ans; ++i) {
      printf("%d %d %d %d\n", x[i].a, x[i].b, x[i].c, x[i].d);
    }
  }
}
