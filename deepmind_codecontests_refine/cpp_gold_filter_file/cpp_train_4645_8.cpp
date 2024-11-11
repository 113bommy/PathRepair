#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int r, s = 0, c;
  for (; !isdigit(c = getchar()); s = c)
    ;
  for (r = c ^ 48; isdigit(c = getchar()); (r *= 10) += c ^ 48)
    ;
  return s ^ 45 ? r : -r;
}
const int N = 300010, L = 20;
int n, opt, f;
int a[2][N], l[2], l3;
int d, d1, d2, d3;
int fa[N][L];
int dep[N];
void modify(int u, int f) {
  dep[u] = dep[f] + 1;
  fa[u][0] = f;
  for (int i = 1; (1 << i) <= dep[u]; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
}
int dis(int u, int v) {
  if (u == v) return 0;
  if (dep[u] < dep[v]) swap(u, v);
  int ans = 0;
  for (int i = 19; i >= 0; i--)
    if (dep[v] + (1 << i) <= dep[u]) {
      u = fa[u][i];
      ans += (1 << i);
    }
  if (u == v) return ans;
  for (int i = 19; i >= 0; i--)
    if (fa[u][i] != fa[v][i]) {
      ans += ((1 << i) << 1);
      u = fa[u][i], v = fa[v][i];
    }
  return ans + 2;
}
void debug(int x) {
  cout << "-----------------------" << endl;
  cout << x << ":\n";
  cout << l[0] << ' ' << l[1] << endl;
  for (int i = 1; i <= l[0]; i++) cout << a[0][i] << ' ';
  cout << endl;
  for (int i = 1; i <= l[1]; i++) cout << a[1][i] << ' ';
  cout << endl;
  cout << "-----------------------" << endl;
}
int main() {
  n = read();
  a[0][1] = 1, l[0] = 1;
  a[1][1] = 2, l[1] = 1;
  dep[1] = 1, dep[2] = 2;
  f = read();
  d = 1;
  puts("2");
  modify(1, 0);
  modify(2, 1);
  for (int i = 3; i <= n + 1; i++) {
    d1 = d2 = 0;
    f = read();
    modify(i, f);
    if (l[0]) d1 = dis(i, a[0][1]);
    if (l[1]) d2 = dis(i, a[1][1]);
    d3 = max(d1, d2);
    if (d3 == d1)
      opt = 0;
    else
      opt = 1;
    l3 = 0;
    if (d3 > d) {
      d = d3;
      for (int j = 1; j <= l[opt ^ 1]; j++)
        if (dis(i, a[opt ^ 1][j]) == d) a[opt][++l[opt]] = a[opt ^ 1][j];
      l[opt ^ 1] = 0;
    }
    if (d3 == d) a[opt ^ 1][++l[opt ^ 1]] = i;
    printf("%d\n", l[0] + l[1]);
  }
  return 0;
}
