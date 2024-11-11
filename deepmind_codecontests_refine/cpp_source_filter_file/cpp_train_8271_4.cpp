#include <bits/stdc++.h>
using namespace std;
const int N = 4010;
struct Data {
  int c, h, t, id;
} a[N];
int f[N][N], g[N][N];
bool operator<(const Data &a, const Data &b) { return a.t < b.t; }
int main() {
  int n, m, p;
  scanf("%d%d", &n, &p);
  for (int i = 1; i < n; i++) {
    scanf("%d%d%d", &a[i].c, &a[i].h, &a[i].t);
    a[i].id = a[i].t / p;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i < n; i++)
    if (a[i].id > a[i - 1].id)
      for (int j = a[i].c; j < N - 1; j++) f[i][j] = a[i].h;
    else {
      memcpy(f[i], f[i - 1], sizeof(f[i]));
      for (int j = N - 1; j >= a[i].c; j--)
        f[i][j] = max(f[i][j], f[i - 1][j - a[i].c] + a[i].h);
    }
  for (int i = n; i; i--)
    if (i == n || a[i].id < a[i + 1].id)
      for (int j = a[i].c; j < N - 1; j++) g[i][j] = a[i].h;
    else {
      memcpy(g[i], g[i + 1], sizeof(g[i]));
      for (int j = N - 1; j >= a[i].c; j--)
        g[i][j] = max(g[i][j], g[i + 1][j - a[i].c] + a[i].h);
    }
  scanf("%d", &m);
  for (int i = 1; i < m; i++) {
    int x, y, l = 0, r = 0, an = 0;
    scanf("%d%d", &x, &y);
    for (int j = 1; j < n; j++)
      if (a[j].t <= x && a[j].t + p > x) {
        if (!l) l = j;
        r = j;
      }
    if (a[l].id == a[r].id) {
      if (r < n && a[r + 1].id == a[r].id)
        l = 0;
      else
        r = 0;
    }
    for (int j = 0; j < y; j++) an = max(an, f[r][j] + g[l][y - j]);
    printf("%d\n", an);
  }
  return 0;
}
