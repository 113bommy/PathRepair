#include <bits/stdc++.h>
using namespace std;
int n, m, k, pos[201], u, ans, a[201], x;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; i++) {
    scanf("%d", &u);
    pos[u] = i;
    a[i] = u;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      scanf("%d", &x);
      ans += pos[x];
      int pre = x, tmp = pos[x];
      for (int q = 1; q < tmp; q++) {
        pos[a[q]]++;
        swap(a[q], pre);
      }
      a[tmp] = pre;
      pos[x] = 1;
    }
  printf("%d\n", ans);
  return 0;
}
