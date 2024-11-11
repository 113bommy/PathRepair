#include <bits/stdc++.h>
using namespace std;
int father[110];
int c[110];
int t[110];
int l;
int find(int x) {
  if (x != father[x]) father[x] = find(father[x]);
  return father[x];
}
void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x != y)
    father[y] = x;
  else
    c[l++] = x;
}
int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) != EOF) {
    int a, b;
    int ans = 0;
    l = 0;
    memset(c, 0, sizeof(c));
    memset(t, 0, sizeof(t));
    for (int i = 1; i <= n; i++) father[i] = i;
    for (int i = 0; i < m; i++) {
      scanf("%d%d", &a, &b);
      merge(a, b);
    }
    for (int i = (1); i < (n + 1); i++) t[find(i)]++;
    for (int i = (0); i < (l); i++)
      if (t[find(c[i])] % 2 == 1) ans++;
    if ((n - ans) % 2 == 1) ans++;
    printf("%d\n", ans);
  }
  return 0;
}
