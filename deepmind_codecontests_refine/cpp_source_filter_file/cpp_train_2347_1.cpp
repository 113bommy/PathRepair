#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const long long INF = 1e18;
long long power(long long x, long long y) {
  long long t = 1;
  while (y > 0) {
    if (y % 2)
      y -= 1, t = t * x % mod;
    else
      y /= 2, x = x * x % mod;
  }
  return t;
}
vector<int> G[N], order, rG[N];
pair<int, int> dp[N];
int A[N], depth[N];
void dfs(int i, int p, int d) {
  pair<int, int> a = make_pair(mod, -1);
  depth[i] = d;
  for (int j = 0; j < G[i].size(); ++j) {
    dfs(G[i][j], i, d + 1);
    a = min(a, dp[G[i][j]]);
  }
  if (a.first == d) {
    if (A[i] != i) {
      printf("-1\n");
      exit(0);
    }
    dp[i] = a;
    return;
  }
  if (a.first > d) {
    dp[i] = make_pair(depth[A[i]], i);
    return;
  }
  if (a.first < d) {
    if (A[i] != a.first) {
      printf("-1\n");
      exit(0);
    }
    dp[i] = a;
  }
}
void dfs1(int i) {
  for (int j = 0; j < G[i].size(); ++j) dfs1(G[i][j]);
  if (i == A[i]) order.push_back(A[i]);
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--;
    v--;
    G[u].push_back(v);
    rG[v].push_back(u);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &A[i]);
    A[i]--;
  }
  for (int i = 0; i < n; ++i)
    if (rG[i].size() == 0) dfs(i, i, 0);
  for (int i = 0; i < n; ++i)
    if (rG[i].size() == 0) dfs1(i);
  printf("%d\n", (int)order.size());
  for (int i = 0; i < order.size(); ++i) printf("%d\n", order[i] + 1);
  return 0;
}
