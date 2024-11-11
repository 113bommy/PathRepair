#include <bits/stdc++.h>
using namespace std;
int f[256], d[256];
int find(int v) { return v == f[v] ? v : f[v] = find(f[v]); }
int main() {
  for (int i = 0; i < 256; i++) d[i] = 1;
  for (int i = 0; i < 256; i++) f[i] = i;
  int n, m;
  scanf("%d%d", &n, &m);
  int x, y, st, et, sum;
  for (int i = 0; i < n; i++) {
    scanf("%d", &y);
    if (y > 0 && f[y] == y && d[y] < m) {
      sum = d[y];
      x = find(y - 1);
      while (d[x] + sum <= m) {
        sum += d[x];
        if (x == 0) break;
        x = find(x - 1);
      }
      int st = y + d[y] - sum;
      int et = y + d[y] - 1;
      for (int j = st; j <= et; j++) {
        f[j] = st;
        d[j] = d[st];
      }
    }
    printf("%d ", f[y]);
  }
  return 0;
}
