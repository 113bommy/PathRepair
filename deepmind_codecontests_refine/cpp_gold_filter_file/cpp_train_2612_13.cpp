#include <bits/stdc++.h>
using namespace std;
int t, a[1000006];
int num[1000006];
int main() {
  scanf("%d", &t);
  int pos = 0;
  for (int i = 1; i <= t; i++) {
    int num;
    scanf("%d", &num);
    a[num]++, pos = max(pos, num);
  }
  int n, m, x, y;
  for (int i = 1; i <= t; i++)
    if (a[i] != 4 * i) {
      x = i;
      break;
    }
  int flag = 0;
  for (int i = 1; i <= t && !flag; i++) {
    if (t % i) continue;
    n = i, m = t / i;
    y = n + m - x - pos;
    memset(num, 0, sizeof(num));
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= m; k++) num[abs(x - j) + abs(y - k)]++;
    flag = 1;
    for (int j = 0; j <= pos; j++)
      if (a[j] != num[j]) flag = 0;
  }
  if (!flag) return 0 * puts("-1");
  printf("%d %d\n%d %d\n", n, m, x, y);
  return 0;
}
