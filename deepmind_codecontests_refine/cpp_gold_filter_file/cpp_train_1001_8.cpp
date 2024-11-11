#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 100007;
struct eT {
  void setd(int _u, int _v, int _l) { u = _u, v = _v, last = _l; }
  int u, v, last;
} edge[MAXN * 2];
int n, m;
int ke, la[MAXN];
long long c[MAXN];
bool vis[MAXN];
long long ans[MAXN];
int si[MAXN];
bool ins[MAXN];
int stk[MAXN], top;
int kc, cyc[MAXN], ce[MAXN];
void init();
void input();
void work();
bool findcyc(int now, int fa);
long long dfs(int now, int fe);
int main() {
  init();
  input();
  work();
}
void init() { ios::sync_with_stdio(false); }
void input() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%I64d", &c[i]);
  ke = 0;
  memset(la, -1, sizeof(la));
  int u, v;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &u, &v);
    edge[ke].setd(u, v, la[u]);
    la[u] = ke++;
    edge[ke].setd(v, u, la[v]);
    la[v] = ke++;
  }
}
void work() {
  if (findcyc(1, -1)) {
    memset(vis, false, sizeof(vis));
    dfs(cyc[1], -1);
    long long del = c[cyc[1]] / 2;
    cyc[kc + 1] = cyc[1];
    for (int i = 1; i <= kc; ++i) {
      int now = cyc[i];
      for (int j = la[now]; ~j; j = edge[j].last) {
        if (edge[j].v == cyc[i + 1]) {
          if (i & 1)
            ans[j >> 1] += del;
          else
            ans[j >> 1] -= del;
        }
      }
    }
  } else {
    memset(vis, false, sizeof(vis));
    dfs(1, -1);
    if (c[1]) {
      printf("NO\n");
      return;
    }
  }
  printf("YES\n");
  for (int i = 0; i < m; ++i) printf("%I64d\n", ans[i]);
}
bool findcyc(int now, int fa) {
  if (vis[now]) {
    if (ins[now] && ((top - si[now]) & 1)) {
      kc = top - si[now];
      for (int i = 1; i <= kc; ++i) cyc[i] = stk[si[now] + i - 1];
      return true;
    } else
      return false;
  }
  vis[now] = true;
  ins[now] = true;
  si[now] = top;
  stk[top++] = now;
  for (int i = la[now]; ~i; i = edge[i].last) {
    if (edge[i].v ^ fa) {
      if (findcyc(edge[i].v, now)) return true;
    }
  }
  ins[now] = false;
  --top;
  return false;
}
long long dfs(int now, int fe) {
  if (vis[now]) return 0;
  vis[now] = true;
  for (int i = la[now]; ~i; i = edge[i].last) {
    c[now] -= dfs(edge[i].v, i >> 1);
  }
  if (~fe) {
    long long ret = c[now];
    ans[fe] += c[now];
    c[now] = 0;
    return ret;
  } else
    return 0;
}
