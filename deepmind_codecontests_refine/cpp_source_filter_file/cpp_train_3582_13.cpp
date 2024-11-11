#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 509;
int main() {
  int n, m, vis[109], a[109], ans[222], vised[229];
  while (~scanf("%d", &n)) {
    m = 2 * n;
    memset(ans, 0, sizeof(ans));
    memset(vised, 0, sizeof(vised));
    int h1 = 0, h2 = 0, c1 = 0, c2 = 0, t = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= m; ++i) {
      scanf("%d", &a[i]);
      vis[a[i]]++;
    }
    for (int i = 10; i <= 99; ++i) {
      if (vis[i] >= 2) {
        h2++;
      } else if (vis[i] == 1) {
        h1++;
      }
    }
    printf("%d\n", (h2 + (h1 / 2)) * (h2 + ((h1 + 1) / 2)));
    for (int i = 1; i <= m; ++i) {
      if (vis[a[i]] >= 2 && vised[a[i]] < 2) {
        ans[i] = ++vised[a[i]];
        if (ans[i] == 1) {
          ++c1;
        }
      } else if (vis[a[i]] == 1) {
        if (t < h1 / 2) {
          ans[i] = 1;
          ++c1;
          ++t;
        } else {
          ans[i] = 2;
        }
      }
    }
    for (int i = 1; i <= m; ++i) {
      if (ans[i]) {
        printf("%d ", ans[i]);
      } else {
        if (c1 < m / 2) {
          printf("1 ");
          ++c1;
        } else {
          printf("2 ");
        }
      }
    }
    puts("");
  }
  return 0;
}
