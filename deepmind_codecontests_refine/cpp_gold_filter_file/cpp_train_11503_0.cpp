#include <bits/stdc++.h>
using namespace std;
int check(int n, int low, int high) { return (n - (high - low)) / 2; }
int main() {
  int n, m, x, prev, u, v, ans = 0;
  ;
  scanf("%d %d", &n, &m);
  scanf("%d %d", &x, &prev);
  int flag = 1;
  ans = prev + x - 1;
  for (int i = 1; i < m; i++) {
    scanf("%d %d", &u, &v);
    int range = u - x;
    if (abs(v - prev) > range) {
      flag = false;
    }
    ans = max(ans, max(prev, v) + check(range, min(prev, v), max(prev, v)));
    x = u;
    prev = v;
  }
  ans = max(ans, prev + n - x);
  if (flag) {
    printf("%d\n", ans);
  } else
    puts("IMPOSSIBLE");
  return 0;
}
