#include <bits/stdc++.h>
using namespace std;
const int kMaxN = 500001;
struct V {
  int p[2], fe, l, r;
} v[kMaxN];
struct E {
  int y, n;
} e[kMaxN];
struct L {
  int p, n, v;
} l[kMaxN * 2];
int n, x, y, ln;
void AddEdge(int i, int x, int y) {
  e[i].y = y;
  e[i].n = v[x].fe;
  v[x].fe = i;
}
int AddNode(int p, int x, int t) {
  ln++;
  l[ln].p = p;
  l[ln].n = l[p].n;
  l[ln].v = x;
  l[l[p].n].p = ln;
  l[p].n = ln;
  v[x].p[t] = ln;
  return ln;
}
void Work(int f, int x) {
  int i = v[x].fe, p = v[x].p[1];
  while (i) {
    if (e[i].y != f) {
      p = AddNode(l[p].p, e[i].y, 0);
    }
    i = e[i].n;
  }
  i = v[x].fe, p = v[x].p[1];
  while (i) {
    if (e[i].y != f) {
      p = AddNode(p, e[i].y, 1);
    }
    i = e[i].n;
  }
  i = v[x].fe;
  while (i) {
    if (e[i].y != f) {
      Work(x, e[i].y);
    }
    i = e[i].n;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d %d", &x, &y);
    AddEdge(i * 2 - 1, x, y);
    AddEdge(i * 2, y, x);
  }
  ln = 2;
  l[1].p = 0;
  l[1].n = 2;
  l[2].p = 1;
  l[2].n = 0;
  l[1].v = l[2].v = 1;
  v[1].p[0] = 1;
  v[1].p[1] = 2;
  Work(0, 1);
  for (int i = 1, c = 1; i; i = l[i].n, c++) {
    if (!v[l[i].v].l) {
      v[l[i].v].l = c;
    } else {
      v[l[i].v].r = c;
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%d %d\n", v[i].l, v[i].r);
  }
  return 0;
}
