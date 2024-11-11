#include <bits/stdc++.h>
using namespace std;
int t, T, n, m;
int l[2010000], r[2010000];
int head[2010000], to[2010000], nxt[2010000];
int col[2010000];
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
int cnt = 0;
void link(int a, int b) {
  cnt++;
  nxt[cnt] = head[a];
  to[cnt] = b;
  head[a] = cnt;
}
bool check(int x) {
  for (int i = head[x]; i; i = nxt[i])
    if (!col[to[i]]) {
      col[to[i]] = col[x] ^ 1;
      if (!check(to[i])) return 0;
    } else if (col[x] == col[to[i]])
      return 0;
  return 1;
}
int main() {
  t = read(), T = read(), n = read(), m = read();
  int n1 = 1e9, n2 = 0;
  for (int i = 1; i <= n; i++)
    l[i] = read(), r[i] = read(), n1 = min(n1, r[i]), n2 = max(n2, l[i]);
  if (n1 + n2 < t) n2 = t - n1;
  if (n1 + n2 > T) n1 = T - n2;
  if (n1 * n2 < 0) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    int p1 = (l[i] <= n1) & (n1 <= r[i]), p2 = (l[i] <= n2) & (n2 <= r[i]);
    if ((!p1) && (!p2)) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
    if (p1 && (!p2)) col[i] = 2;
    if ((!p1) && p2) col[i] = 3;
  }
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    link(x, y), link(y, x);
  }
  for (int i = 1; i <= n; i++)
    if (col[i])
      if (!check(i)) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
      }
  for (int i = 1; i <= n; i++)
    if (!col[i]) {
      col[i] = 2;
      if (!check(i)) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
      }
    }
  cout << "POSSIBLE" << endl;
  cout << n1 << " " << n2 << endl;
  for (int i = 1; i <= n; i++) cout << col[i] - 1;
  cout << endl;
  return 0;
}
