#include <bits/stdc++.h>
using namespace std;
int a[305], b[305], c[305];
int n;
int ans[305 * 305][2], l;
int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++)
        if (b[j] == a[i]) {
          c[i] = j;
          b[j] = -1;
          break;
        }
    }
    l = 0;
    for (int i = 1; i < n; i++)
      for (int j = 1; j + i <= n; j++) {
        if (c[j] > c[j + 1]) {
          swap(c[j], c[j + 1]);
          ans[l][0] = j;
          ans[l++][1] = j + 1;
        }
      }
    printf("%d\n", l);
    for (int i = 0; i < l; i++) printf("%d %d\n", ans[i][0], ans[i][1]);
  }
  return 0;
}
