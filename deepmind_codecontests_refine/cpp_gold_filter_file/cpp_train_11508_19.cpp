#include <bits/stdc++.h>
using namespace std;
int n, d, h, i, ans[500001][2];
int main() {
  scanf("%d%d%d", &n, &d, &h);
  if (h * 2 < d || n + 1 < d) return puts("-1"), 0;
  if (d == h) {
    if (h == 1 && n > 2) return puts("-1"), 0;
    for (i = 1; i <= h; i++) ans[i][0] = i, ans[i][1] = i + 1;
    n -= h + 1;
    while (n) {
      h++;
      n--;
      ans[h][0] = 2;
      ans[h][1] = h + 1;
    }
    for (i = 1; i <= h; i++) printf("%d %d\n", ans[i][0], ans[i][1]);
    return 0;
  }
  n -= d + 1;
  for (i = 1; i <= h; i++) ans[i][0] = i, ans[i][1] = i + 1;
  if (d > h) ans[h + 1][0] = 1;
  ans[h + 1][1] = h + 2;
  for (i = 2; i <= d - h; i++) ans[h + i][0] = h + i, ans[h + i][1] = h + i + 1;
  d = d + 1;
  while (n) {
    d++;
    n--;
    ans[d - 1][0] = 1;
    ans[d - 1][1] = d;
  }
  for (i = 1; i < d; i++) printf("%d %d\n", ans[i][0], ans[i][1]);
}
