#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int mod = 1e9 + 7;
int tot = 0, goal;
map<unsigned int, int> mp;
struct DPAM {
  int f[5];
  unsigned int ha;
} F[1123], Gs, Gab;
DPAM start() {
  DPAM res;
  res.ha = 1, res.f[0] = res.f[1] = res.f[2] = res.f[3] = res.f[4] = 0;
  return res;
}
void Getha(DPAM &P) {
  for (int i = 0, iE = 31; i <= iE; i++) {
    int sum = 0;
    for (int j = 0, jE = 4; j <= jE; j++)
      if (i & (1 << j)) sum ^= P.f[j];
    P.ha |= (1LL << sum);
  }
}
DPAM Getto(DPAM aa, int bb) {
  for (int i = 4, iE = 0; i >= iE; i--)
    if ((bb >> i) & 1) {
      if (!aa.f[i]) aa.f[i] = bb;
      bb ^= aa.f[i];
    }
  Getha(aa);
  return aa;
}
int TO[1123][32];
void bfs() {
  queue<int> q;
  q.push(1), mp[1] = ++tot, F[1] = start();
  while (!q.empty()) {
    int u = q.front();
    DPAM fu = F[u];
    q.pop();
    for (int i = 0, iE = 31; i <= iE; i++) {
      DPAM to = Getto(fu, i);
      if (to.ha == fu.ha)
        TO[u][i] = 0;
      else {
        if (mp[to.ha])
          TO[u][i] = mp[to.ha];
        else {
          mp[to.ha] = TO[u][i] = ++tot, F[tot] = to, q.push(tot);
          if (to.ha == 0u - 1) goal = tot;
        }
      }
    }
  }
}
int sav[1123];
void zy(int *dp, int *savab, DPAM G) {
  for (int i = 1, iE = tot; i <= iE; i++) savab[i] = dp[i], sav[i] = 0;
  for (int i = 4, iE = 0; i >= iE; i--)
    if (G.f[i]) {
      for (int j = 1, jE = tot; j <= jE; j++)
        if (TO[j][G.f[i]]) (sav[TO[j][G.f[i]]] += savab[j]) %= mod;
      for (int j = 1, jE = tot; j <= jE; j++) savab[j] = sav[j], sav[j] = 0;
    }
}
int n, m;
int dp[1123], savs[1123], savab[1123];
int head[N], edge_id;
struct node {
  int to, next, val;
} e[N << 1];
void add_edge(int u, int v, int val) {
  ++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, e[edge_id].val = val,
             head[u] = edge_id;
}
bool to1[N], vis[N];
int dis[N], mat[N], matv[N], toval[N];
bool dfs(int x, int fa, DPAM &f) {
  vis[x] = 1;
  for (int i = head[x]; i; i = e[i].next) {
    int v = e[i].to;
    if (v == 1 || v == fa || !vis[v]) continue;
    unsigned int now = f.ha;
    f = Getto(f, e[i].val ^ dis[x] ^ dis[v]);
    if (now == f.ha) return 0;
  }
  for (int i = head[x]; i; i = e[i].next) {
    int v = e[i].to;
    if (v == 1 || v == fa || vis[v]) continue;
    dis[v] = (dis[x] ^ e[i].val);
    if (!dfs(v, x, f)) return 0;
  }
  return 1;
}
int main() {
  bfs();
  scanf("%d%d", &n, &m);
  for (int i = 1, iE = m; i <= iE; i++) {
    int u, v, val;
    scanf("%d%d%d", &u, &v, &val);
    add_edge(u, v, val), add_edge(v, u, val);
  }
  for (int i = head[1]; i; i = e[i].next) {
    int v = e[i].to;
    to1[v] = 1, toval[v] = e[i].val;
    for (int j = head[v]; j; j = e[j].next) {
      int vto = e[j].to;
      if (to1[vto]) mat[vto] = v, matv[v] = matv[vto] = e[j].val;
    }
  }
  dp[1] = 1;
  for (int t = head[1]; t; t = e[t].next) {
    int v = e[t].to;
    if (mat[v] == -1) continue;
    Gs = Gab = start();
    bool flag = dfs(v, -1, Gs), flags;
    for (int i = 1, iE = tot; i <= iE; i++) savs[i] = savab[i] = 0;
    if (flag) zy(dp, savs, Gs);
    if (!mat[v]) {
      for (int i = 1, iE = tot; i <= iE; i++) (dp[i] += savs[i]) %= mod;
      continue;
    }
    Gab = Gs;
    unsigned int nowab = Gab.ha;
    Gab = Getto(Gab, matv[v] ^ toval[v] ^ toval[mat[v]]);
    flags = (Gab.ha != nowab);
    if (flag & flags) zy(dp, savab, Gab);
    for (int i = 1, iE = tot; i <= iE; i++)
      (dp[i] += 2ll * savs[i] % mod) %= mod, (dp[i] += savab[i]) %= mod;
    mat[mat[v]] = -1;
  }
  int ans = 0;
  for (int i = 1, iE = tot; i <= iE; i++) ans += dp[i];
  printf("%d\n", ans);
  if (dp[0]) assert(0);
  return 0;
}
