#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, totl, quest, x, y, ant, cnt;
  int p[15][15];
  scanf("%d%d%d%d", &m, &n, &totl, &quest);
  memset(p, 0, sizeof(p));
  for (int i = 1; i <= totl; i++) {
    scanf("%d%d", &x, &y);
    p[x][y] = 1;
  }
  ant = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      for (int a = n; a >= i; a--)
        for (int b = m; b >= j; b--) {
          cnt = 0;
          for (int q = i; q <= a; q++)
            for (int w = j; w <= b; w++) cnt += p[q][w];
          if (cnt >= quest) ant++;
        }
  printf("%d\n", ant);
  return 0;
}
