#include <bits/stdc++.h>
using namespace std;
int ans[100010], qz[100010] = {};
int main() {
  for (int i = 3; i <= 100000; i++) {
    int c = i * 2, bs = 0, vis[1000] = {};
    for (int j = 2; j * j <= c; j++) {
      if (c % j == 0) {
        int f, e, z = c / j;
        if ((z & 1) ^ (j & 1)) {
          f = z / 2 - (j - 1) / 2;
          e = z - f;
          if (f > 0) {
            vis[qz[e] ^ qz[f - 1]] = 1;
            if (qz[e] ^ qz[f - 1] == 0)
              if (bs == 0 || bs > j) bs = j;
          }
          swap(z, j);
          f = z / 2 - (j - 1) / 2;
          e = z - f;
          if (f > 0) {
            vis[qz[e] ^ qz[f - 1]] = 1;
            if (qz[e] ^ qz[f - 1] == 0)
              if (bs == 0 || bs > j) bs = j;
          }
          swap(z, j);
        }
      }
    }
    ans[i] = bs;
    int tt = 0;
    while (vis[tt]) tt++;
    qz[i] = qz[i - 1] ^ tt;
  }
  for (int i = 1; i <= 100000; i++)
    if (ans[i] == 0) ans[i]--;
  int n;
  while (scanf("%d", &n) != EOF) {
    printf("%d\n", ans[n]);
  }
  return 0;
}
