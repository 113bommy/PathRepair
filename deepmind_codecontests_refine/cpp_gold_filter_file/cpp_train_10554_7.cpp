#include <bits/stdc++.h>
using namespace std;
const int maxn = 80000 + 10;
int n;
long long ans;
int a[maxn];
vector<int> edge[maxn];
void dfs(int u, int pre) {
  a[u] = 1;
  long long in = 0;
  for (int i = 0; i < edge[u].size(); i++) {
    int v = edge[u][i];
    if (v == pre) continue;
    dfs(v, u);
    in += (long long)a[u] * a[v];
    a[u] += a[v];
  }
  ans -= in * (in + 2 * (long long)a[u] * (n - a[u]));
}
int main() {
  int a, b, i;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &a, &b);
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  ans = (long long)n * (n - 1) / 2;
  ans *= ans;
  dfs(1, 0);
  printf("%I64d", ans);
}
