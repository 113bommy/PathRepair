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
int n, Q, lgg[100010], rot;
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
      sec[i] = mxl[v] + ed[i].w;
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
int cf[100010], sta[100010], tpf, ans, fa[100010];
void dfs3(int u, int dad) {
  sta[++tpf] = u, fa[u] = dad;
  int l = 1, r = tpf, re = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (mxl[u] - mxl[sta[mid]] <= L)
      r = mid - 1, re = sta[mid];
    else
      l = mid + 1;
  }
  cf[u]++, cf[fa[re]]--;
  for (int i = head[u]; i; i = ed[i].nxt) {
    int v = ed[i].to;
    if (v == dad) continue;
    dfs3(v, u);
    cf[u] += cf[v];
  }
  ans = max(ans, cf[u]);
  tpf--;
}
void solve() {
  L = read();
  for (int i = (1); i <= (n); i++) cf[i] = 0;
  ans = 0;
  dfs3(rot, 0);
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
  Q = read();
  for (int i = (1); i <= (Q); i++) solve();
  return 0;
}
