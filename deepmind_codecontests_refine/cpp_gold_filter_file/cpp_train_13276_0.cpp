#include <bits/stdc++.h>
using namespace std;
inline void rd(int &res) {
  res = 0;
  char c;
  while (c = getchar(), c < '0')
    ;
  do {
    res = (res << 1) + (res << 3) + (c ^ 48);
  } while (c = getchar(), c >= '0');
}
inline void print(int k) {
  if (k == 0) return;
  print(k / 10);
  putchar((k % 10) ^ 48);
}
inline void sc(int k) {
  print(k);
  if (k == 0) {
    putchar('0');
    putchar('\n');
  }
}
inline void MIN(int &a, int b) {
  if (a == -1 || a > b) a = b;
}
inline void MAX(int &a, int b) {
  if (a < b) a = b;
}
const int M = 1e5 + 5;
int n, m, scc, ecnt;
int A[M], B[M], p[M], e[M], id[M], head[M];
struct node {
  int t, nxt;
} edge[M << 1];
inline void addedge(int a, int b) {
  edge[++ecnt] = (node){b, head[a]};
  head[a] = ecnt;
}
inline void input() {
  int i, j, k;
  rd(n);
  rd(m);
  for (i = 1; i <= m; i++) {
    rd(A[i]), rd(B[i]);
    addedge(A[i], B[i]);
    addedge(B[i], A[i]);
  }
}
inline void dfs(int x, int c) {
  p[c]++;
  id[x] = c;
  for (int i = head[x]; i; i = edge[i].nxt) {
    int t = edge[i].t;
    if (!id[t]) dfs(t, c);
  }
}
inline void solve() {
  int i, j, k, ans = 0;
  for (i = 1; i <= n; i++)
    if (!id[i]) dfs(i, ++scc);
  for (i = 1; i <= m; i++) e[id[A[i]]]++;
  for (i = 1; i <= scc; i++)
    if (e[i] == p[i] - 1) ans++;
  sc(ans);
}
int main() {
  input();
  solve();
  return 0;
}
