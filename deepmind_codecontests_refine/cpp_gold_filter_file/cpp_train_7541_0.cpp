#include <bits/stdc++.h>
int read() {
  int r = 0, t = 1, c = getchar();
  while (c < '0' || c > '9') {
    t = c == '-' ? -1 : 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    r = r * 10 + c - 48;
    c = getchar();
  }
  return r * t;
}
const int N = 200010;
int n, f[N], q;
long long w[N];
std::pair<long long, int> mi[N], Mi[N], mx[N], Mx[N];
int getf(int u) {
  if (u == f[u]) return u;
  int F = getf(f[u]);
  w[u] += w[f[u]];
  return f[u] = F;
}
int merge(int u, int v, int d) {
  int x = getf(u), y = getf(v);
  if (x == y) return w[u] - w[v] == d;
  f[x] = y;
  w[x] = d - w[u] + w[v];
  if (mi[x].first + w[x] <= mi[y].first) {
    Mi[y] = mi[y];
    mi[y] = {mi[x].first + w[x], mi[x].second};
  } else if (mi[x].first + w[x] <= Mi[y].first) {
    Mi[y] = {mi[x].first + w[x], mi[x].second};
  }
  if (Mi[x].second && Mi[x].first + w[x] <= Mi[y].first) {
    Mi[y] = {Mi[x].first + w[x], Mi[x].second};
  }
  if (mx[x].first + w[x] >= mx[y].first) {
    Mx[y] = mx[y];
    mx[y] = {mx[x].first + w[x], mx[x].second};
  } else if (mx[x].first + w[x] >= Mx[y].first) {
    Mx[y] = {mx[x].first + w[x], mx[x].second};
  }
  if (Mx[x].second && Mx[x].first + w[x] >= Mx[y].first) {
    Mx[y] = {Mx[x].first + w[x], Mx[x].second};
  }
  return 1;
}
long long Div(long long a, long long b) { return (a + a + b) / (b + b); }
long long Mxd;
int main() {
  n = read();
  q = read();
  for (int i = (1), end_i = (n); i <= end_i; i++) {
    f[i] = i;
    mi[i] = mx[i] = {0, i};
  }
  for (int i = (1), end_i = (q); i <= end_i; i++) {
    int u = read(), v = read(), w = read(), b = read(), flag = 1;
    if (!merge(u, v, w * b)) flag = 0;
    int x = getf(u);
    if (getf(1) == x &&
        (mx[x].second != 1 || (mx[x].first == Mx[x].first && Mx[x].second)))
      flag = 0;
    if (getf(n) == x &&
        (mi[x].second != n || (mi[x].first == Mi[x].first && Mi[x].second)))
      flag = 0;
    if (getf(1) != x && getf(n) != x)
      Mxd = std::max(Mxd, mx[x].first - mi[x].first);
    if (getf(1) == getf(n) && ::w[1] - ::w[n] <= Mxd) flag = 0;
    if (!flag) {
      printf("BAD %d\n", i);
      return 0;
    }
  }
  if (getf(1) == getf(n)) {
    printf("%lld\n", w[1] - w[n]);
    return 0;
  } else
    printf("UNKNOWN\n");
  return 0;
}
