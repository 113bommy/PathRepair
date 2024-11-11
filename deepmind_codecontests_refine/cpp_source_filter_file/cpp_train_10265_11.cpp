#include <bits/stdc++.h>
using namespace std;
char b[150][150];
int n, m;
int d[150][150];
int last;
int f(int r, int c) {
  if (r < 0 || r < last) return 0;
  if (d[r][c] >= 0) return d[r][c];
  int ll = -1, rr = -1;
  for (int i = 0; i < m; i++) {
    if (b[r][i] == '1') {
      ll = i;
      break;
    }
  }
  for (int i = m - 1; i >= 0; i--) {
    if (b[r][i] == '1') {
      rr = i;
      break;
    }
  }
  if (ll < 0) return d[r][c] = f(r - 1, c) + 1;
  if (r == 0 || r == last) {
    if (c == 0)
      return d[r][c] = rr;
    else
      return d[r][c] = m - 1 - ll;
  }
  if (c == 0) {
    return d[r][c] = min(f(r - 1, 0) + 2 * (rr - 1) + 1, f(r - 1, m - 1) + m);
  } else {
    return d[r][c] =
               min(f(r - 1, m - 1) + 2 * (m - 1 - ll) + 1, f(r - 1, 0) + m);
  }
}
int main() {
  scanf("%d %d", &n, &m);
  m += 2;
  for (int i = 0; i < n; i++) scanf("%s", b[i]);
  last = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (b[i][j] == '1') {
        last = i;
        break;
      }
    }
    if (last >= 0) break;
  }
  if (last < 0) {
    puts("0");
    return 0;
  }
  memset(d, -1, sizeof(d));
  printf("%d\n", f(n - 1, 0));
  return 0;
}
