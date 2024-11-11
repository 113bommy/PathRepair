#include <bits/stdc++.h>
using namespace std;
const int inf = 1e6 + 2;
const int mxn = 3e5 + 2;
int n, m, c[inf], ans[mxn];
struct node {
  int l, r, id;
} e[inf];
int lowbit(int x) { return x & -x; }
void add(int i) {
  while (i < inf) {
    c[i]++;
    i += lowbit(i);
  }
}
int sum(int i) {
  int s = 0;
  while (i) {
    s += c[i];
    i -= lowbit(i);
  }
  return s;
}
int cmp(node a, node b) {
  if (a.l == b.l) {
    if (a.r == b.r) return a.id < b.id;
    return a.r < b.r;
  }
  return a.l > b.l;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &e[i].l, &e[i].r);
    e[i].id = 0;
  }
  int tot = n;
  for (int k = 1; k <= m; k++) {
    int a, b, cnt;
    scanf("%d%d", &cnt, &a);
    if (a > 1) {
      e[++tot].l = 1;
      e[tot].r = a - 1;
      e[tot].id = k;
    }
    for (int i = 1; i <= cnt - 1; i++) {
      scanf("%d", &b);
      if (a + 1 <= b - 1) {
        e[++tot].l = a + 1;
        e[tot].r = b - 1;
        e[tot].id = k;
      }
      a = b;
    }
    e[++tot].l = a + 1;
    e[tot].r = inf;
    e[tot].id = k;
  }
  sort(e + 1, e + tot + 1, cmp);
  for (int i = 1; i <= tot; i++) {
    if (e[i].id)
      ans[e[i].id] += sum(e[i].r);
    else
      add(e[i].r);
  }
  for (int i = 1; i <= n; i++) printf("%d\n", n - ans[i]);
}
