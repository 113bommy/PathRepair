#include <bits/stdc++.h>
using namespace std;
int n, m, deg[1000005];
int main() {
  scanf("%d", &n);
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d", &u);
    scanf("%d", &v);
    u--;
    v--;
    deg[u]++;
    deg[v]++;
  }
  long long tot = 0;
  for (int i = 0; i < n; i++) {
    long long d = deg[i];
    tot += d * (d - 1) + (n - 1 - d) * (n - 2 - d) - d * (n - 1 - d);
  }
  printf("%I64d", tot / 6ll);
  return 0;
}
