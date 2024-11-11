#include <bits/stdc++.h>
using namespace std;
int T, n, a[200010];
int vis[2000];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    int g = 0, z = 0;
    for (int i = 0; i <= 50; ++i) vis[i] = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i] == 0) g++;
      int cnt = 0;
      while (a[i]) {
        if (a[i] & 1) vis[cnt]++;
        a[i] >>= 1;
        cnt++;
      }
    }
    z = n;
    if (g & 1) {
      int fg = 0;
      for (int i = 32; i >= 0; i--) {
        if (vis[i] & 1) {
          int c = z - vis[i];
          int h = vis[i] >> 1;
          if (h % 2 == 0) {
            puts("WIN");
          } else {
            if (c & 1)
              puts("WIN");
            else
              puts("LOSE");
          }
          fg = 1;
          break;
        }
      }
      if (!fg) puts("DRAW");
      continue;
    } else {
      int fg = 0;
      for (int i = 32; i >= 0; i--) {
        if (vis[i] & 1) {
          int c = z - vis[i];
          if (vis[i] & 1) {
            int h = vis[i] >> 1;
            if (h & 1) {
              if (c & 1)
                puts("WIN");
              else
                puts("LOSE");
            } else {
              puts("WIN");
            }
          }
          fg = 1;
          break;
        }
      }
      if (!fg) puts("DRAW");
    }
  }
  return 0;
}
