#include <bits/stdc++.h>
using namespace std;
const int maxp = 405;
const int maxn = 19;
int n, tot;
int a[maxn];
long long h[maxn][1 << maxn];
long long A[maxn][1 << maxn], F[1 << maxn], G[1 << maxn];
long long val[maxp];
int graph[maxn][maxn];
vector<vector<int> > part;
inline void FWT(long long *vec) {
  for (int i = (0); i < (n); ++i)
    for (int S = (0); S < (1 << n); ++S)
      if (S >> i & 1) vec[S] += vec[S ^ (1 << i)];
  return;
}
inline void mul(long long *v1, long long *v2) {
  for (int S = (0); S < (1 << n); ++S) v1[S] = v1[S] * v2[S];
  return;
}
inline void solve(int dep) {
  for (int i = (0); i < (1 << n); ++i) F[i] = 1;
  for (int i = (0); i < (dep); ++i) mul(F, A[a[i]]);
  int res = 0;
  for (int S = (0); S < (1 << n); ++S) {
    int coe = n - __builtin_popcount(S);
    if (coe & 1)
      res -= F[S];
    else
      res += F[S];
  }
  val[tot++] = res;
  vector<int> tmp;
  for (int i = (0); i < (dep); ++i) tmp.push_back(a[i]);
  part.push_back(tmp);
  return;
}
inline void dfs(int rem, int dep) {
  if (!rem) {
    solve(dep);
    return;
  }
  for (int i = ((dep ? a[dep - 1] : 1)); i <= (rem); ++i)
    a[dep] = i, dfs(rem - i, dep + 1);
  return;
}
inline void precalc() {
  for (int u = (0); u < (n); ++u) h[u][1 << u] = 1;
  for (int S = (0); S < (1 << n); ++S)
    for (int u = (0); u < (n); ++u)
      if (h[u][S])
        for (int v = (0); v < (n); ++v)
          if (!(S >> v & 1) && graph[u][v]) h[v][S ^ (1 << v)] += h[u][S];
  for (int S = (0); S < (1 << n); ++S)
    for (int u = (0); u < (n); ++u) A[__builtin_popcount(S)][S] += h[u][S];
  for (int i = (0); i <= (n); ++i) FWT(A[i]);
  return;
}
int main() {
  scanf("%d", &n);
  for (int i = (0); i < (n); ++i) {
    char buf[maxn];
    scanf("%s", buf);
    for (int j = (0); j < (n); ++j) graph[i][j] = buf[j] - '0';
  }
  precalc();
  dfs(n, 0);
  sort(part.begin(), part.end());
  for (int S = (0); S < (1 << (n - 1)); ++S) {
    int cur = 0;
    vector<int> tmp;
    for (int i = (0); i < (n); ++i) {
      ++cur;
      if (!(S >> i & 1)) tmp.push_back(cur), cur = 0;
    }
    sort(tmp.begin(), tmp.end());
    int pos = lower_bound(part.begin(), part.end(), tmp) - part.begin();
    G[S] = val[pos];
  }
  for (int i = (0); i < (n - 1); ++i)
    for (int S = (1 << n - 1) - 1; S >= 0; --S)
      if (S >> i & 1) G[S ^ (1 << i)] -= G[S];
  for (int i = (0); i < (1 << (n - 1)); ++i) printf("%lld ", G[i]);
  puts("");
  return 0;
}
