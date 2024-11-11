#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= 1000000007;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
  }
  return res;
}
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n;
vector<int> g[500000];
int s[500000], t[500000], tmps[500000], tmpt[500000];
int fa[500000], dep[500000], cir[500000];
void dfs(int u) {
  for (auto v : g[u]) {
    if (v == fa[u] || cir[v]) continue;
    fa[v] = u;
    dep[v] = dep[u] + 1;
    dfs(v);
  }
}
int vis[500000], tmp[500000], on[500000];
int ansu, ansv;
int main() {
  n = read();
  int ss, tt;
  for (int i = 1; i <= n; i++) {
    s[i] = read();
    if (s[i] == 0) ss = i;
  }
  for (int i = 1; i <= n; i++) {
    t[i] = read();
    if (t[i] == 0) tt = i;
  }
  for (int i = 1; i < n; i++) {
    int u = read(), v = read();
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(tt);
  int now = ss;
  for (int i = 1; i <= n; i++) tmp[i] = s[i];
  while (now != tt) {
    swap(tmp[now], tmp[fa[now]]);
    now = fa[now];
  }
  int ok = 0;
  for (int i = 1; i <= n; i++) ok |= tmp[i] != t[i];
  if (!ok) {
    printf("0 %d\n", dep[ss]);
    return 0;
  }
  for (int i = 1; i <= n; i++) vis[i] = tmp[i] != t[i];
  int a[3], b[3], tot;
  for (tot = 0; tot <= 2;) {
    int k = 0;
    for (int i = 1; i <= n; i++)
      if (vis[i]) {
        k = i;
        break;
      }
    if (!k) break;
    int now = k;
    while (true) {
      vis[now] = 0;
      int mark = 0;
      for (auto v : g[now]) {
        if (vis[v]) {
          now = v;
          mark = 1;
          break;
        }
      }
      if (!mark) break;
    }
    a[++tot] = now;
    now = k;
    while (true) {
      vis[now] = 0;
      int mark = 0;
      for (auto v : g[now]) {
        if (vis[v]) {
          now = v;
          mark = 1;
          break;
        }
      }
      if (!mark) break;
    }
    b[tot] = now;
  }
  if (tot > 2) {
    puts("-1");
    return 0;
  }
  if (tot == 1) {
    int &u = a[1], &v = b[1];
    if (dep[u] > dep[v]) swap(u, v);
    int now = v;
    while (now && now != u) now = fa[now];
    if (!now) {
      puts("-1");
      return 0;
    }
    g[fa[u]].push_back(v), g[v].push_back(fa[u]);
    ansu = fa[u], ansv = v;
    now = v;
    while (now != fa[u]) cir[now] = 1, now = fa[now];
    cir[fa[u]] = 1;
  } else {
    for (int i = 1; i <= 2; i++) {
      int &u = a[i], &v = b[i];
      if (dep[u] > dep[v]) swap(u, v);
      int now = v;
      while (now && now != u) now = fa[now];
      if (!now) {
        puts("-1");
        return 0;
      }
    }
    if (fa[a[1]] != fa[a[2]]) {
      puts("-1");
      return 0;
    }
    g[b[1]].push_back(b[2]), g[b[2]].push_back(b[1]);
    ansu = b[1], ansv = b[2];
    for (int i = 1; i <= 2; i++) {
      int now = b[i];
      while (now != fa[a[i]]) cir[now] = 1, now = fa[now];
      cir[fa[a[i]]] = 1;
    }
  }
  for (int i = 1; i <= n; i++)
    if (cir[i]) {
      fa[i] = 0;
      dfs(i);
    }
  long long ans = 0;
  while (!cir[ss]) swap(s[ss], s[fa[ss]]), ss = fa[ss], ans++;
  while (!cir[tt]) swap(t[tt], t[fa[tt]]), tt = fa[tt], ans++;
  now = ss, tot = 0;
  while (true) {
    cir[now] = 0;
    on[tot++] = now;
    int tmp = now;
    for (auto v : g[now]) {
      if (cir[v]) {
        now = v;
        break;
      }
    }
    if (now == tmp) break;
  }
  long long res = INF;
  int pos = 0;
  for (int i = 0; i < tot; i++)
    if (on[i] == tt) pos = i;
  for (int _ = -1; _ <= 1; _ += 2) {
    memcpy(tmps, s, sizeof s);
    memcpy(tmpt, t, sizeof t);
    int tmp = 0;
    if (pos)
      for (int i = pos; i < tot && i; i += _)
        swap(tmpt[on[i]], tmpt[on[(i + _) % tot]]), tmp++;
    int ii = 1, jj = 0, circle;
    for (int i = 1; i < tot; i++)
      if (tmpt[on[i]] == tmps[on[1]]) jj = i;
    circle = jj;
    for (int i = 1; i < tot; i++) {
      if (tmps[on[jj]] != tmpt[on[ii]]) {
        puts("-1");
        return 0;
      }
      ii += 1;
      jj += 1;
      if (ii == tot) ii = 1;
      if (jj == tot) jj = 1;
    }
    chkmin(res, 1LL * tot * (min(tot - circle, circle - 1)) + tmp);
  }
  if (ansu > ansv) swap(ansu, ansv);
  printf("%d %d %lld\n", ansu, ansv, ans + res);
  return 0;
}
