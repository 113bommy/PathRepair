#include <bits/stdc++.h>
using namespace std;
struct Graph2 {
  int head[100010], next[100010], to[100010], w[100010], c[100010], tot;
  void clear(int N) {
    int i;
    for (i = 1; i <= N; i++) head[i] = 0;
    for (i = 2; i <= tot; i++) next[i] = 0;
    tot = 1;
  }
  void add(int a, int b, int ww, int cc) {
    to[++tot] = b;
    next[tot] = head[a];
    w[tot] = ww;
    c[tot] = cc;
    head[a] = tot;
  }
  void adde(int a, int b, int ww, int cc) {
    add(a, b, ww, cc);
    add(b, a, -ww, 0);
  }
} G;
struct ISAP {
  int S, T, last[100010], d[100010], num[100010], Exit;
  void init(int N) {
    for (int i = 1; i <= N; i++) d[i] = num[i] = 0;
    num[0] = N;
    Exit = 0;
  }
  int dfs(Graph2& G, int pos, int in) {
    int flow = 0, t;
    if (pos == T) return in;
    for (int& p = last[pos]; p; p = G.next[p])
      if (G.c[p] and d[G.to[p]] + 1 == d[pos]) {
        flow += t = dfs(G, G.to[p], min(in - flow, G.c[p]));
        G.c[p] -= t, G.c[p ^ 1] += t;
        if (Exit or in == flow) return flow;
      }
    Exit = --num[d[pos]] == 0;
    ++num[++d[pos]];
    last[pos] = G.head[pos];
    return flow;
  }
  int maxflow(Graph2& G) {
    int ans(0);
    while (!Exit) ans += dfs(G, S, 0x3f3f3f3f);
    return ans;
  }
} isap;
struct Lisan {
  int tmp[100010], tot;
  void clear() { tot = 0; }
  void insert(int x) { tmp[++tot] = x; }
  void run() {
    sort(tmp + 1, tmp + tot + 1);
    tot = unique(tmp + 1, tmp + tot + 1) - tmp - 1;
  }
  void lisan(int* a, int len) {
    for (int i = 1; i <= len; i++)
      a[i] = lower_bound(tmp + 1, tmp + tot + 1, a[i]) - tmp;
  }
  int lisan(int x) { return lower_bound(tmp + 1, tmp + tot + 1, x) - tmp; }
} row, col;
int n, m, X1[100010], Y1[100010], X2[100010], Y2[100010];
int main() {
  int i, j, k;
  cin >> n >> m;
  for (i = 1; i <= m; i++) {
    cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
    row.insert(X1[i]), row.insert(X2[i] + 1);
    col.insert(Y1[i]), col.insert(Y2[i] + 1);
  }
  row.run(), col.run();
  isap.S = row.tot + col.tot + 10;
  isap.T = isap.S + 1;
  G.clear(isap.T);
  for (i = 1; i < row.tot; i++)
    G.adde(isap.S, i, 0, row.tmp[i + 1] - row.tmp[i]);
  for (i = 1; i < col.tot; i++)
    G.adde(row.tot + i, isap.T, 0, col.tmp[i + 1] - col.tmp[i]);
  for (i = 1; i <= m; i++) {
    for (j = row.lisan(X1[i]); row.tmp[j] < X2[i] + 1; j++)
      for (k = col.lisan(Y1[i]); col.tmp[k] < Y2[i] + 1; k++)
        G.adde(j, row.tot + k, 0, 0x3f3f3f3f);
  }
  isap.init(isap.T);
  cout << isap.maxflow(G);
  return 0;
}
