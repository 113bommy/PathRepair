#include <bits/stdc++.h>
using namespace std;
const int N = 110010;
bitset<4096> g[N];
int n, k, q, a[13][N];
int qx[N], qy[N];
int now;
bool cmp(int x, int y) { return a[x][now] < a[y][now]; }
int main() {
  scanf("%d%d%d", &n, &k, &q);
  for (int i = 1; i <= k; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
  int op, x, y, cnt = 0, tot = k, up = 1 << k;
  for (int i = 0; i < up; i++)
    for (int j = 1; j <= k; j++)
      if (i >> j - 1 & 1) g[j].set(i);
  while (q--) {
    scanf("%d%d%d", &op, &x, &y);
    if (op == 1)
      g[++tot] = g[x] | g[y];
    else if (op == 2)
      g[++tot] = g[x] & g[y];
    else
      qx[++cnt] = x, qy[cnt] = y;
  }
  int tmp[13], tmp2, last;
  for (int i = 1; i <= k; i++) tmp[i] = i;
  for (int i = 1; i <= cnt; i++) {
    now = qy[i];
    sort(tmp + 1, tmp + k + 1, cmp);
    tmp2 = up - 1;
    for (int j = 1; j <= k; j++) {
      last = g[qx[i]][tmp2];
      tmp2 -= 1 << tmp[j] - 1;
      if (last != g[qx[i]][tmp2]) {
        printf("%d\n", a[tmp[j]][now]);
        break;
      }
    }
  }
  return 0;
}
