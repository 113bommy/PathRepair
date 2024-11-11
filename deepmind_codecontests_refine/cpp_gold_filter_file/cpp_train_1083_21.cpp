#include <bits/stdc++.h>
using namespace std;
int a[20][4];
int q[100005];
int dx[] = {1, 1, -1, -1}, dy[] = {1, -1, 1, -1};
int main() {
  int n, m, k, s, xx;
  scanf("%d%d%d%d", &n, &m, &k, &s);
  for (int i = 0; i < 20; i++)
    for (int j = 0; j < 4; j++) a[i][j] = -1000000;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      scanf("%d", &xx);
      for (int z = 0; z < 4; z++) {
        int x = i * dx[z], y = j * dy[z];
        a[xx][z] = max(a[xx][z], x + y);
      }
    }
  for (int i = 0; i < s; i++) scanf("%d", q + i);
  int ans = 0;
  for (int i = 1; i < s; i++)
    for (int j = 0; j < 4; j++) ans = max(ans, a[q[i]][j] + a[q[i - 1]][3 - j]);
  printf("%d\n", ans);
  return 0;
}
