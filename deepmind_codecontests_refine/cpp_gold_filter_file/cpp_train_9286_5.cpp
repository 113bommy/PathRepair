#include <bits/stdc++.h>
std::multiset<int> st;
int f[501000], cMax[501000], g[501000], fa[501000];
int cnt[501000], s[3 * 501000], Max, ans[2 * 501000];
int h[501000], nxt[2 * 501000], to[2 * 501000], K = 0;
struct xxx {
  int t, w, v;
  xxx() {}
  xxx(int a, int b, int c) {
    t = a;
    w = b;
    v = c;
  }
} q[3 * 501000];
void add(int x) {
  s[cnt[x] + 501000]--;
  cnt[x]++;
  s[cnt[x] + 501000]++;
  Max = std::max(Max, cnt[x]);
}
void del(int x) {
  s[cnt[x] + 501000]--;
  cnt[x]--;
  s[cnt[x] + 501000]++;
  if (!s[Max + 501000]) Max--;
}
bool cmp(xxx a, xxx b) { return a.w > b.w; }
void ins(int u, int v) {
  nxt[++K] = h[u];
  h[u] = K;
  to[K] = v;
}
void dfs(int x, int fa) {
  ::fa[x] = fa;
  for (int i = h[x]; i; i = nxt[i]) {
    if (to[i] == fa) continue;
    dfs(to[i], x);
    if (f[to[i]] + 1 > f[x])
      cMax[x] = f[x], f[x] = f[to[i]] + 1;
    else
      cMax[x] = std::max(cMax[x], f[to[i]] + 1);
  }
}
void dfs2(int x, int fa) {
  for (int i = h[x]; i; i = nxt[i]) {
    if (to[i] == fa) continue;
    g[to[i]] = g[x] + 1;
    if (f[x] == f[to[i]] + 1)
      g[to[i]] = std::max(g[to[i]], cMax[x] + 1);
    else
      g[to[i]] = std::max(g[to[i]], f[x] + 1);
    dfs2(to[i], x);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    ins(u, v);
    ins(v, u);
  }
  dfs(1, 0);
  dfs2(1, 0);
  for (int i = 1; i <= n; i++) {
    int tot = 0;
    int S = 0;
    for (int j = h[i]; j; j = nxt[j]) {
      if (to[j] == fa[i]) continue;
      ++S;
      int v = to[j];
      for (int k = h[v]; k; k = nxt[k]) {
        if (to[k] == fa[v]) continue;
        q[++tot] = xxx(S, f[to[k]] + 1, 1);
      }
      q[++tot] = xxx(S, f[v] + 1, -1);
      q[++tot] = xxx(0, f[v] + 1, 1);
    }
    if (i > 1) q[++tot] = xxx(0, g[i], 1);
    std::sort(q + 1, q + tot + 1, cmp);
    int now = 0;
    s[501000] = 1e9;
    for (int j = 1; j <= tot; j++) {
      if (q[j].t == 0)
        now += q[j].v;
      else {
        if (q[j].v == 1)
          add(q[j].t);
        else
          del(q[j].t);
      }
      ans[2 * q[j].w] = std::max(ans[2 * q[j].w], now + Max);
    }
    for (int j = 1; j <= tot; j++)
      if (q[j].t) {
        if (q[j].v == 1)
          del(q[j].t);
        else
          add(q[j].t);
      }
  }
  for (int i = 1; i <= n; i++) {
    int tot = 0;
    for (int j = h[i]; j; j = nxt[j]) {
      if (to[j] == fa[i]) continue;
      q[++tot] = xxx(0, f[to[j]] + 1, 1);
    }
    if (i > 1) q[++tot] = xxx(0, g[i], 1);
    std::sort(q + 1, q + tot + 1, cmp);
    for (int j = 1; j <= tot; j++) {
      if (j && q[j - 1].w > q[j].w)
        ans[2 * q[j].w + 1] = std::max(ans[2 * q[j].w + 1], j);
      ans[2 * q[j].w - 1] = std::max(ans[2 * q[j].w - 1], j);
    }
  }
  for (int i = ((n & 1) ? n - 1 : n); i >= 1; i -= 2)
    ans[i] = std::max(ans[i], ans[i + 2]);
  for (int i = ((n & 1) ? n : n - 1); i >= 1; i -= 2)
    ans[i] = std::max(ans[i], ans[i + 2]);
  for (int i = 1; i <= n; i++)
    printf("%d ", (i == 1 ? 1 : 0) + (ans[i] == 0 ? 1 : ans[i]));
}
