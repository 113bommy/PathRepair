#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int vis[MAXN], is[MAXN], num[MAXN];
struct operat {
  int k, x;
} f[MAXN];
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  memset(is, 0, sizeof(is));
  char ch;
  int x;
  for (int i = 1; i <= m; i++) {
    cin >> ch >> f[i].x;
    if (ch == '+')
      f[i].k = 1;
    else
      f[i].k = 0;
  }
  memset(vis, 0, sizeof(vis));
  int in = 0, out = 0;
  for (int i = 1; i <= m; i++) {
    if (!f[i].k && !vis[f[i].x]) {
      if (in) is[f[i].x] = 1;
      vis[f[i].x]++;
    } else if (f[i].k && !vis[f[i].x]) {
      if (i > 1) is[f[i].x] = 1;
      vis[f[i].x] = 1;
      in++;
    } else if (!f[i].k && vis[f[i].x]) {
      if (in > 1) is[f[i].x] = 1;
      vis[f[i].x]++;
      in--;
    } else if (f[i].k && vis[f[i].x]) {
      if (!(f[i - 1].k == 0 && f[i - 1].x == f[i].x)) is[f[i].x] = 1;
      vis[f[i].x]++;
      in++;
    }
  }
  out = 0;
  in = 0;
  memset(vis, 0, sizeof(vis));
  for (int i = m; i > 0; i--) {
    if (f[i].k == 1 && !vis[f[i].x]) {
      if (out) is[f[i].x] = 1;
      vis[f[i].x]++;
    } else if (f[i].k == 0 && !vis[f[i].x]) {
      if (i < m) is[f[i].x] = 1;
      out++;
      vis[f[i].x]++;
    } else if (f[i].k == 1 && vis[f[i].x]) {
      if (out - 1 > 0) is[f[i].x] = 1;
      vis[f[i].x]++;
      out--;
    } else if (f[i].k == 0 && vis[f[i].x]) {
      if (!(f[i + 1].k == 1 && f[i + 1].x == f[i].x)) is[f[i].x] = 1;
      vis[f[i].x]++;
      out++;
    }
  }
  int res = 0, p = 0;
  for (int i = 1; i <= n; i++)
    if (!is[i]) res++;
  printf("%d\n", res);
  for (int i = 1; i <= n; i++) {
    if (p < res - 1 && !is[i]) {
      printf("%d ", i);
      p++;
    } else if (p == res - 1 && !is[i]) {
      printf("%d\n", i);
      p++;
    }
  }
  return 0;
}
