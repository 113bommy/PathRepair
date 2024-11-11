#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
vector<int> V[maxn];
int n, m, q, deg[maxn];
long long ans, res[maxn];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, x, y; i <= m; i++) {
    scanf("%d%d", &x, &y);
    if (x > y) swap(x, y);
    deg[x]++;
    deg[y]++;
    V[x].push_back(y);
  }
  for (int i = 1, tmp; i <= n; i++) {
    tmp = V[i].size();
    res[i] = (long long)tmp * (deg[i] - tmp);
    ans += tmp;
  }
  printf("%lld\n", ans);
  scanf("%d", &q);
  while (q--) {
    int x;
    scanf("%d", &x);
    for (int i = 0, j, tmp = V[x].size(), tmp2; i < tmp; i++) {
      j = V[x][i];
      V[j].push_back(x);
      ans -= res[j];
      tmp2 = V[j].size();
      res[j] = (long long)tmp2 * (deg[j] - tmp2);
      ans += res[j];
    }
    V[x].clear();
    ans -= res[x];
    res[x] = 0;
    printf("%lld\n", ans);
  }
  return 0;
}
