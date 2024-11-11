#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int ch = getchar(), f = 0;
  int x = 0;
  while (ch < '0' || ch > '9') {
    f |= ch == '-';
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return f ? -x : x;
}
struct eric {
  int to, next;
} edge[500005 << 1];
int head[500005], size;
int n, m;
int a[500005];
int hson[500005], som[500005], Son, deep[500005], f[500005];
int num[1 << 22], stak[500005], top, rt;
int out[500005];
inline void add(int x, int y) {
  edge[++size].to = y;
  edge[size].next = head[x];
  head[x] = size;
}
void dfs1(int pos, int fa) {
  som[pos] = 1;
  deep[pos] = deep[fa] + 1;
  if (pos > 1) f[pos] = f[fa] ^ (1 << a[pos]);
  for (int i = head[pos]; i; i = edge[i].next) {
    int v = edge[i].to;
    if (v == fa) continue;
    dfs1(v, pos);
    som[pos] += som[v];
    if (som[hson[pos]] < som[v]) hson[pos] = v;
  }
}
void calc(int pos, int fa, int x) {
  if (x == 1) {
    stak[++top] = pos;
    if (num[f[pos]])
      out[rt] = max(out[rt], deep[pos] + num[f[pos]] - 2 * deep[rt]);
    for (int i = 0; i < 22; i++)
      if (num[f[pos] ^ (1 << i)])
        out[rt] =
            max(out[rt], deep[pos] + num[f[pos] ^ (1 << i)] - 2 * deep[rt]);
  } else
    num[f[pos]] = 0;
  for (int i = head[pos]; i; i = edge[i].next) {
    int v = edge[i].to;
    if (v == fa || v == Son) continue;
    calc(v, pos, x);
  }
}
void dfs2(int pos, int fa, int type) {
  for (int i = head[pos]; i; i = edge[i].next) {
    int v = edge[i].to;
    if (v == fa || v == hson[pos]) continue;
    dfs2(v, pos, 0);
    out[pos] = max(out[pos], out[v]);
  }
  if (hson[pos])
    dfs2(hson[pos], pos, 1), Son = hson[pos],
                             out[pos] = max(out[pos], out[Son]);
  rt = pos;
  for (int i = head[pos]; i; i = edge[i].next) {
    int v = edge[i].to;
    if (v == fa || v == Son) continue;
    top = 0;
    calc(v, pos, 1);
    for (int j = 1; j <= top; j++)
      num[f[stak[j]]] = max(num[f[stak[j]]], deep[stak[j]]);
  }
  if (num[f[pos]]) out[pos] = max(out[pos], num[f[pos]] - deep[pos]);
  for (int i = 0; i < 22; i++)
    if (num[f[pos] ^ (1 << i)])
      out[pos] = max(out[pos], num[f[pos] ^ (1 << i)] - deep[pos]);
  num[f[pos]] = max(num[f[pos]], deep[pos]);
  Son = 0;
  if (!type) calc(pos, fa, -1);
}
int main() {
  n = read();
  for (int i = 2; i <= n; i++) {
    int f = read(), ch = getchar();
    while (ch < 'a' || ch > 'v') ch = getchar();
    a[i] = ch - 'a';
    add(f, i);
  }
  dfs1(1, 0);
  dfs2(1, 0, 0);
  for (int i = 1; i <= n; i++) printf("%d ", out[i]);
  printf("\n");
  return 0;
}
