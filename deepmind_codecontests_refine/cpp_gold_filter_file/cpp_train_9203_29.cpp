#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int a, b, c, d;
  int mapp[5][4];
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= 4; i++) {
      scanf("%d %d %d %d", &a, &b, &c, &d);
      mapp[i][1] = min(a, b);
      mapp[i][2] = min(c, d);
      mapp[i][3] = mapp[i][1] + mapp[i][2];
    }
    int k;
    for (k = 1; k <= 4; k++) {
      if (mapp[k][3] <= n) break;
    }
    if (k != 5)
      printf("%d %d %d\n", k, mapp[k][1], n - mapp[k][1]);
    else
      printf("-1\n");
  }
  return 0;
}
