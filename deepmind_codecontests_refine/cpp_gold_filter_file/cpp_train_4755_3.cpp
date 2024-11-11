#include <bits/stdc++.h>
using namespace std;
int a[5][55];
int n, k;
int tot;
struct node {
  int id, x, y;
  node(int a = 0, int b = 0, int c = 0) { id = a, x = b, y = c; }
};
node ans[20005];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= 4; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
  int cnt = 0, sum = 0;
  int nx = 2, ny = 1;
  while (cnt <= 20000 && sum != k) {
    int tx = nx, ty, gx, gy;
    nx == 2 ? ty = ny + 1 : ty = ny - 1;
    if (ty > n) {
      tx++, ty--;
    }
    if (ty < 1) {
      tx--, ty++;
    }
    gy = ty;
    tx == 2 ? gx = 1 : gx = 4;
    if (a[tx][ty]) {
      if (a[tx][ty] == a[gx][gy])
        ans[++tot] = node(a[gx][gy], gx, gy), sum++, a[tx][ty] = 0;
      else if (!a[nx][ny])
        ans[++tot] = node(a[tx][ty], nx, ny), swap(a[nx][ny], a[tx][ty]);
    }
    cnt++;
    nx = tx, ny = ty;
  }
  if (sum == k) {
    cout << tot << endl;
    for (int i = 1; i <= tot; i++)
      cout << ans[i].id << " " << ans[i].x << " " << ans[i].y << endl;
  } else
    cout << "-1" << endl;
}
