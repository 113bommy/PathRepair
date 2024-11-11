#include <bits/stdc++.h>
const double eps = 1e-14;
const int inf = 0x3f3f3f3f;
const int N = 1e6 + 10;
const int mod = 1e6 + 7;
const double pi = acos(-1);
using namespace std;
vector<int> vec[N], G[N];
int color[N];
void dfs(int u, int par) {
  set<int> st;
  int tmp = 0;
  for (auto g : vec[u])
    if (color[g]) st.insert(color[g]);
  for (auto g : vec[u])
    if (!color[g]) {
      while (st.find(++tmp) != st.end())
        ;
      color[g] = tmp;
      st.insert(color[g]);
    }
  for (auto v : G[u])
    if (v != par) dfs(v, u);
}
int main() {
  int n, m;
  while (~scanf("%d%d", &n, &m)) {
    int ans = 0;
    memset(color, 0, sizeof(color));
    for (int i = 1; i <= n; i++) {
      int k;
      scanf("%d", &k);
      ans = max(ans, k);
      vec[i].clear();
      G[i].clear();
      for (int j = 0; j < k; j++) {
        int x;
        scanf("%d", &x);
        vec[i].push_back(x);
      }
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d", &u);
      scanf("%d", &v);
      G[u].push_back(v);
      G[v].push_back(u);
    }
    dfs(1, -1);
    printf("%d\n", ans);
    for (int i = 1; i <= m; i++) printf("%d ", color[i] ? color[i] : 1);
    printf("\n");
  }
  return 0;
}
