#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return f * x;
}
struct edge {
  long long nxt, to, v1, v2;
} ed[605000];
struct node {
  node friend operator+(node a, node b) {
    node ans;
    ans.o[0][0] = min(a.o[0][0] + b.o[0][0], a.o[0][1] + b.o[1][0]);
    ans.o[1][1] = min(a.o[1][0] + b.o[0][1], a.o[1][1] + b.o[1][1]);
    ans.o[0][1] = min(a.o[0][0] + b.o[0][1], a.o[0][1] + b.o[1][1]);
    ans.o[1][0] = min(a.o[1][0] + b.o[0][0], a.o[1][1] + b.o[1][0]);
    return ans;
  }
  long long o[2][2];
} g[305000][20];
long long n, m, rev[305000], a, b, c, d, used[305000];
long long head[305000], cnt, _head[305000], _cnt, __head[305000], __cnt;
long long f[305000][20], dep[305000];
void add(long long a, long long b, long long c, long long d) {
  ed[++cnt].to = b;
  ed[cnt].v1 = c;
  ed[cnt].v2 = d;
  ed[cnt].nxt = head[a];
  head[a] = cnt;
}
void dfs1(int pos) {
  used[pos]++;
  for (int i = head[pos]; i; i = ed[i].nxt) {
    if (!used[ed[i].to]) {
      dfs1(ed[i].to);
      rev[pos] = min(rev[pos], rev[ed[i].to] + ed[i].v1 + ed[i].v2);
    }
  }
}
void dfs2(int pos) {
  used[pos]++;
  for (int i = head[pos]; i; i = ed[i].nxt) {
    if (!used[ed[i].to]) {
      rev[ed[i].to] = min(rev[ed[i].to], rev[pos] + ed[i].v1 + ed[i].v2);
      dfs2(ed[i].to);
    }
  }
}
void dfs3(int pos) {
  used[pos]++;
  for (int i = head[pos]; i; i = ed[i].nxt) {
    if (!used[ed[i].to]) {
      f[ed[i].to][0] = pos;
      dep[ed[i].to] = dep[pos] + 1;
      g[ed[i].to][0].o[0][0] =
          min(ed[i].v1, rev[pos] + ed[i].v2 + rev[ed[i].to]);
      g[ed[i].to][0].o[0][1] =
          min(ed[i].v1 + rev[pos], ed[i].v2 + rev[ed[i].to]);
      g[ed[i].to][0].o[1][0] =
          min(ed[i].v2 + rev[pos], ed[i].v1 + rev[ed[i].to]);
      g[ed[i].to][0].o[1][1] =
          min(ed[i].v2, rev[pos] + ed[i].v1 + rev[ed[i].to]);
      dfs3(ed[i].to);
    }
  }
}
void query(int a, int b) {
  int x = (a + 1) / 2, y = (b + 1) / 2;
  if (x == y) {
    if (a == b)
      printf("0\n");
    else
      printf("%lld\n", rev[x]);
    return;
  }
  node o1 = {0, 1000000000000000ll, 1000000000000000ll, 0},
       o2 = {0, 1000000000000000ll, 1000000000000000ll, 0};
  if (dep[x] < dep[y]) swap(a, b), swap(x, y);
  for (int i = 19; i >= 0; i--) {
    if (dep[f[x][i]] >= dep[y]) {
      o1 = o1 + g[x][i];
      x = f[x][i];
    }
  }
  if (x == y) {
    printf("%lld\n", o1.o[(a & 1) ^ 1][(b & 1) ^ 1]);
    return;
  }
  for (int i = 19; i >= 0; i--) {
    if (f[x][i] != f[y][i]) {
      o1 = o1 + g[x][i];
      o2 = o2 + g[y][i];
      x = f[x][i];
      y = f[y][i];
    }
  }
  o1 = o1 + g[x][0];
  o2 = o2 + g[y][0];
  printf("%lld\n", min(o1.o[(a & 1) ^ 1][0] + o2.o[(b & 1) ^ 1][0],
                       o1.o[(a & 1) ^ 1][1] + o2.o[(b & 1) ^ 1][1]));
}
int main() {
  n = read();
  dep[1] = 1;
  for (int i = 1; i <= n; i++) rev[i] = read();
  for (int i = 1; i < n; i++) {
    a = read();
    b = read();
    c = read();
    d = read();
    add(a, b, c, d);
    add(b, a, c, d);
  }
  dfs1(1);
  memset(used, 0, sizeof(used));
  dfs2(1);
  memset(used, 0, sizeof(used));
  dfs3(1);
  memset(used, 0, sizeof(used));
  g[1][0].o[0][1] = g[1][0].o[1][0] = rev[1];
  for (int i = 1; i <= 19; i++) {
    for (int j = 1; j <= n; j++) {
      f[j][i] = f[f[j][i - 1]][i - 1];
      g[j][i] = g[j][i - 1] + g[f[j][i - 1]][i - 1];
    }
  }
  m = read();
  for (int i = 1; i <= m; i++) {
    a = read();
    b = read();
    query(a, b);
  }
  return 0;
}
