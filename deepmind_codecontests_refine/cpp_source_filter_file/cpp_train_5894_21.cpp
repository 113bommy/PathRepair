#include <bits/stdc++.h>
using namespace std;
const int INF = 2e6 + 10;
const int MAX = 3e5 + 1;
const int MAXN = 20;
int a[MAXN], d[INF], vis[MAX];
struct Trie {
  int l, r, v;
} p[INF];
int clc;
void init() {
  for (int i = 0; i < INF; i++) {
    p[i].l = p[i].r = -1;
    p[i].v = 0;
  }
  memset(vis, 0, sizeof(vis));
  clc = 1;
}
void insert(int x) {
  memset(a, 0, sizeof(a));
  int k = MAXN;
  int tmp = x;
  while (tmp > 0) {
    a[--k] = tmp % 2;
    tmp = tmp / 2;
  }
  int u = 0;
  for (int i = 0; i < MAXN; i++) {
    if (a[i] == 0) {
      if (p[u].l == -1) {
        p[u].l = clc;
        clc++;
      }
      u = p[u].l;
    } else {
      if (p[u].r == -1) {
        p[u].r = clc;
        clc++;
      }
      u = p[u].r;
    }
  }
  p[u].v = x;
}
int find(int x) {
  int tmp = 1 << MAXN;
  memset(a, 0, sizeof(a));
  int k = MAXN;
  while (x > 0) {
    a[--k] = x % 2;
    x = x / 2;
  }
  int u = 0, res = 0;
  for (int i = 0; i < MAXN; i++) {
    if (a[i] == 0) {
      if (p[u].l != -1) {
        u = p[u].l;
      } else {
        u = p[u].r;
      }
    } else {
      if (p[u].r != -1) {
        u = p[u].r;
      } else {
        u = p[u].l;
      }
    }
  }
  return p[u].v;
}
int main(int argc, char const *argv[]) {
  int n, m;
  while (scanf("%d%d", &n, &m) != EOF) {
    int tmp;
    init();
    for (int i = 0; i < n; i++) {
      scanf("%d", &tmp);
      vis[tmp] = 1;
    }
    for (int i = 0; i < MAX; i++)
      if (!vis[i]) {
        insert(i);
      }
    int x, u = 0;
    for (int i = 1; i <= m; i++) {
      scanf("%d", &x);
      u ^= x;
      printf("%d\n", u ^ find(u));
    }
  }
  return 0;
}
