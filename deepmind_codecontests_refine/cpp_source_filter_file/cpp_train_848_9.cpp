#include <bits/stdc++.h>
using namespace std;
const int N = 2000100;
int a[N];
int to[N];
int vis[N];
int main() {
  int T;
  scanf("%d", &T);
  for (; T--;) {
    int n, m, sum(0), po1, po2;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= 3 * n; ++i) to[i] = i;
    for (int i = 1; i <= m; ++i) {
      scanf("%d%d", &po1, &po2);
      vis[i] = 0;
      if (sum < n && (to[po1] == po1 && to[po2] == po2))
        sum++, to[po1] = po2, to[po2] = po1, vis[i] = 1;
    }
    if (sum == n) {
      printf("Matching\n");
      for (int i = 1; i <= m; ++i)
        if (vis[i]) printf("%d ", i);
      printf("\n");
    } else {
      printf("IndSet\n");
      int all(0);
      for (int i = 1; i <= 3 * n; ++i)
        if (all <= n && to[i] == i) printf("%d ", i), all++;
      printf("\n");
    }
  }
  return 0;
}
