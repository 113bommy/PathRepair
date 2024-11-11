#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[107][107];
int b[107][107];
int main() {
  int m, p;
  scanf("%d %d", &m, &p);
  int i, j;
  for (i = 1; i <= m; i++)
    for (j = 1; j <= p; j++) a[i][j].first = i, a[i][j].second = j;
  int q;
  scanf("%d", &q);
  while (q--) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int tem;
      scanf("%d", &tem);
      pair<int, int> temp = a[tem][1];
      for (i = 1; i < p; i++) a[tem][i] = a[tem][i + 1];
      a[tem][p] = temp;
    } else if (type == 2) {
      int tem;
      scanf("%d", &tem);
      pair<int, int> temp = a[1][tem];
      for (i = 1; i < m; i++) a[i][tem] = a[i + 1][tem];
      a[m][tem] = temp;
    } else {
      int aa, bb;
      int tem;
      scanf("%d %d %d", &aa, &bb, &tem);
      b[a[aa][bb].first][a[aa][bb].second] = tem;
    }
  }
  for (i = 1; i <= m; i++) {
    for (j = 1; j <= p; j++) printf("%d ", b[i][j]);
    printf("\n");
  }
  return 0;
}
