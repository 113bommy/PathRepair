#include <bits/stdc++.h>
using namespace std;
int Read() {
  char c;
  while (c = getchar(), (c != '-') && (c < '0' || c > '9'))
    ;
  bool neg = (c == '-');
  int ret = (neg ? 0 : c - 48);
  while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + c - 48;
  return neg ? -ret : ret;
}
const int MAXN = 200005, MOD = 7 + 1e9;
vector<int> e[MAXN];
int size[MAXN], dep[MAXN], suc[MAXN], f[MAXN], fa[MAXN];
int N, cnt, st[MAXN], nxt[MAXN << 1], lnk[MAXN << 1], deg[MAXN];
void init() {
  scanf("%d", &N), N += N;
  for (int i = 2; i <= N; i++) {
    int u = Read(), v = Read();
    ++deg[u], ++deg[v];
    lnk[++cnt] = v, nxt[cnt] = st[u], st[u] = cnt;
    lnk[++cnt] = u, nxt[cnt] = st[v], st[v] = cnt;
  }
}
void DFS(int x) {
  size[x] = 1;
  for (int i = st[x], y = lnk[i]; i; i = nxt[i], y = lnk[i])
    if (y != fa[x]) {
      fa[y] = x, dep[y] = dep[x] + 1, DFS(y);
      e[x].push_back(y), size[x] += size[y], suc[x] = suc[y];
    }
  e[x].push_back(0), e[x].push_back(0);
  if (deg[x] != 2) suc[x] = x;
}
int Duo(int, int);
int Solo(int x) {
  if (!x) return 1;
  if (size[x] & 1) return 0;
  if (f[x] >= 0) return f[x];
  if (deg[suc[x]] == 1) return size[x] / 2;
  int w = suc[x], h = dep[w] - dep[x];
  f[x] = 0;
  for (int i = 0; i <= 1; i++) {
    int y = e[w][i];
    if (size[y] == h - 1 && deg[suc[y]] <= 1)
      (f[x] += Solo(e[w][i ^ 1])) %= MOD;
    else
      for (int j = 0; j <= (e[y][0] > 0); j++) {
        int u = e[y][j], v = e[y][j ^ 1];
        if (size[u] == h && deg[suc[u]] <= 1)
          (f[x] += Duo(v, e[w][i ^ 1])) %= MOD;
      }
  }
  if (deg[x] == 2 && deg[e[x][0]] <= 2) (f[x] += Solo(e[e[x][0]][0])) %= MOD;
  return f[x];
}
int Duo(int x, int y) {
  if ((size[x] + size[y]) & 1) return 0;
  if (!x) return Solo(y);
  if (!y) return Solo(x);
  if (deg[x] > 2 || deg[y] > 2) return 0;
  return Duo(e[x][0], e[y][0]);
}
int Trio(int s1, int s2, int s3) {
  if (deg[s1] == 1) return (long long)Solo(s2) * Solo(s3) % MOD;
  int ret = 0;
  for (int i = 0; i <= 1; i++)
    (ret += (long long)Duo(s2, e[s1][i]) * Duo(s3, e[s1][i ^ 1]) % MOD) %= MOD;
  return ret;
}
int work() {
  memset(f, -1, sizeof(f));
  if (N == 2) return 2;
  for (int i = 1; i <= N; i++)
    if (deg[i] > 3) return 0;
  for (int i = 1; i <= N; i++)
    if (deg[i] == 3) {
      DFS(i);
      int ans = 0, s1 = lnk[st[i]], s2 = lnk[nxt[st[i]]],
          s3 = lnk[nxt[nxt[st[i]]]];
      (ans += Trio(s1, s2, s3)) %= MOD;
      (ans += Trio(s1, s3, s2)) %= MOD;
      (ans += Trio(s2, s1, s3)) %= MOD;
      (ans += Trio(s2, s3, s1)) %= MOD;
      (ans += Trio(s3, s1, s2)) %= MOD;
      (ans += Trio(s3, s2, s1)) %= MOD;
      return (ans + ans) % MOD;
    }
  return N /= 2, 2 * ((long long)N * N - N + 2) % MOD;
}
int main() {
  init();
  printf("%d\n", work());
  return 0;
}
