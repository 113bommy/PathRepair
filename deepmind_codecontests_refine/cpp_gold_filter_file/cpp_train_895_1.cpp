#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int node[15][N + 5];
int n, k, q;
struct Ele {
  int x, y, com = 0;
} ele[N + 15];
int findd(int x, int y) {
  if (x <= k) return node[x][y];
  int t1, t2;
  t1 = findd(ele[x].x, y);
  t2 = findd(ele[x].y, y);
  if (ele[x].com == 1)
    return max(t1, t2);
  else
    return min(t1, t2);
}
int main() {
  while (scanf("%d%d%d", &n, &k, &q) != EOF) {
    memset(node, 0, sizeof node);
    for (int i = 1; i <= k; i++)
      for (int j = 1; j <= n; j++) scanf("%d", &node[i][j]);
    int com, x, y, cnt = k + 1;
    for (int i = 1; i <= q; i++) {
      scanf("%d%d%d", &com, &x, &y);
      if (com == 1) {
        ele[cnt].x = x, ele[cnt].y = y, ele[cnt++].com = com;
      } else if (com == 2) {
        ele[cnt].x = x, ele[cnt].y = y, ele[cnt++].com = com;
      } else {
        printf("%d\n", findd(x, y));
      }
    }
  }
  return 0;
}
