#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int n, t, q[maxn], s[maxn], f[maxn], g[maxn];
bool equal() {
  for (int i = 1; i <= n; ++i)
    if (f[i] != s[i]) return 0;
  return 1;
}
int main() {
  while (cin >> n >> t) {
    for (int i = 1; i <= n; ++i) scanf("%d", &q[i]);
    for (int i = 1; i <= n; ++i) scanf("%d", &s[i]);
    for (int i = 1; i <= n; ++i) f[i] = i;
    if (equal())
      printf("NO\n");
    else {
      int l = -1, r = -1;
      for (int k = 1; k <= t; ++k) {
        for (int i = 1; i <= n; ++i) g[i] = f[q[i]];
        for (int i = 1; i <= n; ++i) f[i] = g[i];
        if (equal()) {
          l = k;
          break;
        }
      }
      for (int i = 1; i <= n; ++i) f[i] = i;
      for (int k = 1; k <= t; ++k) {
        for (int i = 1; i <= n; ++i) g[q[i]] = f[i];
        for (int i = 1; i <= n; ++i) f[i] = g[i];
        if (equal()) {
          r = k;
          break;
        }
      }
      if (l == -1 && r == -1)
        printf("NO\n");
      else if (l == -1 || r == -1) {
        int e = max(l, r);
        if ((t - e) & 1)
          printf("NO\n");
        else
          printf("YES\n");
      } else {
        if (l + r == 2) {
          if (t == 1)
            printf("YES\n");
          else
            printf("NO\n");
        } else {
          if (((t - l) & 1) == 0 && ((t - r) & 1) == 0)
            printf("YES\n");
          else
            printf("NO\n");
        }
      }
    }
  }
  return 0;
}
