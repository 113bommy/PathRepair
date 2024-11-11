#include <bits/stdc++.h>
using namespace std;
vector<int> G[101000];
int x, y, n;
long long num[101000], jia[101000], jian[101000];
void add(int x, int y) {
  G[x].push_back(y);
  G[y].push_back(x);
}
void dp(int u, int fa) {
  jia[u] = jian[u] = 0;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v == fa) continue;
    dp(v, u);
    jia[u] = max(jia[u], jia[v]);
    jian[u] = max(jian[u], jian[v]);
  }
  num[u] += jia[u] - jian[u];
  if (num[u] > 0)
    jian[u] += num[u];
  else
    jia[u] -= num[u];
}
int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; i++) G[i].clear();
    for (int i = 1; i < n; i++) {
      scanf("%d%d", &x, &y);
      add(x, y);
    }
    for (int i = 1; i <= n; i++) scanf("%I64d", &num[i]);
    dp(1, -1);
    printf("%I64d\n", jia[1] + jian[1]);
  }
}
