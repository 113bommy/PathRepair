#include <bits/stdc++.h>
using namespace std;
const int MX = 100005, lg = 17;
int n, m, Q, L[MX];
vector<int> G[MX];
struct Node {
  int prnt;
  vector<int> V;
  Node() : prnt(0) {}
  void mrge(vector<int> v1, vector<int> v2) {
    vector<int> v;
    v = v1;
    v.insert(v.end(), v2.begin(), v2.end());
    sort(v.begin(), v.end());
    while (v.size() >= 10) {
      v.pop_back();
    }
    V = v;
  }
} sp[lg + 1][MX];
void dfs(int u) {
  for (auto v : G[u])
    if (!L[v]) {
      L[v] = L[u] + 1;
      sp[0][v].prnt = u;
      dfs(v);
    }
}
void build() {
  for (int i = 1; i <= lg; i++)
    for (int j = 1; j <= n; j++) {
      sp[i][j].prnt = sp[i - 1][sp[i - 1][j].prnt].prnt;
      sp[i][j].mrge(sp[i - 1][j].V, sp[i - 1][sp[i - 1][j].prnt].V);
    }
}
vector<int> query(int u, int v) {
  Node ret;
  if (L[u] < L[v]) swap(u, v);
  for (int i = lg; i >= 0; i--)
    if (L[sp[i][u].prnt] >= L[v]) {
      ret.mrge(ret.V, sp[i][u].V);
      u = sp[i][u].prnt;
    }
  for (int i = lg; i >= 0; i--)
    if (sp[i][u].prnt != sp[i][v].prnt) {
      ret.mrge(ret.V, sp[i][u].V);
      ret.mrge(ret.V, sp[i][v].V);
      u = sp[i][u].prnt, v = sp[i][v].prnt;
    }
  if (u != v) {
    ret.mrge(ret.V, sp[0][u].V);
    ret.mrge(ret.V, sp[0][v].V);
    u = sp[0][u].prnt, v = sp[0][v].prnt;
  }
  ret.mrge(ret.V, sp[0][u].V);
  return ret.V;
}
int main() {
  scanf("%d %d %d", &n, &m, &Q);
  for (int i = 1, u, v; i < n; i++) {
    scanf("%d %d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  for (int i = 1, a; i <= m; i++) {
    scanf("%d", &a);
    sp[0][a].V.push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    vector<int> dmy;
    sp[0][i].mrge(sp[0][i].V, dmy);
  }
  L[1] = 1;
  dfs(1);
  build();
  while (Q--) {
    int u, v, a;
    scanf("%d %d %d", &u, &v, &a);
    vector<int> ans = query(u, v);
    int sz = min(a, (int)ans.size());
    printf("%d", sz);
    for (int i = 0; i < sz; i++) {
      printf(" %d", ans[i]);
    }
    printf("\n");
  }
  return 0;
}
