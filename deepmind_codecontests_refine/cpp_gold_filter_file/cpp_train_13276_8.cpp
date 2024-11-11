#include <bits/stdc++.h>
using namespace std;
int n, m, f[100009], sum, k, h[100009];
inline int getf(int i) {
  if (f[i] == i) return i;
  return f[i] = getf(f[i]);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i <= n; i++) f[i] = i;
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u = getf(u), v = getf(v);
    if (u != v) {
      f[u] = v;
      if (h[u] || h[v]) h[u] = h[v] = 1;
    } else {
      h[u] = h[v] = 1;
    }
  }
  for (int i = 1; i <= n; i++)
    if (f[i] == i && !h[i]) sum++;
  printf("%d", sum);
  return 0;
}
