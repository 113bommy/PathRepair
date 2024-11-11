#include <bits/stdc++.h>
using namespace std;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= 1000000007;
  for (; b; b >>= 1) {
    if (b & 1) res = res * 1 % 1000000007;
    a = a * a % 1000000007;
  }
  return res;
}
int fst[200010], nxt[500010], vv[500010], cost[500010], e;
int dfn[200010], fa[200010], cnt[200010], dep[200010];
int mx1[200010], mx2[200010], id1[200010], id2[200010], ans, ansu, ansv, nowu,
    nowv, nowa;
int sz[200010], ch[200010], chnum, del[200010], rt;
int ll, rr, n, m, fckn, d1, d2;
void init() {
  e = 0;
  memset(fst, -1, sizeof fst);
}
void add(int u, int v, int c) {
  vv[e] = v, nxt[e] = fst[u], cost[e] = c, fst[u] = e++;
  vv[e] = u, nxt[e] = fst[v], cost[e] = c, fst[v] = e++;
}
bool check() {
  static int q[200010];
  int h = 0, t = 0;
  int mxd = d1;
  for (int i = 0; i <= d2; i++) {
    while (mxd >= 0 && mxd + i >= ll) {
      while (h < t && mx1[mxd] >= mx1[q[t - 1]]) t--;
      q[t++] = mxd;
      mxd--;
    }
    while (h < t && q[h] + i > rr) h++;
    if (h < t && mx1[q[h]] + mx2[i] >= 0) {
      nowu = id1[q[h]];
      nowv = id2[i];
      return true;
    }
  }
  return false;
}
void dfs(int u, int ff, int mid, int c, int d) {
  dfn[++fckn] = u;
  fa[u] = ff;
  dep[u] = d, cnt[u] = c;
  sz[u] = 1;
  for (int i = fst[u]; ~i; i = nxt[i]) {
    int v = vv[i];
    if (v == ff || del[v]) continue;
    dfs(v, u, mid, c + (cost[i] >= mid ? 1 : -1), d + 1);
    sz[u] += sz[v];
  }
}
bool cmp(int a, int b) { return sz[a] < sz[b]; }
void solve(int rt) {
  fckn = 0;
  dfs(rt, -1, -1, 0, 0);
  int zp = 0, mi = 0x3f3f3f3f;
  for (int i = 1; i <= fckn; i++) {
    int u = dfn[i];
    int tmp = sz[rt] - sz[u];
    for (int j = fst[u]; ~j; j = nxt[j]) {
      int v = vv[j];
      if (v == fa[u] || del[v]) continue;
      tmp = max(tmp, sz[v]);
    }
    if (tmp < mi) mi = tmp, zp = u;
  }
  chnum = 0;
  rt = zp;
  del[rt] = 1;
  fckn = 0;
  dfs(rt, -1, -1, 0, 0);
  for (int i = fst[rt]; ~i; i = nxt[i]) {
    int v = vv[i];
    if (del[v]) continue;
    ch[chnum++] = v;
  }
  sort(ch, ch + chnum, cmp);
  bool ok;
  int l = -1, r = 1e9 + 1;
  while (l < r - 1) {
    int mid = (l + r) / 2;
    d1 = 0;
    mx1[0] = 0, id1[0] = rt;
    for (int i = fst[rt]; ~i; i = nxt[i]) {
      int v = vv[i];
      if (del[v]) continue;
      cnt[v] = cost[i] >= mid ? 1 : -1;
    }
    ok = 0;
    for (int i = 0; i < chnum; i++) {
      int u = ch[i];
      fckn = 0;
      d2 = 0;
      dfs(u, -1, mid, cnt[u], 1);
      for (int j = 1; j <= fckn; j++) d2 = max(d2, dep[dfn[j]]);
      for (int j = 0; j <= d2; j++) mx2[j] = -0x3f3f3f3f;
      for (int j = 1; j <= fckn; j++) {
        int v = dfn[j];
        if (cnt[v] > mx2[dep[v]]) {
          mx2[dep[v]] = cnt[v];
          id2[dep[v]] = v;
        }
      }
      if (check()) {
        ok = 1;
        break;
      }
      for (int j = 0; j <= d2; j++) {
        if (j > d1 || mx2[j] > mx1[j]) {
          mx1[j] = mx2[j];
          id1[j] = id2[j];
        }
      }
      d1 = max(d1, d2);
    }
    if (ok) {
      l = mid;
    } else
      r = mid;
  }
  if (l >= ans) ans = l, ansu = nowu, ansv = nowv;
  for (int i = fst[rt]; ~i; i = nxt[i]) {
    int v = vv[i];
    if (!del[v]) solve(v);
  }
}
int main() {
  scanf("%d%d%d", &n, &ll, &rr);
  init();
  for (int i = 1; i < n; i++) {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    add(u, v, c);
  }
  solve(1);
  printf("%d %d\n", ansu, ansv);
  return 0;
}
