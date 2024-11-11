#include <bits/stdc++.h>
using namespace std;
int T, n, m;
int sn, dn;
int ans[2000005], deg[2000005];
int dfn[2000005];
int cmp[2000005];
vector<int> adj[2000005], scc[2000005];
stack<int> st;
int make_scc(int x) {
  int low;
  low = dfn[x] = ++dn;
  st.push(x);
  for (int y : adj[x]) {
    if (dfn[y] && !cmp[y])
      low = min(low, dfn[y]);
    else if (!dfn[y])
      low = min(low, make_scc(y));
  }
  if (dfn[x] == low) {
    scc[++sn].emplace_back(x);
    cmp[x] = sn;
    while (st.top() != x) {
      scc[sn].emplace_back(st.top());
      cmp[st.top()] = sn;
      st.pop();
    }
    st.pop();
  }
  return low;
}
int main() {
  int i, x, y;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &m);
    for (i = 1; i <= sn; i++) {
      (scc[i]).clear();
      (scc[i]).resize(0);
      ;
      deg[i] = 0;
    }
    dn = sn = 0;
    for (i = 1; i <= 2 * n; i++) {
      (adj[i]).clear();
      (adj[i]).resize(0);
      ;
      ans[i] = dfn[i] = cmp[i] = 0;
    }
    for (i = 0; i < m; i++) {
      scanf("%d %d", &x, &y);
      if (x == y) continue;
      adj[2 * x].emplace_back(2 * y);
      adj[2 * y - 1].emplace_back(2 * x - 1);
    }
    for (i = 1; i <= 2 * n; i++) {
      if (!dfn[i]) {
        make_scc(i);
      }
    }
    if (sn == 2) {
      printf("No\n");
      continue;
    }
    printf("Yes\n");
    for (i = 1; i <= 2 * n; i++) {
      for (int y : adj[i]) {
        if (cmp[i] == cmp[y]) continue;
        deg[cmp[i]]++;
      }
    }
    for (i = 1; i <= sn; i++) {
      if (deg[i] == 0 && scc[i][0] % 2 == 0) break;
    }
    int z = 0;
    for (int y : scc[i]) {
      ans[(y + 1) / 2] = 1;
      z++;
    }
    printf("%d %d\n", z, n - z);
    for (i = 1; i <= n; i++) {
      if (ans[i]) printf("%d ", i);
    }
    printf("\n");
    for (i = 1; i <= n; i++) {
      if (!ans[i]) printf("%d ", i);
    }
    printf("\n");
  }
  return 0;
}
