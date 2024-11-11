#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000")
vector<int> G[100009];
int n;
double ans;
void dfs(int u, int fa, int d) {
  ans += 1.0 / d;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v != fa) dfs(v, u, d + 1);
  }
}
int main() {
  scanf("%d", &n);
  int x, y;
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    G[x].push_back(y);
    G[y].push_back(x);
  }
  ans = 0;
  dfs(1, -1, 1);
  printf("%.9lf\n", ans);
}
