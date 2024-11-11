#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
int dxx[] = {+1, 0, -1, 0, +1, +1, -1, -1};
int dyy[] = {0, +1, 0, -1, +1, -1, +1, -1};
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
int main() {
  long long l, r, k, x, i, y;
  bool flag = false;
  scanf("%lld %lld %lld", &l, &r, &k);
  x = 1;
  for (i = 1;; i++) {
    if (x >= l && x <= r) {
      flag = true;
      printf("%lld ", x);
    }
    y = x;
    x *= k;
    if (x > r || (x / k != y)) break;
  }
  if (!flag) printf("-1");
  printf("\n");
  return 0;
}
