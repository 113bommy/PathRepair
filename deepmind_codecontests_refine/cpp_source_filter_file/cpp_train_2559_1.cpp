#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7, M = 27, Q = 2e4 + 7;
vector<int> z[N], s[N], f[N], f1[N];
map<pair<int, int>, int> vt[N];
int n, m, c, k, q, rt, p1, p2, opt, s1[N], s2[N], dep[Q], siz1[N], len[N],
    e[Q][M], ov[N], ft[N], ct[N], siz[N], ch[N][M];
bool fl[N];
vector<int> v[N], w[N];
inline int getlca(int u, int t) {
  if (dep[u] < dep[t]) swap(u, t);
  int z = dep[u] - dep[t];
  for (int i = 18; i >= 0; i--)
    if ((1 << i) & z) u = e[u][i];
  if (u == t) return u;
  for (int i = 18; i >= 0; i--)
    if (e[u][i] != e[t][i]) u = e[u][i], t = e[t][i];
  return e[u][0];
}
inline int jmp(int u, int t) {
  for (int i = 18; i >= 0; i--)
    if ((1 << i) & t) u = e[u][i];
  return u;
}
struct node {
  int p, g[N], e1[Q][M], e2[Q][M];
  inline void dfs(int u, int fa) {
    for (int x = 1; x <= 20; x++) {
      e1[u][x] =
          e1[u][x - 1] + 1ll * e1[e[u][x - 1]][x - 1] * g[(1 << (x - 1))] % p;
      e2[u][x] =
          e2[e[u][x - 1]][x - 1] + 1ll * e2[u][x - 1] * g[(1 << (x - 1))] % p;
    }
    for (int i = 0; i < v[u].size(); i++) {
      int x = v[u][i];
      if (fa == x) continue;
      e1[x][0] = w[u][i], e2[x][0] = w[u][i], dfs(x, u);
    }
  }
  inline int gethsh(int a, int b) {
    int x = getlca(a, b);
    int s = 0, w = 0, z = dep[a] - dep[x];
    for (int i = 18; i >= 0; i--)
      if (z & (1 << i))
        w = (w + 1ll * g[s] * e1[a][i]) % p, s += (1 << i), a = e[a][i];
    z = dep[b] - dep[x];
    s1[0] = 0, s2[0] = 0;
    for (int i = 18; i >= 0; i--)
      if (z & (1 << i))
        s1[++s1[0]] = e2[b][i], s2[++s2[0]] = (1 << i), b = e[b][i];
    for (int i = s1[0]; i > 0; i--)
      w = (w + 1ll * g[s] * s1[i]) % p, s += s2[i];
    return w;
  }
} a, b;
inline pair<int, int> gethsh(int x, int y, int c) {
  int e = getlca(x, y);
  if (dep[x] - dep[e] >= c)
    y = jmp(x, c);
  else
    y = jmp(y, (dep[y] - dep[e]) - (c - (dep[x] - dep[e])));
  return make_pair(a.gethsh(x, y), b.gethsh(x, y));
}
inline int getval(int x, int y, int c) {
  int e = getlca(x, y);
  if (dep[x] - dep[e] > c) {
    y = jmp(x, c);
    return a.e1[y][0];
  } else {
    y = jmp(y, (dep[y] - dep[e]) - (c - (dep[x] - dep[e])) - 1);
    return a.e1[y][0];
  }
}
inline void dfs(int u, int fa) {
  e[u][0] = fa;
  for (int x = 1; x <= 20; x++) e[u][x] = e[e[u][x - 1]][x - 1];
  for (int i = 0; i < v[u].size(); i++) {
    int x = v[u][i];
    if (fa == x) continue;
    dep[x] = dep[u] + 1, dfs(x, u);
  }
}
inline void dfs1(int u, int fa) {
  siz1[u] = 1;
  for (int i = 0; i < v[u].size(); i++) {
    int x = v[u][i];
    if (fl[x] || x == fa) continue;
    dfs1(x, u), siz1[u] += siz1[x];
  }
}
inline void dfs2(int u, int fa) {
  int og = 0;
  for (int i = 0; i < v[u].size(); i++) {
    int x = v[u][i];
    if (fl[x] || x == fa) continue;
    dfs2(x, u), og = max(og, siz1[x]);
  }
  og = max(og, siz1[c] - siz1[u]);
  if (og < p1) p1 = og, p2 = u;
}
inline int getroot(int u) {
  c = u, p1 = n, p2 = 0, dfs1(u, 0), dfs2(u, 0);
  return p2;
}
inline void dfs3(int u, int fa, int g) {
  z[g].push_back(u), ft[u] = q, f[u].push_back(q);
  for (int i = 0; i < v[u].size(); i++) {
    int x = v[u][i];
    if (fl[x] || x == fa) continue;
    if (!ch[g][w[u][i]]) ch[g][w[u][i]] = ++k;
    dfs3(x, u, ch[g][w[u][i]]);
  }
}
inline void dfs4(int u, int x, int y, int xa, int xb) {
  siz[u] = z[u].size(), len[u] = s[rt].size();
  for (int i = 0; i < z[u].size(); i++) s[rt].push_back(z[u][i]);
  vt[rt][make_pair(x, y)] = u;
  for (int i = 1; i <= 26; i++)
    if (ch[u][i])
      dfs4(ch[u][i], (x + 1ll * i * xa) % a.p, (y + 1ll * i * xb) % b.p,
           29ll * xa % a.p, 29ll * xb % b.p),
          siz[u] += siz[ch[u][i]];
}
inline void solve(int u) {
  u = getroot(u), fl[u] = 1, k++, z[k].push_back(u), ft[u] = 0;
  int vt = k;
  for (int i = 0; i < v[u].size(); i++) {
    int x = v[u][i];
    if (fl[x]) continue;
    if (!ch[vt][w[u][i]]) ch[vt][w[u][i]] = ++k;
    q++, ct[q] = u, dfs3(x, u, ch[vt][w[u][i]]);
  }
  rt = u, dfs4(vt, 0, 0, 1, 1);
  for (int i = 0; i < s[u].size(); i++)
    if (ft[s[u][i]] > 0) f1[ft[s[u][i]]].push_back(i + 1);
  for (int i = 0; i < v[u].size(); i++) {
    int x = v[u][i];
    if (fl[x]) continue;
    solve(x);
  }
}
inline int getans(int u, int t, int zk) {
  int a = getlca(u, t), b = getlca(u, zk);
  int d1 = dep[u] + dep[t] - dep[a] * 2, d2 = dep[u] + dep[zk] - dep[b] * 2;
  int l = 0, r = min(d1, d2), pos = 0, pot;
  while (l <= r) {
    int d = (l + r) >> 1;
    pair<int, int> f1 = gethsh(u, t, d), f2 = gethsh(u, zk, d);
    if (f1.first == f2.first && f1.second == f2.second)
      pos = d, l = d + 1;
    else
      r = d - 1;
  }
  if (pos < min(d1, d2)) {
    int a = getval(u, t, pos), b = getval(u, zk, pos);
    if (a > b) return s[zk].size();
    return 0;
  }
  if (dep[u] - dep[a] >= min(d1, d2))
    u = jmp(u, min(d1, d2));
  else
    u = jmp(t, (dep[t] - dep[a]) - (min(d1, d2) - (dep[u] - dep[a])));
  d1 -= d2, l = 0, r = d1, pos = 0, pot = 0;
  while (l <= r) {
    int d = (l + r) >> 1, x = vt[zk][gethsh(u, t, d)];
    if (x > 0)
      pot = x, pos = d, l = d + 1;
    else
      r = d - 1;
  }
  if (pos == d1)
    return len[pot];
  else {
    int ans = len[pot] + z[pot].size(), x = getval(u, t, pos);
    for (int i = 1; i < x; i++)
      if (ch[pot][i]) ans += siz[ch[pot][i]];
    return ans;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  int u, t;
  char s[3];
  a.p = 998244353, b.p = 1e9 + 9, a.g[0] = 1, b.g[0] = 1;
  for (int i = 1; i <= n; i++)
    a.g[i] = a.g[i - 1] * 29ll % a.p, b.g[i] = b.g[i - 1] * 29ll % b.p;
  for (int i = 1; i < n; i++)
    scanf("%d%d%s", &u, &t, s + 1), v[u].push_back(t), v[t].push_back(u),
        w[u].push_back(s[1] - 'a' + 1), w[t].push_back(s[1] - 'a' + 1);
  solve(1), dfs(1, 0), a.dfs(1, 0), b.dfs(1, 0);
  while (m--) {
    scanf("%d%d", &u, &t);
    int ans = getans(u, t, u) - 1;
    for (int i = 0; i < f[u].size(); i++) {
      int x = ct[f[u][i]], c = getans(u, t, x);
      ans += c;
      int l = 1, r = f1[f[u][i]].size(), pos = 0;
      while (l <= r) {
        int d = (l + r) >> 1;
        if (f1[f[u][i]][d - 1] <= c)
          pos = d, l = d + 1;
        else
          r = d - 1;
      }
      ans -= pos;
    }
    printf("%d\n", ans);
  }
}
