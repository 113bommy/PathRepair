#include <bits/stdc++.h>
using namespace std;
int n, d, m;
int xx[4], yy[4];
int main() {
  scanf("%d%d%d", &n, &d, &m);
  xx[0] = 0, xx[1] = d, xx[2] = n, xx[3] = n - d;
  yy[0] = d, yy[1] = 0, yy[2] = n - d, yy[3] = n;
  while (m--) {
    int x, y;
    scanf("%d%d", &x, &y);
    int pre = 1;
    bool ok = 1;
    for (int i = 0; i < 4; i++) {
      int a = xx[(i + 1) % 4] - xx[i], b = yy[(i + 1) % 4] - yy[i];
      int c = x - xx[i], d = y - yy[i];
      int res = a * d - b * c;
      if (i) pre = res * pre;
      if (pre < 0) ok = 0;
      pre = res;
    }
    if (ok)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
