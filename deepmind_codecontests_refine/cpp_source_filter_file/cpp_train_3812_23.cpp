#include <bits/stdc++.h>
using namespace std;
int n;
int a[1005], b[1005], c[1005], d[1005], e[1005];
int hd[1005], tot;
int main() {
  scanf("%d", &n);
  if (n > 10) {
    printf("0\n");
    return 0;
  }
  for (int j = 1; j <= n; j++)
    scanf("%d %d %d %d %d", &a[j], &b[j], &c[j], &d[j], &e[j]);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i != j) {
        for (int k = j + 1; k <= n; k++) {
          if (k != i) {
            int ans = 0;
            ans += (a[j] - a[i]) * (a[k] - a[i]);
            ans += (b[j] - b[i]) * (b[k] - b[i]);
            ans += (c[j] - c[i]) * (c[k] - c[i]);
            ans += (d[j] - d[i]) * (d[k] - d[i]);
            ans += (e[j] - e[i]) * (e[k] - e[i]);
            if (ans > 0) goto nxt;
          }
        }
      }
    }
    tot++;
    hd[tot] = i;
  nxt:;
  }
  printf("%d\n", tot);
  for (int i = 1; i <= tot; i++) printf("%d\n", hd[i]);
  return 0;
}
