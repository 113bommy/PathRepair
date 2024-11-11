#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void cmin(T &a, T b) {
  ((a > b) && (a = b));
}
template <class T>
inline void cmax(T &a, T b) {
  ((a < b) && (a = b));
}
char IO;
template <class T = int>
T rd() {
  T s = 0;
  int f = 0;
  while (!isdigit(IO = getchar())) f |= IO == '-';
  do s = (s << 1) + (s << 3) + (IO ^ '0');
  while (isdigit(IO = getchar()));
  return f ? -s : s;
}
const int N = 510, INF = 1e9 + 10;
int n, m;
int trie[N][10], cnt, c[N];
char s[N];
int dp[N][N][12];
int F[N][12], G[12], dep[N];
void dfs(int u) {
  for (int v : trie[u])
    if (v) dep[v] = dep[u] + 1, dfs(v);
  memset(F, 63, sizeof F);
  for (int i = 0, iend = dep[u]; i <= iend; ++i) F[i][0] = c[u] * (dep[u] - i);
  for (int v : trie[u])
    if (v) {
      for (int j = 0, jend = dep[u]; j <= jend; ++j) {
        for (int k = 0, kend = m; k <= kend; ++k) G[k] = F[j][k], F[j][k] = INF;
        for (int k = 0, kend = m; k <= kend; ++k)
          for (int d = 0, dend = m - k; d <= dend; ++d)
            cmin(F[j][k + d], G[k] + dp[v][j][d]);
      }
    }
  for (int d = 0, dend = dep[u]; d <= dend; ++d) {
    for (int i = 0, iend = m; i <= iend; ++i) dp[u][d][i] = INF;
    for (int i = 0, iend = m; i <= iend; ++i) {
      cmin(dp[u][d][i + 1], F[dep[u]][i]);
      cmin(dp[u][d][i], F[d][i]);
    }
  }
}
int main() {
  n = rd(), m = rd();
  for (int i = 1, iend = n; i <= iend; ++i) {
    scanf("%s", s + 1);
    int u = 0;
    for (int j = 1; s[j]; ++j) {
      int &v = trie[u][s[j] - '0'];
      if (!v) v = ++cnt;
      u = v;
    }
    c[u] += rd();
  }
  dfs(0);
  int ans = INF;
  for (int i = 0, iend = m; i <= iend; ++i) cmin(ans, dp[0][0][i]);
  printf("%d\n", ans);
}
