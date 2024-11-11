#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const int INF = (int)1e9 + 9;
const int MAXN = (int)2e6 + 7;
int n, m;
int dsu[MAXN];
int get(int u) {
  if (dsu[u] == u) {
    return u;
  }
  return dsu[u] = get(dsu[u]);
}
bool join(int u, int v) {
  u = get(u);
  v = get(v);
  if (u == v) {
    return false;
  }
  dsu[u] = v;
  return true;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    dsu[i] = i;
  }
  int ans = 1;
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (!join(u, v)) {
      ans = (ans << 1) % INF;
    }
    printf("%d\n", ans - 1);
  }
  return 0;
}
