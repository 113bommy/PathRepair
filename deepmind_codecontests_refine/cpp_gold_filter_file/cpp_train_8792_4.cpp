#include <bits/stdc++.h>
using namespace std;
struct rec {
  int x, y, id;
} a[100010], b[100010];
int n, m, s[100010], l[100010], r[100010], key[100010], id[100010], c[100010],
    num = 0, root = 0, ans[100010];
bool cmpx(rec a, rec b) { return a.x < b.x; }
void r_rotate(int &u) {
  int v = l[u];
  l[u] = r[v];
  r[v] = u;
  s[v] = s[u];
  s[u] = s[l[u]] + s[r[u]] + 1;
  u = v;
}
void l_rotate(int &u) {
  int v = r[u];
  r[u] = l[v];
  l[v] = u;
  s[v] = s[u];
  s[u] = s[l[u]] + s[r[u]] + 1;
  u = v;
}
void maintain(int &u, bool flag) {
  if (!flag) {
    if (s[l[l[u]]] > s[r[u]])
      r_rotate(u);
    else if (s[r[l[u]]] > s[r[u]])
      l_rotate(l[u]), r_rotate(u);
    else
      return;
  } else {
    if (s[r[r[u]]] > s[l[u]])
      l_rotate(u);
    else if (s[l[r[u]]] > s[l[u]])
      r_rotate(r[u]), l_rotate(u);
    else
      return;
  }
  maintain(l[u], 0);
  maintain(r[u], 1);
  maintain(u, 0);
  maintain(u, 1);
}
void ins(int &u, int y, int D) {
  if (!u) {
    u = ++num;
    s[u] = 1;
    l[u] = r[u] = 0;
    key[u] = y;
    id[u] = D;
    return;
  }
  s[u]++;
  if (y < key[u] || y == key[u] && D < id[u])
    ins(l[u], y, D);
  else
    ins(r[u], y, D);
  maintain(u, !(y < key[u] || y == key[u] && D < id[u]));
}
int find(int u, int y) {
  if (!u) return 0;
  if (key[u] < y) return find(r[u], y);
  int t = find(l[u], y);
  return t ? t : u;
}
int R(int u) { return (r[u] ? R(r[u]) : u); }
void del(int &u, int y, int D) {
  s[u]--;
  if (y == key[u] && D == id[u]) {
    if (!l[u] || !r[u])
      u = l[u] + r[u];
    else {
      int t = R(l[u]);
      key[u] = key[t];
      id[u] = id[t];
      del(l[u], key[t], id[t]);
    }
    return;
  }
  if (y < key[u] || y == key[u] && D < id[u])
    del(l[u], y, D);
  else
    del(r[u], y, D);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i], &a[i].y), a[i].id = i;
  scanf("%d", &m);
  for (int i = 1; i <= m; i++)
    scanf("%d%d%d", &b[i].x, &b[i].y, &c[i]), b[i].id = i;
  sort(a + 1, a + n + 1, cmpx);
  sort(b + 1, b + m + 1, cmpx);
  int z = 0;
  for (int i = 1; i <= n; i++) {
    while (z < m && b[z + 1].x <= a[i].x) {
      z++;
      ins(root, b[z].y, b[z].id);
    }
    int t = find(root, a[i].y);
    if (!t) {
      printf("NO\n");
      return 0;
    }
    c[id[t]]--;
    ans[a[i].id] = id[t];
    if (!c[id[t]]) del(root, key[t], id[t]);
  }
  printf("YES\n");
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
