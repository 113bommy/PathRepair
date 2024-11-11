#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int f = 1, ans = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ans = ans * 10 + c - '0';
    c = getchar();
  }
  return f * ans;
}
const int MAXN = 2e3 + 11;
vector<int> vec[MAXN];
int f[MAXN][MAXN << 1], g[MAXN][MAXN << 1], Sf[MAXN][MAXN << 1],
    Sg[MAXN][MAXN << 1], N, M, tot, cnt, A[MAXN], vis[MAXN], F[MAXN][MAXN],
    G[MAXN][MAXN];
long long Ans;
void dfs(int u) {
  ++tot;
  vis[u] = 1;
  for (auto v : vec[u])
    if (!vis[v]) dfs(v);
  return;
}
int Query(int l, int r, int id) {
  l = max(l, -N), r = min(r, N);
  l += N, r += N;
  if (l > r) return 0;
  if (!l) return Sg[id][r];
  return (Sg[id][r] - Sg[id][l - 1] + 1000000007) % 1000000007;
}
signed main() {
  N = read(), M = read();
  for (int i = 1; i <= M; i++) {
    int u = read(), v = read();
    vec[u].push_back(v), vec[v].push_back(u);
  }
  vis[1] = 1;
  for (auto v : vec[1])
    if (!vis[v]) tot = 0, dfs(v), A[++cnt] = tot + 1;
  sort(A + 1, A + cnt + 1);
  f[0][0 + N] = 1, g[cnt + 1][0 + N] = 1;
  for (int i = 1; i <= cnt; i++) {
    for (int j = -N; j <= N; j++) {
      f[i][j + N] += f[i - 1][j + N], f[i][j + N] %= 1000000007;
      if (j + A[i] <= N)
        f[i][j + A[i] + N] += f[i - 1][j + N], f[i][j + A[i] + N] %= 1000000007;
      if (j - A[i] >= -N)
        f[i][j - A[i] + N] += f[i - 1][j + N], f[i][j - A[i] + N] %= 1000000007;
    }
  }
  for (int i = cnt; i >= 1; i--) {
    for (int j = -N; j <= N; j++) {
      g[i][j + N] += g[i + 1][j + N], g[i][j + N] %= 1000000007;
      if (j + A[i] <= N)
        g[i][j + A[i] + N] += g[i + 1][j + N], g[i][j + A[i] + N] %= 1000000007;
      if (j - A[i] >= -N)
        g[i][j - A[i] + N] += g[i + 1][j + N], g[i][j - A[i] + N] %= 1000000007;
    }
  }
  for (int i = 0; i <= cnt + 1; i++)
    for (int j = 0; j <= 2 * N; j++)
      Sf[i][j] = (j == 1 ? 0 : Sf[i][j - 1]) + f[i][j],
      Sg[i][j] = (j == 1 ? 0 : Sg[i][j - 1]) + g[i][j], Sf[i][j] %= 1000000007,
      Sg[i][j] %= 1000000007;
  for (int i = 1; i <= cnt; i++) {
    int L = 2 - A[i], R = A[i] - 2;
    if (L > R) swap(L, R);
    for (int j = -N; j <= N; j++) {
      Ans +=
          (long long)f[i - 1][j + N] * Query(L - j, R - j, i + 1) % 1000000007,
          Ans %= 1000000007;
    }
  }
  Ans = Ans * 2ll % 1000000007;
  if (M & 1) {
    F[0][0] = 1, G[cnt + 1][0] = 1;
    for (int i = 0; i < cnt; i++) {
      for (int j = 0; j <= N; j++) {
        if (!F[i][j]) continue;
        F[i + 1][j + A[i + 1]] += F[i][j], F[i + 1][j + A[i + 1]] %= 1000000007;
        F[i + 1][j] += F[i][j], F[i + 1][j] %= 1000000007;
      }
    }
    for (int i = cnt + 1; i > 1; i--) {
      for (int j = 0; j <= N; j++) {
        if (!G[i][j]) continue;
        G[i - 1][j + A[i - 1]] += G[i][j], G[i - 1][j + A[i - 1]] %= 1000000007;
        G[i - 1][j] += G[i][j], G[i - 1][j] %= 1000000007;
      }
    }
    for (int i = 1; i <= cnt; i++) {
      int sum = (M - 1) / 2;
      for (int j = 0; j <= sum; j++) {
        Ans += (long long)4ll * F[i - 1][j] * G[i + 1][sum - j] % 1000000007,
            Ans %= 1000000007;
      }
    }
  } else {
    memset(f, 0, sizeof(f));
    f[0][0 + N] = 1;
    for (int i = 1; i <= cnt; i++) {
      for (int j = -N; j <= N; j++) {
        if (j + A[i] <= N)
          f[i][j + A[i] + N] += f[i - 1][j + N],
              f[i][j + A[i] + N] %= 1000000007;
        if (j - A[i] >= -N)
          f[i][j - A[i] + N] += f[i - 1][j + N],
              f[i][j + A[i] + N] %= 1000000007;
      }
    }
    Ans += f[cnt][0 + N];
    Ans %= 1000000007;
  }
  printf("%lld\n", Ans);
  return 0;
}
