#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5, M = 1e5 + 5;
int n, m;
int st, mt, cnt1, cnt2;
int fa[M], u, v;
char c;
bool b[M], ans[M];
struct node {
  int u, v, num;
} es[M], em[M];
int get_fa(int x) {
  if (fa[x] == x) return x;
  return fa[x] = get_fa(fa[x]);
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %c", &u, &v, &c);
    if (c == 'S')
      es[++st] = (node){u, v, i};
    else
      em[++mt] = (node){u, v, i};
  }
  if (!(n & 1)) {
    printf("-1\n");
    return 0;
  }
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 1; i <= st; i++) {
    u = get_fa(es[i].u), v = get_fa(es[i].v);
    if (u != v) fa[v] = u, cnt1++;
  }
  if (cnt1 < (n - 1) / 2) {
    printf("-1\n");
    return 0;
  }
  for (int i = 1; i <= mt; i++) {
    u = get_fa(em[i].u), v = get_fa(em[i].v);
    if (u != v) fa[v] = u, b[i] = 1, cnt2++;
  }
  if (cnt1 + cnt2 < n - 1) {
    printf("-1\n");
    return 0;
  }
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 1; i <= mt; i++)
    if (b[i]) {
      u = get_fa(em[i].u), v = get_fa(em[i].v);
      fa[v] = u, ans[em[i].num] = 1;
    }
  for (int i = 1; i <= mt && cnt2 < (n - 1) / 2; i++)
    if (!b[i]) {
      u = get_fa(em[i].u), v = get_fa(em[i].v);
      if (u != v) fa[v] = u, cnt2++, ans[em[i].num] = 1;
    }
  if (cnt2 < (n - 1) / 2) {
    printf("-1\n");
    return 0;
  }
  for (int i = 1; i <= st; i++) {
    u = get_fa(es[i].u), v = get_fa(es[i].v);
    if (u != v) fa[v] = u, ans[es[i].num] = 1;
  }
  printf("%d\n", n - 1);
  for (int i = 1; i <= m; i++)
    if (ans[i]) printf("%d ", i);
  return 0;
}
