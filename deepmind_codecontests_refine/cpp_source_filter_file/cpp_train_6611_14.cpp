#include <bits/stdc++.h>
using namespace std;
int f[100030], a[100030], pos[100030], vis[100030];
int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) != EOF) {
    memset(vis, 0, sizeof(vis));
    memset(pos, 0, sizeof(pos));
    for (int i = 0; i < n; i++) {
      scanf("%d", &f[i]);
      pos[f[i]] = i + 1;
      vis[f[i]]++;
    }
    int flag = 0;
    for (int i = 0; i < n; i++) {
      int tmp;
      scanf("%d", &tmp);
      if (flag == 2) continue;
      if (pos[tmp] != 0) {
        if (vis[tmp] > 1) {
          flag = 1;
        } else if (vis[tmp] == 1) {
          a[i] = pos[tmp];
        }
      } else
        flag = 2;
    }
    if (flag == 1)
      printf("Ambiguity\n");
    else if (flag == 2)
      printf("Impossible\n");
    else {
      printf("Possible\n");
      for (int i = 0; i < n - 1; i++) printf("%d ", a[i]);
      printf("%d\n", a[n - 1]);
    }
  }
}
