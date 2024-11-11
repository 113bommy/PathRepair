#include <bits/stdc++.h>
const int N = 210;
const int inf = 0x3f3f3f3f;
using namespace std;
int n, c[N], g[N][N], deg[N], td[N], m[4][4];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
  for (int i = 1; i <= n; i++) {
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      int x;
      scanf("%d", &x);
      g[x][i] = 1;
      deg[i]++;
    }
  }
  int ret = inf;
  for (int cur = 1; cur <= 3; cur++) {
    int tc = cur, cnt = 0, z = -1;
    for (int i = 1; i <= n; i++) td[i] = deg[i];
    while (cnt < n) {
      for (int k = 0; k < n; k++) {
        for (int i = 1; i <= n; i++)
          if (td[i] == 0 && c[i] == tc) {
            for (int j = 1; j <= n; j++) {
              if (g[i][j]) td[j]--;
            }
            td[i]--, cnt++;
          }
      }
      tc++;
      if (tc > 3) tc = 1;
      z++;
    }
    ret = min(ret, z);
  }
  printf("%d\n", ret + n);
  return 0;
}
