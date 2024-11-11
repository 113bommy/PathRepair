#include <bits/stdc++.h>
using namespace std;
const int m = 500000;
int n, x, d, q[501000], s = 0;
bool v[501000];
void init() {
  scanf("%d%d", &n, &d);
  v[0] = 1;
  for (int i = (1); i <= (n); ++i) {
    scanf("%d", &x);
    for (int j = (m); j >= (x); --j)
      if (v[j - x]) v[j] = 1;
  }
  for (int i = (0); i <= (m); ++i)
    if (v[i]) q[++s] = i;
}
void work() {
  int ans = 0, sum = 0;
  x = 1;
  while (x <= s) {
    if (q[x] - ans > d) break;
    while (x < s && q[x + 1] - ans <= d) x++;
    ans = q[x];
    sum++;
    x++;
  }
  printf("%d %d\n", ans, sum);
}
int main() {
  init();
  work();
  return 0;
}
