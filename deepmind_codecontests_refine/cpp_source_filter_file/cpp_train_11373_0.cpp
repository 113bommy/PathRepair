#include <bits/stdc++.h>
long long gi() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) f ^= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f ? x : -x;
}
std::mt19937 rnd(time(NULL));
template <class T>
void cxk(T& a, T b) {
  a = a > b ? a : b;
}
template <class T>
void cnk(T& a, T b) {
  a = a < b ? a : b;
}
int n, m, fir[200010], dis[200010], nxt[200010], id;
std::vector<int> G[200010], rG[200010];
void link(int a, int b) {
  nxt[++id] = fir[a], fir[a] = id, dis[id] = b;
  G[a].push_back(b);
  rG[b].push_back(a);
}
int dfn[200010], low[200010], ins[200010];
void tarjan(int x) {
  dfn[x] = low[x] = ++dfn[0];
  ins[x] = 1;
  for (int i = fir[x]; i; i = nxt[i])
    if (!dfn[dis[i]])
      tarjan(dis[i]), cnk(low[x], low[dis[i]]);
    else if (ins[dis[i]])
      cnk(low[x], dfn[dis[i]]);
  ins[x] = 0;
  if (low[x] < dfn[x]) puts("-1"), exit(0);
}
int que[200010], hd, tl, in[200010], minl[200010], minr[200010];
void work(std::vector<int> G[200010], int min[200010]) {
  memset(in, 0, sizeof in);
  hd = tl = 0;
  for (int i = 1; i <= n; ++i)
    for (int j : G[i]) ++in[j];
  for (int i = 1; i <= n; ++i)
    if (!in[i]) que[tl++] = i;
  while (hd ^ tl) {
    int x = que[hd++];
    for (int i : G[x]) {
      cnk(min[i], min[x]);
      if (!--in[i]) que[tl++] = dis[i];
    }
  }
}
int main() {
  n = gi(), m = gi();
  int a, b;
  for (int i = 1; i <= m; ++i) a = gi(), b = gi(), link(a, b);
  for (int i = 1; i <= n; ++i)
    if (!dfn[i]) tarjan(i);
  for (int i = 1; i <= n; ++i) minl[i] = minr[i] = i;
  work(G, minl), work(rG, minr);
  int sum = 0;
  for (int i = 1; i <= n; ++i)
    if (std::min(minl[i], minr[i]) < i) ++sum;
  printf("%d\n", n - sum);
  for (int i = 1; i <= n; ++i)
    putchar(std::min(minl[i], minr[i]) == i ? 'A' : 'E');
  return 0;
}
