#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000 + 1;
struct Edge {
  int u, v, w;
} e[maxn];
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, sum;
int a[maxn], pre[maxn], sz[maxn];
bool cmp(Edge a, Edge b) { return a.w < b.w; }
int find(int x) { return x == pre[x] ? x : pre[x] = find(pre[x]); }
int main() {
  n = read();
  for (int i = 1; i < n; i++) {
    e[i].u = read();
    e[i].v = read();
    e[i].w = read();
  }
  sort(e + 1, e + n, cmp);
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    pre[i] = i;
    sz[i] = 1;
    sum += a[i];
  }
  for (int i = 1; i < n; i++) {
    int u = find(e[i].u), v = find(e[i].v);
    pre[u] = v;
    sz[v] += sz[u];
    a[v] += a[u];
    if (sz[v] > sum - a[i]) {
      printf("%d\n", e[i].w);
      return 0;
    }
  }
  puts("0");
  return 0;
}
