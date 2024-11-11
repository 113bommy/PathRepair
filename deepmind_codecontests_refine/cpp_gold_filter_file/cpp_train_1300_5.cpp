#include <bits/stdc++.h>
using namespace std;
const long long linf = 1e18 + 5;
const int mod = (int)1e9 + 7;
const int logN = 17;
const int inf = 1e9;
const int N = 2e5 + 5;
int w[N], n, m, a[N], x, y, q;
pair<int, int> b[N];
int find_left(int x, int l) {
  int bas = 1, son = x;
  while (bas < son) {
    int orta = bas + son >> 1;
    if (a[x] - a[orta] <= l)
      son = orta;
    else
      bas = orta + 1;
  }
  return bas;
}
int find_right(int x, int l) {
  int bas = x, son = n;
  while (bas < son) {
    int orta = bas + son >> 1;
    if (bas == orta) orta++;
    if (a[orta] - a[x] <= l)
      bas = orta;
    else
      son = orta - 1;
  }
  return bas;
}
int f(int x, int l, int dir) {
  if (dir == 0) {
    int y = find_right(x, l), dist = a[y] - a[x];
    if (x == y) return x;
    if (find_left(y, l - dist) != x) return f(y, l - dist, 1);
    if ((l / dist) & 1) return f(y, l % dist, 1);
    return f(x, l % dist, 0);
  } else {
    int y = find_left(x, l), dist = a[x] - a[y];
    if (x == y) return x;
    if (find_right(y, l - dist) != x) return f(y, l - dist, 0);
    if ((l / dist) & 1) return f(y, l % dist, 0);
    return f(x, l % dist, 1);
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    b[i] = make_pair(a[i], i);
  }
  sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; i++) w[b[i].second] = i;
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &x, &y);
    if (find_right(w[x], y) == w[x])
      printf("%d\n", b[f(w[x], y, 1)].second);
    else
      printf("%d\n", b[f(w[x], y, 0)].second);
  }
  return 0;
}
