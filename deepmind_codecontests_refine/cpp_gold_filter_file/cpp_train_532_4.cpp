#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 29;
const int maxn = 1e5 + 5;
int n, m, k;
int p[maxn], sc[maxn], ask[maxn], pq[maxn], fg[maxn], ans[maxn];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
  for (int i = 1; i <= n; i++)
    scanf("%d", &sc[i]), pq[sc[i]] = max(pq[sc[i]], p[i]);
  for (int i = 1; i <= k; i++) scanf("%d", &ask[i]), fg[p[ask[i]]] = 1;
  int res = k;
  for (int i = 1; i <= m; i++) {
    int which = pq[i];
    if (fg[which]) --res;
  }
  printf("%d\n", res);
  return 0;
}
