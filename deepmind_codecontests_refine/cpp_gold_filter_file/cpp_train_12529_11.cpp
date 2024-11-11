#include <bits/stdc++.h>
using namespace std;
int a, b, cnt, d, n;
int up[110], w[110];
struct pp {
  int d, id;
};
bool com(pp a, pp b) { return a.d < b.d; }
pp x[110];
pp y[110];
inline int scan(int x) {
  if (up[x] == x) return x;
  up[x] = scan(up[x]);
  return up[x];
}
int main() {
  scanf("%d", &n);
  cnt = n - 1;
  for (a = 1; a <= n; a++)
    scanf("%d%d", &x[a].d, &y[a].d), x[a].id = y[a].id = a;
  sort(x + 1, x + 1 + n, com);
  sort(y + 1, y + 1 + n, com);
  for (a = 1; a <= n; a++) w[a] = 1, up[a] = a;
  for (a = 1; a < n; a++)
    if (x[a].d == x[a + 1].d)
      if (scan(x[a].id) != scan(x[a + 1].id)) {
        cnt--;
        int v1, v2;
        v1 = up[x[a].id];
        v2 = up[x[a + 1].id];
        if (w[v1] > w[v2])
          w[v1] += w[v2], up[v2] = v1;
        else
          w[v2] += w[v1], up[v1] = v2;
      }
  for (a = 1; a < n; a++)
    if (y[a].d == y[a + 1].d)
      if (scan(y[a].id) != scan(y[a + 1].id)) {
        cnt--;
        int v1, v2;
        v1 = up[y[a].id];
        v2 = up[y[a + 1].id];
        if (w[v1] > w[v2])
          w[v1] += w[v2], up[v2] = v1;
        else
          w[v2] += w[v1], up[v1] = v2;
      }
  printf("%d\n", cnt);
}
