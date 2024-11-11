#include <bits/stdc++.h>
static const int MAXN = 100005;
static const int MAXM = MAXN * 2;
inline int &tuple4_get(std::pair<std::pair<int, int>, std::pair<int, int> > &t,
                       int idx) {
  switch (idx) {
    case 0:
      return t.first.first;
    case 1:
      return t.first.second;
    case 2:
      return t.second.first;
    default:
      return t.second.second;
  }
}
inline void tuple4_sort(
    std::pair<std::pair<int, int>, std::pair<int, int> > &t) {
  static int a[4];
  for (int i = 0; i < 4; ++i) a[i] = tuple4_get(t, i);
  std::sort(a, a + 4);
  t = std::pair<std::pair<int, int>, std::pair<int, int> >(
      std::make_pair(a[0], a[1]), std::make_pair(a[2], a[3]));
}
int n;
int deg[MAXN] = {0}, head[MAXN], dest[MAXM], next[MAXM];
inline void add_edge(int u, int v) {
  static int w = 0;
  ++deg[u];
  dest[w] = v;
  next[w] = head[u];
  head[u] = w++;
}
int tag_ct = 0;
std::map<std::pair<std::pair<int, int>, std::pair<int, int> >, int> tag_id;
int tag[MAXN];
void dfs_mark(int u, int p = -1) {
  std::pair<std::pair<int, int>, std::pair<int, int> > t =
      std::pair<std::pair<int, int>, std::pair<int, int> >(
          std::make_pair(-1, -1), std::make_pair(-1, -1));
  for (int w = head[u], i = 0; w != -1; w = next[w], ++i)
    if (dest[w] != p) {
      dfs_mark(dest[w], u);
      tuple4_get(t, i) = tag[dest[w]];
    }
  tuple4_sort(t);
  int &ptr = tag_id[t];
  if (ptr == 0)
    tag[u] = (ptr = ++tag_ct);
  else
    tag[u] = ptr;
}
void dfs_push(int u, int p = -1) {
  std::pair<std::pair<int, int>, std::pair<int, int> > t =
      std::pair<std::pair<int, int>, std::pair<int, int> >(
          std::make_pair(-1, -1), std::make_pair(-1, -1));
  for (int w = head[u], i = 0; w != -1; w = next[w], ++i) {
    tuple4_get(t, i) = tag[dest[w]];
  }
  for (int w = head[u], i = 0, j, tt; w != -1; w = next[w], ++i)
    if (dest[w] != p) {
      for (j = 0; j < 4; ++j)
        if (tuple4_get(t, j) == tag[dest[w]]) {
          tt = tag[dest[w]];
          tuple4_get(t, j) = -1;
          break;
        }
      tuple4_sort(t);
      int &ptr = tag_id[t];
      if (ptr == 0)
        tag[u] = (ptr = ++tag_ct);
      else
        tag[u] = ptr;
      dfs_push(dest[w], u);
      tuple4_get(t, j) = tt;
    }
  tuple4_sort(t);
  int &ptr = tag_id[t];
  if (ptr == 0)
    tag[u] = (ptr = ++tag_ct);
  else
    tag[u] = ptr;
}
int main() {
  scanf("%d", &n);
  int u, v;
  for (int i = 0; i < n; ++i) head[i] = -1;
  for (int i = 0; i < n - 1; ++i) {
    scanf("%d%d", &u, &v);
    --u, --v;
    add_edge(u, v);
    add_edge(v, u);
  }
  dfs_mark(0);
  dfs_push(0);
  for (int i = 0; i < n; ++i)
    if (deg[i] >= 4) tag[i] = -1;
  std::sort(tag, tag + n);
  int cnt = std::unique(tag, tag + n) - &tag[0];
  if (tag[0] == -1) --cnt;
  printf("%d\n", cnt);
  return 0;
}
