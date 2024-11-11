#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int N = 1e5 + 7;
struct line {
  int a, b, c, id;
} a[N][6];
int n, m, Res_X[6], Res_Y[6];
bool check(int x, int y, int k) {
  int A1 = a[x][k].a, B1 = a[x][k].b;
  int A2 = a[y][k].a, B2 = a[y][k].b;
  return A1 * B2 - B1 * A2;
}
long long Solve(line x, line y, line z) {
  long long a = 1ll * y.b * z.c - 1ll * y.c * z.b;
  long long b = 1ll * y.a * z.c - 1ll * y.c * z.a;
  long long c = 1ll * y.a * z.b - 1ll * y.b * z.a;
  return x.a * a - x.b * b + x.c * c;
}
void Dfs(int x, int y) {
  if (x + y <= m) {
    for (int i = y + 1; i <= x + y; i++) Res_X[i] = a[i][0].id, Res_Y[i] = -1;
    y += x;
    x = 0;
  }
  if (x == 0) {
    printf("YES\n%d\n", y);
    for (int i = 1; i <= y; i++) printf("%d %d\n", Res_X[i], Res_Y[i]);
    exit(0);
  }
  if (x == y) return;
  for (int flag = 3 * (m - y) * (m - y); flag; flag--) {
    int q = rand() % x + 1, p = rand() % x + 1;
    if (!check(q, p, y)) continue;
    double A1 = a[q][y].a, B1 = a[q][y].b, C1 = a[q][y].c;
    double A2 = a[p][y].a, B2 = a[p][y].b, C2 = a[p][y].c;
    int now = y;
    for (int i = 1; i <= x; i++) {
      if (i != p && i != q && Solve(a[q][y], a[p][y], a[i][y]))
        a[++now][y + 1] = a[i][y];
    }
    if (now > max(m - y - 1, x - x / (m - y))) continue;
    Res_X[y + 1] = a[q][y].id, Res_Y[y + 1] = a[p][y].id;
    Dfs(now, y + 1);
    if (x - now > m - y) return;
  }
}
int main() {
  srand(time(0));
  n = read(), m = read();
  for (int i = 1; i <= n; i++)
    a[i][0].a = read(), a[i][0].b = read(), a[i][0].c = read(), a[i][0].id = i;
  Dfs(n, 0);
  printf("NO\n");
  return 0;
}
