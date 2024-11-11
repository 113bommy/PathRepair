#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, now, d[2], w[2], a[110][10010];
long long ans;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (j == 1) getchar();
      switch (getchar()) {
        case '.':
          break;
        case '+':
          a[i][j] = 1;
          break;
        case '#':
          a[i][j] = 2;
          break;
      }
    }
  }
  d[0] = 1, d[1] = -1;
  x = y = w[0] = w[1] = 1;
  for (int T = 2000000; T; --T) {
    if (x == n) {
      printf("%I64d\n", ans);
      return 0;
    }
    if (!a[x + 1][y])
      ++x, w[0] = w[1] = y;
    else if (y == w[now])
      if ((1 <= y + d[now]) && (y + d[now] <= m) && (a[x][y + d[now]] < 2)) {
        w[now] += d[now];
        if (!a[x][y + d[now]])
          y += d[now];
        else
          now ^= 1;
      } else
        now ^= 1;
    else {
      ans += (long long)abs(w[now] - y) - 1;
      y = w[now];
    }
    ++ans;
  }
  printf("Never\n");
  return 0;
}
