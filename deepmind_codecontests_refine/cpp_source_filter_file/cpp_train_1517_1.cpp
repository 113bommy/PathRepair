#include <bits/stdc++.h>
using namespace std;
const int Mod = 1000000007;
int n, m, tot, sz;
int head[100010], to[400010], nxt[400010], t[100010], p2[400010];
long long w[400010], dis[100010], A[400010], P[63];
bool vis[100010];
void Add_Edge(int x, int y, long long z) {
  to[tot] = y, nxt[tot] = head[x], w[tot] = z, head[x] = tot++;
}
void Dfs(int x, long long s) {
  vis[x] = true;
  dis[x] = s;
  t[++t[0]] = x;
  for (int i = head[x]; i != -1; i = nxt[i]) {
    int y = to[i];
    if (vis[y])
      A[++sz] = s ^ w[i] ^ dis[y];
    else
      Dfs(y, s ^ w[i]);
  }
}
void Guass() {
  memset(P, 0, sizeof(P));
  for (int i = 1; i <= sz; i++) {
    for (int j = 61; j >= 0; j--) {
      if ((A[i] >> j) & 1) {
        if (P[j])
          A[i] ^= P[j];
        else {
          P[j] = A[i];
          break;
        }
      }
    }
  }
}
int f(int x) { return 1ll * x * (x - 1) / 2 % Mod; }
int Solve() {
  int res = 0, r = 0;
  for (int i = 1; i <= sz; i++)
    if (P[i]) r++;
  for (int k = 0; k <= 61; k++) {
    bool flag = false;
    for (int j = 1; j <= sz; j++)
      if ((P[j] >> k) & 1) flag = true;
    int cnt[2] = {0};
    int tmp;
    for (int i = 1; i <= t[0]; i++) cnt[(dis[t[i]] >> k) & 1]++;
    tmp = (f(cnt[0]) + f(cnt[1])) % Mod;
    if (flag)
      tmp = 1ll * tmp * p2[r - 1] % Mod, tmp = 1ll * p2[k] * tmp % Mod,
      res = (res + tmp) % Mod;
    tmp = 1ll * cnt[0] * cnt[1] % Mod;
    if (flag)
      tmp = 1ll * tmp * p2[r - 1] % Mod;
    else
      tmp = 1ll * tmp * p2[r] % Mod;
    tmp = 1ll * p2[k] * tmp % Mod;
    res = (res + tmp) % Mod;
  }
  return res;
}
int main() {
  p2[0] = 1;
  for (int i = 1; i < 400010; i++) p2[i] = 1ll * p2[i - 1] * 2 % Mod;
  int x, y, ans = 0;
  long long z;
  scanf("%d%d", &n, &m);
  memset(head, -1, sizeof(head));
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%I64d", &x, &y, &z);
    Add_Edge(x, y, z);
    Add_Edge(y, x, z);
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      sz = t[0] = 0;
      Dfs(i, 0);
      Guass();
      ans = (ans + Solve()) % Mod;
    }
  printf("%d\n", ans);
  return 0;
}
