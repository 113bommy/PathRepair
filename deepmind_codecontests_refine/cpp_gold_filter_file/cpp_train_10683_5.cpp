#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
int n, m, len, a[200005], t, las[200005];
int head[200005], nxt[400005], v[400005], cnt;
inline void add(int x, int y) {
  v[++cnt] = y;
  nxt[cnt] = head[x];
  head[x] = cnt;
}
int dfn[200005], low[200005], c[200005], tot, num;
stack<int> zhan;
inline void tarjan(int x) {
  dfn[x] = low[x] = ++num;
  zhan.push(x);
  for (int i = head[x]; i; i = nxt[i])
    if (!dfn[v[i]]) {
      tarjan(v[i]);
      low[x] = min(low[x], low[v[i]]);
    } else if (!c[v[i]])
      low[x] = min(low[x], dfn[v[i]]);
  if (dfn[x] == low[x]) {
    tot++;
    while (zhan.top() != x) c[zhan.top()] = tot, zhan.pop();
    c[zhan.top()] = tot;
    zhan.pop();
  }
}
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) {
    len = read();
    for (int j = 1; j <= len; j++) a[j] = read();
    int minn = min(len, t);
    for (int j = 1; j <= minn; j++) {
      if (a[j] > las[j])
        add(a[j], las[j]), add(las[j] + m, a[j] + m);
      else if (a[j] < las[j])
        add(las[j] + m, las[j]), add(a[j], a[j] + m);
      else if (j == minn && t > len) {
        printf("No\n");
        return 0;
      }
      if (a[j] != las[j]) break;
    }
    t = len;
    for (int j = 1; j <= len; j++) las[j] = a[j];
  }
  for (int i = 1; i <= (m << 1); i++)
    if (!dfn[i]) tarjan(i);
  for (int i = 1; i <= m; i++)
    if (c[i] == c[i + m]) {
      printf("No\n");
      return 0;
    }
  printf("Yes\n");
  int ans = 0;
  for (int i = 1; i <= m; i++)
    if (c[i] < c[i + m]) ans++;
  printf("%d\n", ans);
  for (int i = 1; i <= m; i++)
    if (c[i] < c[i + m]) printf("%d ", i);
  return 0;
}
