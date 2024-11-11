#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
struct DL {
  int c, q;
} a[maxn];
inline bool operator<(DL a, DL b) { return a.q == b.q ? a.c < b.c : a.q > b.q; }
int ch[maxn][2], ad[maxn], de[maxn], v[maxn], as[maxn], r[maxn], n, m, rt,
    st[maxn], tp;
inline void pd(int x) {
  if (ch[x][0])
    de[ch[x][0]] += de[x], v[ch[x][0]] -= de[x], ad[ch[x][0]] += ad[x],
        as[ch[x][0]] += ad[x];
  if (ch[x][1])
    de[ch[x][1]] += de[x], v[ch[x][1]] -= de[x], ad[ch[x][1]] += ad[x],
        as[ch[x][1]] += ad[x];
  ad[x] = de[x] = 0;
}
void split(int o, int &x, int &y, int va) {
  if (!o) {
    x = y = 0;
    return;
  }
  pd(o);
  if (v[o] < va)
    x = o, split(ch[x][1], ch[x][1], y, va);
  else
    y = o, split(ch[y][0], x, ch[y][0], va);
}
int merge(int x, int y) {
  if (!x || !y) return x | y;
  pd(x);
  pd(y);
  if (r[x] > r[y])
    return ch[x][1] = merge(ch[x][1], y), x;
  else
    return ch[y][0] = merge(x, ch[y][0]), y;
}
int insert(int o, int x) {
  int y, z;
  split(o, y, z, v[x]);
  y = merge(y, x);
  return merge(y, z);
}
void dfs(int x) {
  if (!x) return;
  pd(st[++tp] = x);
  dfs(ch[x][0]);
  dfs(ch[x][1]);
  ch[x][0] = ch[x][1] = 0;
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); ++i) scanf("%d%d", &a[i].c, &a[i].q);
  sort(a + 1, a + n + 1);
  scanf("%d", &m);
  for (int i = (1); i <= (m); ++i) {
    scanf("%d", &v[i]);
    r[i] = rand();
    rt = insert(rt, i);
  }
  for (int i = (1); i <= (n); ++i) {
    int x, y, z;
    split(rt, x, y, a[i].c);
    ++as[y];
    v[y] -= a[i].c;
    ad[y]++;
    de[y] += a[i].c;
    split(y, y, z, a[i].c);
    tp = 0;
    dfs(y);
    rt = merge(x, z);
    for (int i = (1); i <= (tp); ++i) rt = insert(rt, st[i]);
  }
  tp = 0;
  dfs(rt);
  for (int i = (1); i <= (m); ++i) printf("%d ", as[i]);
  return 0;
}
