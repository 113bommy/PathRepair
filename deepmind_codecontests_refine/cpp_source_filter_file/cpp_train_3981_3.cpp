#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 5;
int k, H = 0;
vector<int> g[N], lay[N];
int d[N], par[N];
void dfs(int v) {
  lay[d[v]].push_back(v);
  H = max(H, d[v]);
  for (int u : g[v]) {
    if (d[u] == -1) {
      par[u] = v;
      d[u] = d[v] + 1;
      dfs(u);
    } else {
      if (d[v] - d[u] >= k - 1) {
        printf("2\n");
        printf("%d\n", d[v] - d[u]);
        printf("%d ", v + 1);
        for (int x = v; x != u; x = par[x]) printf("%d ", par[x] + 1);
        printf("\n");
        exit(0);
      }
    }
  }
}
int dp[N];
int prv[N];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  k = (int)sqrt(n);
  if (k * k != n) ++k;
  while (m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  memset(d, -1, sizeof d);
  d[0] = 0;
  dfs(0);
  dp[0] = (int)(lay[0]).size();
  prv[0] = -2;
  for (int i = 1; i <= H; ++i) {
    int add = (int)(lay[i]).size() + (i >= k - 1 ? dp[i - k + 1] : 0);
    if (dp[i - 1] > add) {
      dp[i] = dp[i - 1];
      prv[i] = i - 1;
    } else {
      dp[i] = add;
      prv[i] = max(i - k + 1, -1);
    }
  }
  int i = H;
  int left = k;
  vector<int> out;
  while (i >= 0 && left) {
    if (prv[i] != i - 1) {
      for (int v : lay[i]) {
        out.push_back(v);
        --left;
        if (!left) break;
      }
    }
    i = prv[i];
  }
  printf("1\n");
  for (int x : out) printf("%d ", x + 1);
  printf("\n");
}
