#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
struct node {
  int l, r, mx;
} T[N];
int n, m, q[N], num = 0;
void zb() {
  puts("IMPOSSIBLE");
  exit(0);
}
int dfs(int nw, int Rb) {
  int t = nw + 1;
  if (T[nw].l >= t) t = dfs(t, T[nw].l);
  if (t > T[nw].r) zb();
  q[++num] = nw;
  Rb = max(Rb, T[nw].mx);
  if (t <= Rb) dfs(t, Rb);
  return t;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    T[i].l = -1e9;
    T[i].r = 1e9;
    T[i].mx = -1e9;
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    char kd[10];
    scanf("%d%d%s", &x, &y, kd);
    if (y <= x) zb();
    T[x].mx = max(T[x].mx, y);
    if (kd[0] == 'R') {
      T[x].r = min(T[x].r, y);
    }
    if (kd[0] == 'L') {
      T[x].l = max(T[x].l, y);
    }
  }
  dfs(1, n);
  for (int i = 1; i <= n; i++) printf("%d ", q[i]);
  puts("");
  return 0;
}
