#include <bits/stdc++.h>
using namespace std;
const int N = 105, inf = 10000007;
int n, l[N], r[N], ans[N], vis[N];
bool pd(int a, int b) {
  return l[a] < l[b] ? 1 : l[a] == l[b] ? r[a] < r[b] ? 1 : 0 : 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &l[i], &r[i]);
  l[0] = r[0] = inf;
  for (int i = 1; i <= n; i++) {
    int opt = 0;
    for (int j = 1; j <= n; j++) {
      if (!vis[j] && pd(j, opt)) opt = j;
    }
    ans[opt] = l[opt];
    vis[opt] = 1;
    for (int j = 1; j <= n; j++) {
      l[j] = max(l[j], ans[opt] + 1);
    }
  }
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
