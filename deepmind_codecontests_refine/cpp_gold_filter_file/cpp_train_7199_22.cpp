#include <bits/stdc++.h>
using namespace std;
const int mx = 2e5 + 10;
int n, m;
int a[mx];
int b[mx];
int c[mx];
int d[mx];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), c[a[i]] = d[a[i]] = 1;
  for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
  int now = 1;
  int bef = 0;
  int hgf = 1;
  int last = 0;
  int ans = 0x3f3f3f3f;
  for (int i = 1; i <= n; ++i) {
    for (int j = now; j <= n; ++j) {
      if (c[j])
        now = j + 1;
      else
        break;
    }
    c[b[i]] = 1;
    if (b[i] == now) {
      if (i - last > now - hgf) {
        bef += i - last - (now - hgf);
        hgf = now;
        last = i;
      }
    }
  }
  if (hgf == 1) {
    for (int i = last; i <= n; ++i) {
      if (b[i] == hgf) {
        ++hgf;
        if (i == n) {
          int now2 = b[i] + 1;
          int l = 1;
          while (now2 < n + 1) {
            if (d[now2]) {
              now2++;
              d[b[l]] = 1;
              l++;
            } else
              break;
          }
          if (now2 == n + 1) ans = n - b[i];
        }
      } else
        break;
    }
  }
  ans = min(ans, bef + n);
  printf("%d\n", ans);
}
