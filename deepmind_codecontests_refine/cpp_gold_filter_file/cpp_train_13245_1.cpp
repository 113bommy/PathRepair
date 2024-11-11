#include <bits/stdc++.h>
using namespace std;
int m, n, t = 1, zx[200005], vis[200005];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int d = 0, ok = 1, sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &zx[i]);
      d = max(d, zx[i]);
    }
    int a = d, b = n - d;
    for (int i = 0; i < d; ++i) {
      if (!vis[zx[i]]) {
        a--;
        vis[zx[i]]++;
      } else
        break;
    }
    if (a != 0) ok = 0;
    if (ok) {
      a = b;
      for (int i = 1; i <= n; i++) vis[i] = 0;
      for (int i = d; i < n; i++) {
        if (!vis[zx[i]] && zx[i] >= 1 && zx[i] <= b) {
          a--;
          vis[zx[i]]++;
        } else
          break;
      }
      if (a == 0) sum1++;
    }
    ok = 1;
    for (int i = 1; i <= n; i++) vis[i] = 0;
    a = d;
    for (int i = b; i < n; ++i) {
      if (!vis[zx[i]]) {
        a--;
        vis[zx[i]]++;
      } else
        break;
    }
    if (a != 0) ok = 0;
    if (ok) {
      a = b;
      for (int i = 1; i <= n; i++) vis[i] = 0;
      for (int i = 0; i < b; i++) {
        if (!vis[zx[i]] && zx[i] >= 1 && zx[i] <= b) {
          a--;
          vis[zx[i]]++;
        } else
          break;
      }
      if (a == 0) sum2++;
    }
    for (int i = 1; i <= n; i++) vis[i] = 0;
    if (b != d)
      printf("%d\n", sum1 + sum2);
    else
      printf("%d\n", (sum1 + sum2) / 2);
    if (sum1) printf("%d %d\n", d, b);
    if (sum2 && b != d) printf("%d %d\n", b, d);
  }
  return 0;
}
