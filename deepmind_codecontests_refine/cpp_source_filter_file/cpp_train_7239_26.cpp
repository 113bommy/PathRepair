#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:64000000")
template <class T>
inline T sqr(T x) {
  return x * x;
}
int n;
int a[6][6];
int lower[6][6];
int upper[6][6];
int cur_flow;
int best, cost;
int f[7][7];
void rec(int v, int to, int fuel) {
  if (v == n - 1) {
    if (fuel != cur_flow) return;
    best = max(best, cost);
    return;
  }
  if (to == n) {
    if (fuel) return;
    int in = 0;
    for (int i = 0; i < n; ++i) in += f[i][v + 1];
    rec(v + 1, v + 2, in);
    return;
  }
  int lim = min(fuel, upper[v][to]);
  for (int give = lower[v][to]; give <= lim; ++give) {
    f[v][to] = give;
    if (give) cost += a[v][to] + sqr(give);
    rec(v, to + 1, fuel - give);
    if (give) cost -= a[v][to] + sqr(give);
    f[v][to] = 0;
  }
}
pair<int, int> solve() {
  for (int fuel = 0; fuel < 6; ++fuel) {
    best = INT_MIN;
    cost = 0;
    memset(f, 0, sizeof f);
    cur_flow = fuel;
    rec(0, 1, fuel);
    if (best != INT_MIN) return make_pair(fuel, best);
  }
  return make_pair(-1, -1);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < (n * (n - 1)) / 2; ++i) {
    int x, y, l, r, c;
    scanf("%d%d%d%d%d", &x, &y, &l, &r, &c);
    --x, --y;
    a[x][y] = c;
    lower[x][y] = l;
    upper[x][y] = r;
  }
  pair<int, int> res = solve();
  printf("%d %d\n", res.first, res.second);
  return 0;
}
