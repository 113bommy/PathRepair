#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e3 + 10, M = 2e4;
int n, a[N];
bool minimize(int &x, int y) {
  if (x > y)
    x = y;
  else
    return 0;
  return 1;
}
int main() {
  scanf("%d", &n);
  for (auto i = 0; i < n; i++) scanf("%d", a + i);
  sort(a, a + n);
  int ans = inf, ansv, anst;
  for (auto step = 0; step <= M; step++) {
    int mi = inf, ma = -inf;
    for (auto i = 0; i < n; i++) {
      mi = min(mi, a[i] - step * i);
      ma = max(ma, a[i] - step * i);
    }
    int use = (ma - mi + 1) >> 1;
    if (minimize(ans, use)) ansv = mi + use, anst = step;
  }
  printf("%d\n%d %d", ans, ansv, anst);
}
