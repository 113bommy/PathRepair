#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
set<int> xs[N], ys[N];
int x[N], y[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", x + i, y + i);
    xs[y[i]].insert(x[i]);
    ys[x[i]].insert(y[i]);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    auto a = ys[x[i]].upper_bound(y[i]);
    auto b = xs[y[i]].upper_bound(x[i]);
    while (a != ys[x[i]].end() && b != xs[y[i]].end()) {
      if (*a - y[i] > *b - x[i])
        b = xs[y[i]].lower_bound(x[i] + *a - y[i]);
      else if (*a - y[i] < *b - x[i])
        a = ys[x[i]].lower_bound(y[i] + *b - x[i]);
      else {
        if (ys[*b].find(*a) != ys[*b].end()) ans++;
        a++, b++;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
