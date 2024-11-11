#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
int n, u, v, a[MAXN + 5], Ans;
vector<int> Graph[MAXN + 5];
vector<int> p[MAXN + 5], w[MAXN + 5];
void update(int u, int v) {
  for (int i = 0; i < p[u].size(); i++)
    for (int j = 0; j < p[v].size(); j++)
      if (p[u][i] == p[v][j]) {
        Ans = max(Ans, w[u][i] + w[v][j]);
        w[u][i] = max(w[u][i], w[v][j] + 1);
      }
}
void dfs(int u, int fa) {
  for (int i = 0; i < Graph[u].size(); i++) {
    int v = Graph[u][i];
    if (v == fa) continue;
    dfs(v, u);
    update(u, v);
  }
}
int main() {
  scanf("%d", &n);
  int f = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] != 1) f = 1;
    for (int j = 2; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        p[i].push_back(j);
        w[i].push_back(1);
        while (a[i] % j == 0) a[i] /= j;
      }
    }
    if (a[i]) {
      p[i].push_back(a[i]);
      w[i].push_back(1);
    }
  }
  for (int i = 1; i <= n - 1; i++) {
    scanf("%d %d", &u, &v);
    Graph[u].push_back(v);
    Graph[v].push_back(u);
  }
  if (!f) {
    printf("0");
    return 0;
  }
  dfs(1, 0);
  printf("%d\n", Ans);
  return 0;
}
