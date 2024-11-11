#include <bits/stdc++.h>
using namespace std;
const int maxn = 1011;
int fa[maxn * 2];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
int n, m, q;
struct edge {
  int u, v, w, id;
  bool operator<(const edge &oth) const { return w > oth.w; }
} E[maxn * maxn / 2];
int getn() {
  int r = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) r = r * 10 + c - '0', c = getchar();
  return r;
}
int main() {
  n = getn();
  m = getn();
  q = getn();
  for (int i = 1; i <= m; i++) {
    E[i].u = getn() - 1;
    E[i].v = getn() - 1;
    E[i].w = getn();
    E[i].id = i;
  }
  sort(E + 1, E + 1 + m);
  while (q--) {
    int l = getn(), r = getn();
    for (int i = 0; i <= n * 2; i++) fa[i] = i;
    int ok = 0;
    for (int i = 1; i <= m; i++)
      if (l <= E[i].id && E[i].id <= r) {
        if (find(E[i].u * 2) == find(E[i].v * 2)) {
          ok = 1;
          printf("%d\n", E[i].w);
          break;
        } else {
          fa[find(E[i].u * 2)] = find(E[i].v * 2 + 1);
          fa[find(E[i].u * 2 + 1)] = find(E[i].v * 2);
        }
      }
    if (!ok) puts("-1");
  }
  return 0;
}
