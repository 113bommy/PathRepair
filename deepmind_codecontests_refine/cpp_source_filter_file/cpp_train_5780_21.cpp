#include <bits/stdc++.h>
using namespace std;
int link[100010], vis[100010];
struct node {
  int w, id;
} a[100010], b[100010];
struct tree {
  int u, v;
} T[100010];
bool cmp(node n1, node n2) { return n1.w < n2.w; }
int main() {
  int n, m, x, y;
  scanf("%d%d", &n, &m);
  int la = 0, lb = 0;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    if (y == 1) {
      a[la].w = x, a[la++].id = i;
    } else {
      b[lb].w = x, b[lb++].id = i;
    }
  }
  sort(a, a + la, cmp);
  sort(b, b + lb, cmp);
  int p = 1, ans = 2, s;
  for (int i = 0; i < la; i++) {
    link[ans] = a[i].w;
    T[a[i].id].u = p;
    T[a[i].id].v = ans++;
  }
  p = 2, ans = 3, s = 0;
  for (int i = 0; i < lb; i++) {
    if (link[p] > b[i].w) {
      printf("-1\n");
      return 0;
    }
    T[b[i].id].u = p;
    T[b[i].id].v = ans++;
    if (ans == n) p++, ans = p + 1;
  }
  for (int i = 1; i <= m; i++) {
    printf("%d %d\n", T[i].u, T[i].v);
  }
  return 0;
}
