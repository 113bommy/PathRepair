#include <bits/stdc++.h>
using namespace std;
int father[600005];
int size[600005];
int val[3005][6005];
int visit[600005];
int a[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {1, -1},
               {1, 0},   {1, 1},  {0, -1}, {0, 1}};
int findroot(int x) {
  int root = x;
  for (; father[root] != -1; root = father[root])
    ;
  for (; father[x] != -1;) {
    int temp = father[x];
    father[x] = root;
    x = temp;
  }
  return root;
}
void u(int x, int y) {
  if (x == -1) return;
  if (y == -1) return;
  x = findroot(x);
  y = findroot(y);
  if (x == y) return;
  if (size[x] > size[y]) swap(x, y);
  father[x] = y;
  size[y] += size[x];
}
int n, m, k;
bool check(int x, int y) {
  static int tot = 0;
  tot++;
  int j;
  for (j = 0; j < 8; j++) {
    int tx = x + a[j][0];
    int ty = y + a[j][1];
    if (ty < 0) ty += m + m;
    if ((tx < 0) || (tx >= n)) continue;
    if (val[tx][ty] == -1) continue;
    visit[findroot(val[tx][ty])] = tot;
  }
  for (j = 0; j < 8; j++) {
    int tx = x + a[j][0];
    int ty = y + m + a[j][1];
    if (ty >= m + m) ty -= m + m;
    if ((tx < 0) || (tx >= n)) continue;
    if (val[tx][ty] == -1) continue;
    if (visit[findroot(val[tx][ty])] == tot) return false;
  }
  return true;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  if (m == 1) {
    printf("0\n");
    return 0;
  }
  int i;
  for (i = 0; i < k + k; i++) {
    father[i] = -1;
    size[i] = 1;
  }
  memset(val, -1, sizeof(val));
  int ans = 0;
  for (i = 0; i < k; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    if (check(x, y)) {
      ans++;
      val[x][y] = i;
      int j;
      for (j = 0; j < 8; j++) {
        int tx = x + a[j][0];
        int ty = y + a[j][1];
        if ((tx < 0) || (tx >= n)) continue;
        if (ty < 0) ty += (m << 1);
        u(i, val[tx][ty]);
      }
      val[x][y + m] = i + k;
      for (j = 0; j < 8; j++) {
        int tx = x + a[j][0];
        int ty = y + m + a[j][1];
        if ((tx < 0) || (tx >= n)) continue;
        if (ty > m + m) ty -= (m << 1);
        u(i + k, val[tx][ty]);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
