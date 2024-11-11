#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
char XX[MAXN * 100], *Buffer;
inline int read() {
  int p = 1, x = 0;
  char ch = *Buffer;
  while (ch < '0' || ch > '9') ch == '-' ? p = -1 : 0, ch = *++Buffer;
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + (ch ^ 48), ch = *++Buffer;
  return p * x;
}
int n, y, k, ki, X, val[MAXN];
int vis[MAXN], rt, Mn, sz[MAXN], tot;
long long Fpk[MAXN], Fpki[MAXN];
int in[MAXN], out[MAXN];
struct Node {
  long long x;
  int y;
} p[MAXN], q[MAXN];
vector<int> G[MAXN];
inline long long fp(long long x, int k) {
  long long ans = 1;
  while (k) {
    if (k & 1) ans = ans * x % y;
    x = x * x % y, k >>= 1;
  }
  return ans;
}
void GetRt(int x, int N, int fa) {
  int Mx = 0;
  sz[x] = 1;
  for (int i = 0; i <= (int)G[x].size() - 1; ++i) {
    int y = G[x][i];
    if (vis[y] || y == fa) continue;
    GetRt(y, N, x), sz[x] += sz[y];
    Mx = max(Mx, sz[y]);
  }
  Mx = max(Mx, n - sz[x]);
  if (Mx < Mn) Mn = Mx, rt = x;
}
void dfs(int x, int fa, int dep, long long s1, long long s2) {
  s1 = (s1 * k + val[x]) % y,
  s2 = (s2 + val[x] * (!dep ? 0 : Fpk[dep - 1])) % y, dep++;
  ++tot, p[tot] = (Node){(X - s1 + y) * Fpki[dep] % y, x},
         q[tot] = (Node){s2, x};
  for (int i = 0; i <= (int)G[x].size() - 1; ++i)
    if (!vis[G[x][i]] && G[x][i] != fa) dfs(G[x][i], x, dep, s1, s2);
}
inline void Calc(int x, int flag, int dep, long long s1, long long s2) {
  tot = 0, s1 = (s1 * k + val[x]) % y,
  s2 = (s2 + val[x] * ((!dep) ? 0 : Fpk[dep - 1])) % y, dep++;
  ++tot, p[tot] = (Node){(X - s1 + y) * Fpki[dep] % y, x},
         q[tot] = (Node){s2, x};
  for (int i = 0; i <= (int)G[x].size() - 1; ++i)
    if (!vis[G[x][i]]) dfs(G[x][i], x, dep, s1, s2);
  sort(p + 1, p + tot + 1, [](Node a, Node b) { return a.x < b.x; });
  sort(q + 1, q + tot + 1, [](Node a, Node b) { return a.x < b.x; });
  for (int cnt = 0, i = 0, j = 0; i <= tot; ++i) {
    for (; j <= tot && q[j].x <= p[i].x; ++j, ++cnt)
      if (j == 1 || q[j].x != q[j - 1].x) cnt = 0;
    if (j != 1 && q[j - 1].x == p[i].x) out[p[i].y] += flag * cnt;
  }
  for (int cnt = 0, i = 0, j = 0; i <= tot; ++i) {
    for (; j <= tot && p[j].x <= q[i].x; ++j, ++cnt)
      if (j == 1 || p[j].x != p[j - 1].x) cnt = 0;
    if (j != 1 && p[j - 1].x == q[i].x) in[q[i].y] += flag * cnt;
  }
}
void Solve(int now, int N) {
  vis[now] = 1, Calc(now, 1, 0, 0, 0);
  for (int i = 0; i <= (int)G[now].size() - 1; ++i) {
    int y = G[now][i];
    if (vis[y]) continue;
    Calc(y, -1, 1, val[now], 0);
    Mn = 1 << 30;
    GetRt(y, sz[y], now), Solve(rt, sz[y]);
  }
}
int main() {
  fread(XX, 100, MAXN, stdin);
  Buffer = XX;
  n = read(), y = read(), k = read(), ki = fp(k, y - 2), X = read();
  Fpk[0] = 1;
  for (int i = 1; i <= n; ++i) Fpk[i] = Fpk[i - 1] * k % y;
  Fpki[0] = 1;
  for (int i = 1; i <= n; ++i) Fpki[i] = Fpki[i - 1] * ki % y;
  for (int i = 1; i <= n; ++i) val[i] = read();
  for (int i = 1; i <= n - 1; ++i) {
    int x = read(), y = read();
    G[x].push_back(y);
    G[y].push_back(x);
  }
  Mn = 1 << 30;
  GetRt(1, n, 0);
  Solve(rt, n);
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    int in1 = n - in[i], out1 = n - out[i];
    ans += 2 * in1 * in[i] + 2 * out1 * out[i] + in1 * out[i] + in[i] * out1;
  }
  cout << 1ll * n * n * n - ans / 2 << "\n";
  return 0;
}
