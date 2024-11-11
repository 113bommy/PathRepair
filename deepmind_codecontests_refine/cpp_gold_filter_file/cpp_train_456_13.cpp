#include <bits/stdc++.h>
struct edge {
  int y;
  int l;
  int r;
  int next;
} mem[10000];
int head[1100];
int pm;
int n, m;
void buildE(int x, int y, int l, int r) {
  pm++;
  mem[pm].y = y;
  mem[pm].l = l;
  mem[pm].r = r;
  mem[pm].next = head[x];
  head[x] = pm;
}
void inp() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int t1, t2, t3, t4;
    scanf("%d%d%d%d", &t1, &t2, &t3, &t4);
    buildE(t1, t2, t3, t4);
    buildE(t2, t1, t3, t4);
  }
}
int g[1100];
int p, q;
bool z[1100];
int check(int x, int y) {
  memset(z, 0, sizeof(z));
  p = 0, q = 0;
  g[p++] = 1;
  z[1] = 1;
  while (p != q) {
    int t1 = g[q++];
    for (int i = head[t1]; i; i = mem[i].next) {
      if (mem[i].l <= x && mem[i].r >= y) {
        if (z[mem[i].y] == 0) g[p++] = mem[i].y, z[mem[i].y] = 1;
      }
    }
  }
  return z[n];
}
void find() {
  int L = 1, R = 1000001;
  int i;
  for (i = 2; i <= 2 * m; i += 2) {
    if (check(mem[i].l, mem[i].l)) break;
  }
  if (i > m * 2) {
    printf("Nice work, Dima!\n");
    return;
  }
  while (L + 1 < R) {
    int Mi = (L + R) / 2;
    for (i = 2; i <= 2 * m; i += 2) {
      if (check(mem[i].l, mem[i].l + Mi - 1)) break;
    }
    if (i <= 2 * m)
      L = Mi;
    else
      R = Mi;
  }
  printf("%d\n", L);
}
int main() {
  inp();
  find();
  return 0;
}
