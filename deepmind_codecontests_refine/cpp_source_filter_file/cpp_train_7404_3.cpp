#include <bits/stdc++.h>
using namespace std;
namespace RikukiIX {
const int N = 100069;
struct sumireko {
  int to, ne;
} e[N << 1];
int he[N], ecnt;
void addline(int f, int t) {
  e[++ecnt].to = t;
  e[ecnt].ne = he[f];
  he[f] = ecnt;
}
int f[N], rt[N], dd[N];
int find(int x) {
  if (f[x] == f[f[x]]) return f[x];
  return f[x] = find(f[x]);
}
int up[N], d1[N], d2[N], dx1[N], dx2[N];
void findroot(int x, int fr, int p) {
  for (int i = he[x], t = e[i].to; i; i = e[i].ne, t = e[i].to) {
    if (t != fr) {
      findroot(t, x, p);
      int g = d1[t] + 1;
      if (g > d1[x]) {
        d2[x] = d1[x], dx2[x] = dx1[x], d1[x] = g, dx1[x] = t;
      } else if (g > d2[x]) {
        d2[x] = g, dx2[x] = t;
      }
    }
  }
}
void findroot2(int x, int fr, int p) {
  dd[p] = max(dd[p], d1[x] + d2[x]);
  dd[p] = max(dd[p], d1[x] + up[x]);
  for (int i = he[x], t = e[i].to; i; i = e[i].ne, t = e[i].to) {
    if (t != fr) {
      if (t == dx1[x])
        up[t] = 1 + max(d2[x], up[x]);
      else
        up[t] = 1 + max(d1[x], up[x]);
      findroot2(t, x, p);
    }
  }
  if (max(up[x], d1[x]) < max(up[rt[p]], d1[rt[p]])) rt[p] = x;
}
int list[N], li;
void findroot(int x) {
  list[++li] = x;
  findroot(x, 0, x);
  findroot2(x, 0, x);
}
int cmp(int x, int y) {
  return max(up[rt[x]], d1[rt[x]]) > max(up[rt[y]], d1[rt[y]]);
}
int n, m, xi, yi;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) f[i] = i;
  for (int i = 1; i <= m; i++)
    scanf("%d%d", &xi, &yi), addline(xi, yi), addline(yi, xi),
        f[find(xi)] = find(yi);
  up[0] = d1[0] = d2[0] = 114514;
  for (int i = 1; i <= n; i++)
    if (find(i) == i) findroot(i);
  sort(list + 1, list + 1 + li, cmp);
  int ans = 0;
  for (int i = 1; i <= li; i++) ans = max(ans, dd[list[li]]);
  if (li >= 2)
    ans = max(ans, 1 + max(up[rt[list[1]]], d1[rt[list[1]]]) +
                       max(up[rt[list[2]]], d1[rt[list[2]]]));
  if (li >= 3)
    ans = max(ans, 2 + max(up[rt[list[3]]], d1[rt[list[3]]]) +
                       max(up[rt[list[2]]], d1[rt[list[2]]]));
  printf("%d\n", ans);
  for (int i = 2; i <= li; i++) printf("%d %d\n", rt[list[1]], rt[list[i]]);
  return 0;
}
}  // namespace RikukiIX
int main() { return RikukiIX::main(); }
