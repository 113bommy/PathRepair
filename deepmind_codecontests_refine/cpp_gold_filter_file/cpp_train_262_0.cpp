#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T sqr(T a) {
  return a * a;
};
const double pi = acos(-1.0);
const int INF = INT_MAX;
const long long LLINF = LLONG_MAX;
const int MAX_N = 4e5 + 10;
int N, ans[MAX_N], sz[MAX_N], ms[MAX_N][2], mv[MAX_N][2];
vector<int> G[MAX_N];
void dfs(int v, int p) {
  sz[v] = 1;
  for (auto u : G[v])
    if (u != p) {
      dfs(u, v);
      sz[v] += sz[u];
      int t = sz[u] <= N / 2 ? sz[u] : ms[u][0];
      if (t > ms[v][0])
        mv[v][1] = mv[v][0], mv[v][0] = u, ms[v][1] = ms[v][0], ms[v][0] = t;
      else if (t > ms[v][1])
        mv[v][1] = u, ms[v][1] = t;
    }
}
void dfs1(int v, int p, int lst) {
  if (N - sz[v] - lst <= N / 2) ans[v] = 1;
  for (auto u : G[v])
    if (u != p) {
      if (sz[u] - ms[v][0] > N / 2) ans[v] = 0;
      dfs1(u, v,
           N - sz[u] <= N / 2 ? N - sz[u] : max(lst, ms[v][mv[v][0] == u]));
    }
}
int main(int argc, char const *argv[]) {
  scanf("%d", &N);
  for (int i = 1, u, v; i < N; ++i)
    scanf("%d%d", &u, &v), G[u].push_back(v), G[v].push_back(u);
  dfs(1, 0), dfs1(1, 0, 0);
  for (int i = 1; i < N + 1; ++i) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
