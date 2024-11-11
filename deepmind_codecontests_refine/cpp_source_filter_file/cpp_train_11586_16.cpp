#include <bits/stdc++.h>
using namespace std;
char s[111][111];
int d[111];
int main() {
  int n, m, k, i, j, t;
  cin >> n >> m >> k;
  int win[2] = {0, 0};
  for (i = t = 0; i < n; i++) {
    scanf("%s", s + i);
    int g[2] = {-1, -1}, r[2] = {-1, -1}, nn[2] = {0, 0};
    for (j = 0; j < m; j++) {
      if (s[i][j] == 'G') g[nn[0]++] = j;
      if (s[i][j] == 'R') r[nn[1]++] = j;
    }
    if (nn[0] == 2 && m > 2)
      win[0] = 1;
    else if (nn[1] == 2 && m > 2)
      win[1] = 1;
    else if (nn[0] == 1 && nn[1] == 0 && m > 1)
      win[0] = 1;
    else if (nn[1] == 1 && nn[0] == 0 && m > 1)
      win[1] = 1;
    else if (nn[1] && nn[0])
      d[t++] = abs(g[0] - r[0]);
  }
  if (win[0] && win[1]) return puts("Draw"), 0;
  if (win[0]) return puts("First"), 0;
  if (win[1]) return puts("Second"), 0;
  int ok = 0;
  for (i = 0; i < 10; i++) {
    int cnt = 0;
    for (j = 0; j < t; j++) {
      if (d[j] & (1 << i)) cnt++;
    }
    if (cnt % (k + 1)) ok = 1;
  }
  if (ok)
    puts("First");
  else
    puts("Second");
  return 0;
}
