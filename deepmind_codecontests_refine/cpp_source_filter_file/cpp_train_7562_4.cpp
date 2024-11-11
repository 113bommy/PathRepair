#include <bits/stdc++.h>
using namespace std;
int n, m, k, x, y, a[500005];
int tot, to[500005], ne[500005], la[500005];
int dfn[500005], low[500005], num;
int z[500005], top, p[500005];
int cnt, color[500005], size[500005];
int q[500005], ans;
void read(int &x) {
  x = 0;
  int k = 1;
  char c = getchar();
  while ((c != '-') && (c < '0' || c > '9')) c = getchar();
  if (c == '-') k = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  x = x * k;
}
void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
void link(int u, int v) { to[++tot] = v, ne[tot] = la[u], la[u] = tot; }
void init() { freopen("e.in", "r", stdin); }
void tarjan(int x) {
  dfn[x] = low[x] = ++num;
  z[++top] = x, p[x] = 1;
  for (int i = la[x]; i; i = ne[i]) {
    int y = to[i];
    if (!dfn[y]) {
      tarjan(y);
      low[x] = min(low[x], low[y]);
    } else if (p[y]) {
      low[x] = min(low[x], dfn[y]);
    }
  }
  if (dfn[x] == low[x]) {
    p[x] = 0;
    color[x] = ++cnt;
    int t = 1;
    while (x != z[top]) {
      t++;
      p[z[top]] = 0;
      color[z[top]] = cnt;
      z[top] = 0;
      top--;
    }
    z[top--] = 0;
    size[cnt] = t;
  }
}
int main() {
  read(n), read(m), read(k);
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int i = 1; i <= m; i++) {
    read(x), read(y);
    if ((a[x] + 1) % k == a[y]) link(x, y);
    if ((a[y] + 1) % k == a[x]) link(y, x);
  }
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) tarjan(i);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = la[i]; j; j = ne[j]) {
      int y = to[j];
      if (color[i] != color[y]) {
        q[color[i]] = 1;
      }
    }
  }
  ans = -1;
  for (int i = 1; i <= n; i++) {
    if (q[color[i]]) continue;
    if (ans = -1)
      ans = i;
    else if (size[color[i]] < size[color[ans]])
      ans = i;
  }
  write(size[color[ans]]), printf("\n");
  for (int i = 1; i <= n; i++)
    if (color[i] == color[ans]) write(i), printf(" ");
  return 0;
}
