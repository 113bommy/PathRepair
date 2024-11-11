#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
inline long long rd() {
  long long x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * w;
}
int to[N << 2], nt[N << 2], hd[N << 1], dg[N << 1], tot = 1;
void add(int x, int y) {
  ++tot, to[tot] = y, nt[tot] = hd[x], hd[x] = tot, ++dg[x];
  ++tot, to[tot] = x, nt[tot] = hd[y], hd[y] = tot, ++dg[y];
}
bool cs[N << 2], ban[N << 2], v[N << 1];
int n, m, a[N][2], b[N << 1];
void dfs(int x) {
  v[x] = 1;
  for (int &i = hd[x]; i; i = nt[i]) {
    if (ban[i]) continue;
    int y = to[i];
    ban[i] = ban[i ^ 1] = 1, cs[i] = 1;
    dfs(y);
  }
}
int main() {
  n = rd();
  for (int i = 1; i <= n; ++i)
    a[i][0] = b[i * 2 - 1] = rd(), a[i][1] = b[i * 2] = rd() + 1;
  sort(b + 1, b + n + n + 1), m = unique(b + 1, b + n + n + 1) - b - 1;
  for (int i = 1; i <= n; ++i) {
    a[i][0] = lower_bound(b + 1, b + m + 1, a[i][0]) - b;
    a[i][1] = lower_bound(b + 1, b + m + 1, a[i][1]) - b;
    add(a[i][0], a[i][1]);
  }
  for (int i = 1, la = 0; i <= m; ++i)
    if (dg[i] & 1) {
      if (!la)
        la = i;
      else
        add(la, i), la = 0;
    }
  for (int i = 1; i <= m; ++i)
    if (!v[i]) dfs(i);
  for (int i = 1; i <= n; ++i) printf("%d ", cs[i << 1]);
  return 0;
}
