#include <bits/stdc++.h>
using namespace std;
const int N = 410, M = N * N;
int n, m, l, p[N], mx[2], num[N], numb[N];
char c[N], st[N], res[N];
int e[N][N], now[N], tmp[N];
void Pre_work() {
  for (int k = 1; k <= n + n; ++k)
    for (int i = 1; i <= n + n; ++i)
      for (int j = 1; j <= n + n; ++j) e[i][j] |= (e[i][k] & e[k][j]);
}
int f(int k, int q) {
  for (int i = q + 1; i < l; ++i)
    if (p[i] == k) return i;
  return l;
}
int check(int id, int k) {
  for (int i = 1; i <= n + n; ++i) tmp[i] = now[i];
  int o = id + num[p[res[id]]];
  tmp[o] = 1;
  for (int i = 1; i <= n + n; ++i) tmp[i] |= e[o][i];
  for (int i = 1; i <= n; ++i)
    if (tmp[i] && tmp[n + i]) return 0;
  if (k) {
    for (int i = id + 1; i <= n; ++i) {
      if (tmp[i]) {
        if (mx[0] < st[i]) return 0;
        if (mx[0] > st[i]) break;
      } else if (tmp[n + i]) {
        if (mx[1] < st[i]) return 0;
        if (mx[1] > st[i]) break;
      } else if (st[i] != l - 1)
        break;
    }
  }
  for (int i = 1; i <= n + n; ++i) now[i] = tmp[i];
  return 1;
}
signed main() {
  scanf("%s %d %d", c, &n, &m);
  l = strlen(c);
  mx[0] = mx[1] = -1;
  num['V'] = num[1] = n;
  numb['C'] = n;
  for (int i = 0; i < l; ++i) p[i] = (c[i] == 'V'), mx[p[i]] = i;
  for (int i = 1, x, y; i <= m; ++i) {
    char a[2], b[2];
    scanf("%d %s %d %s", &x, a, &y, b);
    e[x + num[a[0]]][y + num[b[0]]] = 1;
    e[y + numb[b[0]]][x + numb[a[0]]] = 1;
  }
  Pre_work();
  scanf("%s", st + 1);
  int qwq = 1;
  for (int i = 1; i <= n; ++i) st[i] -= 'a';
  for (int i = 1; i <= n; ++i) {
    if (qwq) {
      res[i] = st[i];
      if (check(i, 1)) continue;
      qwq = 0;
      int a = f(0, st[i]), b = f(1, st[i]);
      if (a > b) swap(a, b);
      if (a < l) {
        res[i] = a;
        if (check(i, 0)) continue;
      }
      if (b < l) {
        res[i] = b;
        if (check(i, 0)) continue;
      }
    } else {
      int a = f(0, -1), b = f(1, -1);
      if (a > b) swap(a, b);
      if (a < l) {
        res[i] = a;
        if (check(i, 0)) continue;
      }
      if (b < l) {
        res[i] = b;
        if (check(i, 0)) continue;
      }
    }
    return puts("-1"), 0;
  }
  for (int i = 1; i <= n; ++i) putchar(res[i] + 'a');
  return putchar('\n'), 0;
}
