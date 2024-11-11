#include <bits/stdc++.h>
using namespace std;
int m, n, a[2000100], b[2000100], d[2000100], ans = 1, pos[2000100];
int between(int x, int y, int z) {
  if (z < y) return x < z || x > y;
  return x > y && x < z;
}
int main() {
  memset(d, -1, sizeof(d));
  cin >> m >> n;
  for (int i = 0; i < m; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]), d[b[i]] = i;
  int M = 0;
  for (int i = 0; i < m; i++)
    if (d[a[i]] >= 0) a[M] = a[i], pos[M++] = i;
  swap(m, M);
  if (!m) {
    puts("0");
    return 0;
  }
  for (int i = 0; i < m; i++) a[m + i] = a[i], pos[m + i] = pos[i] + M;
  int x = 1, bor = 0;
  for (int i = 1; i <= m * 2 - 1; i++)
    if (pos[i] == pos[i - 1] + 1) {
      x++;
      while (x > 2 && !between(d[a[i]], d[a[i - 1]], d[a[bor]])) bor++, x--;
      ans = max(ans, x);
    } else
      x = 1, bor = i;
  cout << min(m, ans) << endl;
}
