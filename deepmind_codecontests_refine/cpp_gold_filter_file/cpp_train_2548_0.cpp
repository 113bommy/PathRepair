#include <bits/stdc++.h>
using namespace std;
int read() {
  int s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
  return s * w;
}
struct Edge {
  int to, next;
} a[1000010 << 2];
int h[1000010], cnt = 1, q[1000010], n, m, D[1000010], v[1000010];
void add(int x, int y) {
  ++D[x], ++D[y], a[++cnt] = (Edge){y, h[x]}, h[x] = cnt,
                  a[++cnt] = (Edge){x, h[y]}, h[y] = cnt;
}
void print(int x, int y) {
  static int c;
  ++c & 1 ? cout << x << ' ' << y << '\n' : cout << y << ' ' << x << '\n';
}
void Dfs(int x) {
  int y;
  for (int& i = h[x]; i; i = a[i].next)
    if (!v[i]) v[i] = v[i ^ 1] = 1, Dfs(y = a[i].to), print(x, y);
}
signed main() {
  n = read(), m = read();
  for (int i = 1; i <= m; i++) add(read(), read());
  for (int i = 1; i <= n; i++)
    if (D[i] & 1) q[++q[0]] = i;
  for (int i = 1; i <= q[0]; i += 2) add(q[i], q[i + 1]);
  if ((m + q[0] / 2) & 1) add(1, 1);
  cout << m + q[0] / 2 + ((m + q[0] / 2) & 1) << '\n', Dfs(1);
  return 0;
}
