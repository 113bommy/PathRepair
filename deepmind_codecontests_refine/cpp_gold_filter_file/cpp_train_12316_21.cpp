#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, l, d, sum, ans, i;
  scanf("%d%d%d%d%d", &k, &l, &m, &n, &d);
  sum = 0;
  ans = d;
  for (i = 1; i <= d; i++) {
    sum = 0;
    if (i % k == 0) sum = 1;
    if (i % l == 0) sum = 1;
    if (i % m == 0) sum = 1;
    if (i % n == 0) sum = 1;
    if (sum == 0) ans--;
  }
  printf("%d\n", ans);
}
