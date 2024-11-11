#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int LEN = 100010;
vector<int> Map[LEN];
int n, vex[LEN], st[LEN], ed[LEN], bf[LEN];
void dfs(int v, int fa, int ffa) {
  if (ffa == -1) {
    if (st[v] != ed[v]) {
      vex[v] = 1;
      bf[v] ^= 1;
    }
  } else {
    bf[v] ^= bf[ffa];
    if (st[v] != ed[v] && !bf[v]) vex[v] = 1;
    if (st[v] == ed[v] && bf[v]) vex[v] = 1;
    bf[v] ^= vex[v];
  }
  for (int i = 0; i < Map[v].size(); i++) {
    int x = Map[v][i];
    if (x != fa) {
      dfs(x, v, fa);
    }
  }
}
int main() {
  int a, b;
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < LEN; i++) Map[i].clear();
    memset(vex, 0, sizeof vex);
    memset(bf, 0, sizeof bf);
    for (int i = 0; i < n - 1; i++) {
      scanf("%d%d", &a, &b);
      Map[a].push_back(b);
      Map[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d", &st[i]);
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d", &ed[i]);
    }
    dfs(1, -1, -1);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (vex[i]) cnt++;
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= n; i++) {
      if (vex[i]) printf("%d\n", i);
    }
    printf("\n");
  }
  return 0;
}
