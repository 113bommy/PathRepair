#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = x * 10 + (c & 15), c = getchar();
}
int n, e[2505][2505], fa[2505], cnt;
struct Edge {
  int a, b, c;
  inline Edge(int a = 0, int b = 0, int c = 0) : a(a), b(b), c(c) {}
} k[2505 * 2505];
inline bool cmp(const Edge &a, const Edge &b) { return a.c < b.c; }
inline int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
signed main() {
  read(n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) read(e[i][j]);
  for (int i = 1; i <= n; i++) {
    if (e[i][i]) {
      printf("NOT MAGIC");
      return 0;
    }
    for (int j = 1; j < i; j++)
      if (e[i][j] != e[j][i]) {
        printf("NOT MAGIC");
        return 0;
      } else
        k[++cnt] = Edge(i, j, e[i][j]);
  }
  for (int i = 1; i <= n; i++) fa[i] = i;
  sort(k + 1, k + cnt + 1, cmp);
  for (int i = 1, las = 0; i <= cnt; i++) {
    if (find(k[i].a) == find(k[i].c)) {
      printf("NOT MAGIC");
      return 0;
    }
    if (k[i].c < k[i + 1].c) {
      for (int j = las + 1; j <= i; j++) fa[find(k[j].a)] = find(k[j].b);
      las = i;
    }
  }
  printf("MAGIC");
  return 0;
}
