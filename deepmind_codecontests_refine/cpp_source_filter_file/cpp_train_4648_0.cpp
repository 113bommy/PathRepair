#include <bits/stdc++.h>
using namespace std;
int a[1000005];
list<int> sq[601][101];
void apply(int bl, int id, int flag, int x, int y, int id2 = 0) {
  for (auto it = sq[bl][x].begin(); it != sq[bl][x].end();) {
    if ((flag == 1 && *it >= id) || (flag == 0 && *it <= id) ||
        (flag == 2 && *it >= id && *it <= id2)) {
      auto it2 = ++it;
      --it;
      sq[bl][y].splice(sq[bl][y].begin(), sq[bl][x], it);
      it = it2;
    } else {
      it++;
    }
  }
}
int main() {
  int i, j, k, l, m, n, t, r, cnt;
  int flag = 0;
  long long ans = 0, an = 0;
  t = 1;
  while (t--) {
    scanf("%d", &n);
    int fa = 401;
    for (i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      sq[i / fa][a[i]].push_back(i);
    }
    int q, x, y;
    scanf("%d", &q);
    while (q--) {
      scanf("%d", &l);
      scanf("%d", &r);
      scanf("%d", &x);
      scanf("%d", &y);
      if (x == y) continue;
      if (l / fa == r / fa) {
        apply(l / fa, l, 2, x, y, r);
      } else {
        apply(l / fa, l, 1, x, y);
        apply(r / fa, r, 0, x, y);
        for (i = l / fa + 1; i < r / fa; i++) {
          sq[i][y].splice(sq[i][y].begin(), sq[i][x]);
        }
      }
    }
    for (i = 0; i < 450; i++) {
      for (j = 0; j < 101; j++) {
        for (int it : sq[i][j]) {
          a[it] = j;
        }
      }
    }
    for (i = 1; i <= n; i++) {
      printf("%d ", a[i]);
    }
    printf("\n");
  }
}
