#include <bits/stdc++.h>
using namespace std;
int a[100010], n, sum(0);
int x[100010], y[100010], z[100010], xx, yy, zz;
bool vis[100010];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), sum += a[i];
  sort(a + 1, a + n + 1);
  if (a[1] != 0)
    puts("-1");
  else {
    if (sum % 3 == 0)
      ;
    else {
      for (int i = 1; i <= n; i++) {
        if (a[i] % 3 == 1) x[++xx] = i;
        if (a[i] % 3 == 2) y[++yy] = i;
      }
      if (sum % 3 == 1) {
        if (xx > 0)
          vis[x[1]] = true;
        else if (yy >= 2) {
          vis[y[1]] = true;
          vis[y[2]] = true;
        } else {
          puts("-1");
          return 0;
        }
      }
      if (sum % 3 == 2) {
        if (yy > 0) {
          vis[y[1]] = true;
        } else if (xx >= 2) {
          vis[x[1]] = true;
          vis[x[2]] = true;
        } else {
          puts("-1");
          return 0;
        }
      }
    }
    while (n > 1 && (a[n] == 0 || !vis[n])) n--;
    for (int i = n; i >= 1; i--)
      if (!vis[i]) printf("%d", a[i]);
  }
  return 0;
}
