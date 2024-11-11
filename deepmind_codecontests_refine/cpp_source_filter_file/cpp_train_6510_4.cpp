#include <bits/stdc++.h>
using namespace std;
int _MAX(int a, int b) { return a > b ? a : b; }
int _MIN(int a, int b) { return a > b ? b : a; }
int b[200005], c[200005];
map<int, int> vis;
int main() {
  int n, m, a1 = 0, a2 = 0, p, x;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &x), vis[x]++;
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) scanf("%d", b + i);
  for (int i = 1; i <= m; ++i) scanf("%d", c + i);
  for (int i = 1; i <= m; ++i) {
    if (vis[b[i]] > a1)
      p = i, a1 = vis[b[i]], a2 = vis[c[i]];
    else if (vis[b[i]] == a1 && vis[c[i]] > a2)
      p = i, a1 = vis[b[i]], a2 = vis[c[i]];
  }
  printf("%d\n", p);
  return 0;
}
