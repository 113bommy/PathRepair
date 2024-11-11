#include <bits/stdc++.h>
using namespace std;
bool p[100005];
int main() {
  int T, n;
  scanf("%d", &T);
  while (T--) {
    memset(p, 0, sizeof(p));
    int m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
      int u, v, w;
      scanf("%d%d%d", &u, &w, &v);
      p[u] = p[v] = 1;
    }
    int flag = 1;
    for (int i = 1; i <= n; i++)
      if (!p[i]) flag = i;
    for (int i = 1; i <= n; i++)
      if (i != flag) printf("%d %d\n", flag, i);
  }
  return 0;
}
