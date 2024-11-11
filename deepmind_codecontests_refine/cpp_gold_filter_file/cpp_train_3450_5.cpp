#include <bits/stdc++.h>
using namespace std;
int r[150010], l[150010], nex[150010], n, f[150010];
int find(int u) {
  if (f[u] == u)
    return u;
  else
    return f[u] = find(f[u]);
}
int main() {
  int x, y;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    r[i] = l[i] = f[i] = i;
  }
  for (int i = 0; i < n - 1; i++) {
    scanf("%d%d", &x, &y);
    int xx = find(x);
    int yy = find(y);
    f[yy] = xx;
    nex[r[xx]] = l[yy];
    r[xx] = r[yy];
  }
  x = l[find(1)];
  while (x) {
    printf("%d ", x);
    x = nex[x];
  }
}
