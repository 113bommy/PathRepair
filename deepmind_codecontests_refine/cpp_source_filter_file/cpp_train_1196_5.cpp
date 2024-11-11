#include <bits/stdc++.h>
using namespace std;
int n, head[100005 * 3], tot, de[100005], le[100005], lf[100005];
struct node {
  int to, next;
} edge[100005 * 2];
void add_edge(int u, int v) {
  de[u]++;
  edge[tot].to = v;
  edge[tot].next = head[u];
  head[u] = tot++;
}
void dfs(int cnt, int pre) {
  lf[cnt] = 1;
  for (int i = head[cnt]; i != -1; i = edge[i].next) {
    int j = edge[i].to;
    if (j == pre) continue;
    if (de[j] <= 2) dfs(j, cnt);
  }
}
int main() {
  while (cin >> n) {
    tot = 0;
    memset(head, -1, sizeof(head));
    memset(de, 0, sizeof(de));
    memset(lf, 0, sizeof(lf));
    memset(le, 0, sizeof(le));
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      add_edge(u, v);
      add_edge(v, u);
    }
    for (int i = 1; i <= n; i++) {
      if (de[i] == 1) dfs(i, 0);
    }
    for (int i = 1; i <= n; i++) {
      for (int j = head[i]; j != -1; j = edge[j].next) {
        int k = edge[j].to;
        if (lf[k]) le[k]++;
      }
    }
    int flag = 0;
    for (int i = 1; i <= n && !flag; i++) {
      if (lf[i]) continue;
      int cn = 0;
      for (int j = head[i]; j != -1; j = edge[j].next) {
        int k = edge[j].to;
        if (lf[k] == 0 && de[k] - min(2, le[k]) >= 2) cn++;
        if (cn > 2) {
          flag = 1;
          break;
        }
      }
    }
    if (flag)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
