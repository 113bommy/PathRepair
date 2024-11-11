#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long w = 0, flg = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') {
      flg = -1;
    }
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    w = w * 10 + ch - '0', ch = getchar();
  }
  return w * flg;
}
int head[100010], ednum;
struct edge {
  int nxt, to;
  long long w;
} ed[100010 * 2];
void add_Edge(int u, int v, long long w) {
  ednum++;
  ed[ednum].nxt = head[u], ed[ednum].to = v, ed[ednum].w = w;
  head[u] = ednum;
}
int n, Q, lgg[100010];
long long L;
long long mxl[100010], sec[100010];
void dfs1(int u, int dad) {
  for (int i = head[u]; i; i = ed[i].nxt) {
    int v = ed[i].to;
    if (v == dad) continue;
    dfs1(v, u);
    if (mxl[v] + ed[i].w > mxl[u])
      sec[u] = mxl[u], mxl[u] = mxl[v] + ed[i].w;
    else if (mxl[v] + ed[i].w > sec[u])
      sec[u] = mxl[v] + ed[i].w;
  }
}
void dfs2(int u, int dad, long long tot) {
  for (int i = head[u]; i; i = ed[i].nxt) {
    int v = ed[i].to;
    if (v == dad) continue;
    if (mxl[v] + ed[i].w != mxl[u])
      dfs2(v, u, max(mxl[u], tot) + ed[i].w);
    else
      dfs2(v, u, max(sec[u], tot) + ed[i].w);
  }
  mxl[u] = max(mxl[u], tot);
}
int rot, mxd[100010], hv[100010], dep[100010], fa[100010][20], tpf[100010];
vector<int> up[100010], dw[100010];
void dfs3(int u, int dad) {
  dep[u] = dep[dad] + 1, fa[u][0] = dad;
  for (int i = (1); i <= (19); i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
  for (int i = head[u]; i; i = ed[i].nxt) {
    int v = ed[i].to;
    if (v == dad) continue;
    dfs3(v, u);
    if (mxd[v] + 1 > mxd[u]) mxd[u] = mxd[v] + 1, hv[u] = v;
  }
}
void dfs4(int u, int topf, int dad) {
  tpf[u] = topf;
  if (hv[u]) dfs4(hv[u], topf, u);
  for (int i = head[u]; i; i = ed[i].nxt) {
    int v = ed[i].to;
    if (v == dad || v == hv[u]) continue;
    dfs4(v, v, u);
  }
}
int queryk(int u, int k) {
  if (!k) return u;
  int v = fa[u][lgg[k]];
  k ^= (1 << lgg[k]);
  if (dep[v] - dep[tpf[v]] >= k)
    return dw[tpf[v]][dep[v] - dep[tpf[v]] - k];
  else
    return up[tpf[v]][k - (dep[v] - dep[tpf[v]])];
}
int cf[100010], ans;
void dfs5(int u, int dad) {
  for (int i = head[u]; i; i = ed[i].nxt) {
    int v = ed[i].to;
    if (v == dad) continue;
    dfs5(v, u);
    cf[u] += cf[v];
  }
  ans = max(ans, cf[u]);
}
void solve() {
  for (int i = (1); i <= (n); i++) cf[i] = 0;
  L = read(), ans = 0;
  for (int i = (1); i <= (n); i++) {
    int l = 0, r = dep[i] - 1, re;
    while (l <= r) {
      int mid = (l + r) >> 1, anc = queryk(i, mid);
      if (mxl[i] - mxl[anc] <= L)
        re = anc, l = mid + 1;
      else
        r = mid - 1;
    }
    cf[i]++, cf[fa[re][0]]--;
  }
  dfs5(rot, 0);
  printf("%d\n", ans);
}
int main() {
  n = read(), lgg[0] = -1;
  for (int i = (1); i <= (n); i++) lgg[i] = lgg[i >> 1] + 1;
  for (int i = (1); i <= (n - 1); i++) {
    int u = read(), v = read();
    long long w = read();
    add_Edge(u, v, w), add_Edge(v, u, w);
  }
  dfs1(1, 0);
  dfs2(1, 0, 0);
  for (int i = (1); i <= (n); i++)
    if (!rot || mxl[i] < mxl[rot]) rot = i;
  dfs3(rot, 0);
  dfs4(rot, rot, 0);
  for (int i = (1); i <= (n); i++) {
    if (tpf[i] == i) {
      int p = i, q = i;
      for (int j = (1); j <= (mxd[i] + 1); j++) {
        dw[i].push_back(p), up[i].push_back(q);
        p = hv[p], q = fa[q][0];
      }
    }
  }
  Q = read();
  for (int i = (1); i <= (Q); i++) solve();
  return 0;
}
