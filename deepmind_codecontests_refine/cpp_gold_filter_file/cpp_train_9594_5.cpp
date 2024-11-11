#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, u[151], d[151], p, s = 0;
  char ch;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    u[i] = 0;
    d[i] = m + 1;
    getchar();
    for (int j = 1; j <= m; j++) {
      scanf("%c", &ch);
      if (ch == 'W') {
        if (j > u[i]) u[i] = j;
        if (j < d[i]) d[i] = j;
      }
    }
  }
  p = n;
  while (p >= 1 && !u[p]) p--;
  if (!p) {
    printf("0\n");
    return 0;
  }
  n = p;
  for (int i = 1; i <= n - 1; i++) {
    if (!u[i] && !u[i + 1]) continue;
    if (i & 1 && u[i + 1] > u[i])
      u[i] = u[i + 1];
    else if (!(i & 1) && d[i] > d[i + 1])
      d[i] = d[i + 1];
  }
  p = 1;
  for (int i = 1; i <= n - 1; i++) {
    if (i & 1 && u[i] > p) {
      s += u[i] - p;
      p = u[i];
    } else if (!(i & 1) && d[i] < p) {
      s += p - d[i];
      p = d[i];
    }
  }
  if (n & 1)
    s += u[n] - p;
  else
    s += p - d[n];
  printf("%d\n", s + n - 1);
  return 0;
}
