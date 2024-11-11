#include <bits/stdc++.h>
using namespace std;
const int MAX = 212345;
vector<int> edge[MAX];
int ans[MAX];
void dfs(int u, int c) {
  ans[u] = c;
  for (const auto &v : edge[u]) {
    if (ans[v]) continue;
    dfs(v, c == 1 ? 2 : 1);
  }
}
int main() {
  int n;
  cin >> n;
  vector<int> G1, G2;
  for (int i = 0; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--, v--;
    G1.push_back(u);
    G2.push_back(v);
    edge[u].push_back(v);
    edge[v].push_back(u);
    edge[i * 2].push_back(i * 2 + 1);
    edge[i * 2 + 1].push_back(i * 2);
  }
  for (int i = 0; i < 2 * n; i++)
    if (!ans[i]) dfs(i, 1);
  for (int i = 0; i < n; i++) printf("%d %d\n", ans[G1[i]], ans[G2[i]]);
}
