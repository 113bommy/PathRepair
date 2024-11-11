#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
const int inf = 0x3f3f3f3f;
long long e[500][500], dis[500][500];
long long a[maxn];
int main() {
  int n, m, i, j, k, t, p, x, y;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%I64d", &a[i]);
    if (a[i] == 0) i--, n--;
  }
  if (n > 300) {
    printf("3\n");
    return 0;
  }
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) e[i][j] = inf;
  for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++) {
      if ((a[i] & a[j]) > 0) e[i][j] = e[j][i] = 1;
    }
  memcpy(dis, e, sizeof dis);
  long long ans = inf;
  for (k = 0; k < n; k++) {
    for (i = 0; i < k; i++)
      for (j = 0; j < i; j++) ans = min(ans, e[i][k] + e[k][j] + dis[i][j]);
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
  }
  if (ans > 1004) ans = -1;
  printf("%I64d\n", ans);
  return 0;
}
