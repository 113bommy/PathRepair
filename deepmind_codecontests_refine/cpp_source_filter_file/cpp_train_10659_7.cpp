#include <bits/stdc++.h>
using namespace std;
const int N = 11111;
int h[N], f[N], opt[N], a[N], b[N], c[N], d[N];
int n, m, i, j, k, x, ch;
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) f[i] = i;
  for (i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
    if (b[i]) f[find(i)] = f[find(b[i])];
  }
  for (i = 1; i <= n; i++)
    if (f[find(m)] != i) {
      int cnt = 0;
      for (j = 1; j <= n; j++)
        if (f[find(j)] == i) cnt++;
      if (cnt) a[++ch] = cnt;
    }
  opt[1] = 1;
  for (i = 1; i <= ch; i++)
    for (j = n; j >= a[i]; j--) opt[j] |= opt[j - a[i]];
  int cnt = 0, top = 0;
  for (i = 1; i <= n; i++)
    if (f[find(i)] == f[find(m)]) c[++cnt] = i;
  queue<int> q;
  for (i = 1; i <= cnt; i++)
    if (!b[c[i]]) {
      d[++top] = c[i];
      q.push(i);
    }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (i = 1; i <= cnt; i++)
      if (b[c[i]] == u) {
        int v = c[i];
        b[v] = 0;
        d[++top] = v;
        q.push(v);
      }
  }
  for (x = 1; x <= top; x++)
    if (d[x] == m) break;
  x--;
  for (i = 1; i <= n - cnt + 1; i++)
    if (opt[i]) printf("%d\n", i + x);
}
