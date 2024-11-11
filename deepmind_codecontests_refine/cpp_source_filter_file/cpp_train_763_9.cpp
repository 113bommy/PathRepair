#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
long long deg[N];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--, v--;
    deg[u]++;
    deg[v]++;
  }
  long long ans = 0;
  for (int v = 0; v < n; ++v) {
    ans += deg[v] * deg[v] - deg[v];
    ans -= deg[v] * (n - 1 - deg[v]);
    ans += (n - 1 - deg[v]) * (n - 1 - deg[v]) - (n - 1 - deg[v]);
  }
  printf("%d\n", ans / 6);
}
