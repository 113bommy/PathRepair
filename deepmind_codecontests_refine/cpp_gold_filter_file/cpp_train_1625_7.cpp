#include <bits/stdc++.h>
using namespace std;
struct edge {
  int u, v, next, f;
};
struct edge e[200010];
struct unit {
  int s1, s2, c;
};
struct unit f[100010][2], ans;
int n, n1, k, k1, num;
int a[100010], b[100010], p[100010], used[100010], fa[100010], c[100010],
    w[100010];
struct unit operator+(struct unit aa, struct unit bb) {
  struct unit ret;
  ret.c = 0;
  ret.s1 = aa.s1 + bb.s1;
  ret.s2 = aa.s2 + bb.s2;
  return ret;
}
struct unit operator-(struct unit aa, struct unit bb) {
  struct unit ret;
  ret.c = 0;
  ret.s1 = aa.s1 - bb.s1;
  ret.s2 = aa.s2 - bb.s2;
  return ret;
}
int cmp(struct unit aa, struct unit bb) {
  if (aa.s1 > bb.s1 || (aa.s1 == bb.s1 && aa.s2 >= bb.s2))
    return 1;
  else
    return 0;
}
void add(int u, int v) {
  e[num].u = u;
  e[num].v = v;
  e[num].next = p[u];
  p[u] = num;
  num++;
  e[num].u = v;
  e[num].v = u;
  e[num].next = p[v];
  p[v] = num;
  num++;
}
int find(int i) {
  if (fa[i] == i) return i;
  return fa[i] = find(fa[i]);
}
void dfs(int i, int fa) {
  int j;
  j = p[i];
  while (j != -1) {
    if (e[j].v != fa) {
      if (e[j].v == e[k].v) {
        k1 = j;
        return;
      } else
        dfs(e[j].v, i);
    }
    j = e[j].next;
  }
}
void work(int i, int fa) {
  int j;
  struct unit t;
  used[i] = 1;
  j = p[i];
  f[i][0].s1 = 0;
  f[i][0].s2 = 0;
  f[i][1].s1 = 0;
  f[i][1].s2 = 0;
  while (j != -1) {
    if (e[j].f == 0 && e[j].v != fa) {
      work(e[j].v, i);
      if (cmp(f[e[j].v][0], f[e[j].v][1]))
        f[i][0] = f[i][0] + f[e[j].v][0];
      else
        f[i][0] = f[i][0] + f[e[j].v][1];
    }
    j = e[j].next;
  }
  j = p[i];
  while (j != -1) {
    if (e[j].f == 0 && e[j].v != fa) {
      if (cmp(f[e[j].v][0], f[e[j].v][1]))
        t = f[i][0] - f[e[j].v][0];
      else
        t = f[i][0] - f[e[j].v][1];
      t = t + f[e[j].v][0];
      t.s1++;
      if (a[e[j].v] != a[i]) t.s2++;
      if (cmp(t, f[i][1])) {
        f[i][1] = t;
        f[i][1].c = e[j].v;
      }
    }
    j = e[j].next;
  }
}
void calc(int i, int fa, int flag) {
  int j, f1 = 0;
  if (flag == 0 && cmp(f[i][1], f[i][0])) f1 = 1;
  used[i] = 2;
  j = p[i];
  while (j != -1) {
    if (e[j].f == 0 && e[j].v != fa) {
      if (f1 == 1 && e[j].v == f[i][1].c) {
        printf("%d %d\n", i, e[j].v);
        calc(e[j].v, i, 1);
      } else
        calc(e[j].v, i, 0);
    }
    j = e[j].next;
  }
}
int main() {
  int i, j, fx, fy;
  struct unit t;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) fa[i] = i;
  memset(p, -1, sizeof(p));
  k = -1;
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &b[i], &a[i]);
    if (b[i] > i || b[b[i]] != i) {
      add(i, b[i]);
      fx = find(b[i]);
      fy = find(i);
      if (fx != fy)
        fa[fx] = fy;
      else {
        n1++;
        c[n1] = num - 1;
      }
    }
  }
  for (i = 1; i <= n1; i++) w[find(e[c[i]].u)] = c[i];
  for (i = 1; i <= n; i++)
    if (used[i] == 0) {
      if (w[find(i)] == 0) {
        work(i, 0);
        if (cmp(f[i][0], f[i][1]))
          ans = ans + f[i][0];
        else
          ans = ans + f[i][1];
      } else {
        k = w[find(i)];
        dfs(e[k].u, e[k].v);
        e[k].f = 1;
        e[k ^ 1].f = 1;
        work(i, 0);
        e[k].f = 0;
        e[k ^ 1].f = 0;
        if (cmp(f[i][0], f[i][1]))
          t = f[i][0];
        else
          t = f[i][1];
        e[k1].f = 1;
        e[k1 ^ 1].f = 1;
        work(i, 0);
        e[k1].f = 0;
        e[k1 ^ 1].f = 0;
        if (cmp(f[i][0], t)) t = f[i][0];
        if (cmp(f[i][1], t)) t = f[i][1];
        if (cmp(f[i][0], t) || cmp(f[i][1], t)) {
          e[k1].f = 1;
          e[k1 ^ 1].f = 1;
        } else {
          e[k].f = 1;
          e[k ^ 1].f = 1;
          work(i, 0);
        }
        ans = ans + t;
      }
    }
  printf("%d %d\n", ans.s1, ans.s2);
  for (i = 1; i <= n; i++)
    if (used[i] == 1) calc(i, 0, 0);
  return 0;
}
