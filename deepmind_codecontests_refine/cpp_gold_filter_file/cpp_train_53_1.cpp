#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void gn(T &first) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-')
    ;
  for ((c == '-' ? sg = 1, c = getchar() : 0), first = 0; c >= '0' && c <= '9';
       c = getchar())
    first = (first << 1) + (first << 3) + c - '0';
  if (sg) first = -first;
}
template <class T1, class T2>
inline void gn(T1 &x1, T2 &x2) {
  gn(x1), gn(x2);
}
pair<int, int> edge[500010];
int w[500010];
int n, m, Q;
int id[500010];
int col[1010];
int root[1010];
int rev[500010];
inline int find_root(int u) {
  if (root[u] == u) return u;
  int first = find_root(root[u]);
  col[u] ^= col[root[u]];
  return root[u] = first;
}
int main() {
  gn(n, m);
  gn(Q);
  for (int i = 1; i <= m; i++) {
    gn(edge[i].first, edge[i].second);
    gn(w[i]);
  }
  for (int i = 1; i <= m; i++) id[i] = i;
  sort(id + 1, id + m + 1, [&](int u, int v) { return w[u] > w[v]; });
  while (Q--) {
    int L, R;
    gn(L, R);
    for (int i = 1; i <= n; i++) {
      col[i] = 0;
      root[i] = i;
    }
    int ans = -1;
    for (int i = 1; i <= m; i++) {
      if (id[i] > R || id[i] < L) continue;
      int u = edge[id[i]].first, v = edge[id[i]].second;
      if (find_root(u) == find_root(v)) {
        if (col[u] == col[v]) {
          ans = w[id[i]];
          break;
        }
        continue;
      }
      col[root[u]] = col[u] ^ col[v] ^ 1;
      root[root[u]] = root[v];
    }
    printf("%d\n", ans);
  }
}
