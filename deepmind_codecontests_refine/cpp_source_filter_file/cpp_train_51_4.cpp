#include <bits/stdc++.h>
using namespace std;
struct fenwin_tree {
  long long sum[200200];
  void add(int x, int val) {
    while (x < 200200) {
      sum[x] += val, x += x & -x;
    }
  }
  long long calc(int x) {
    long long rlt = 0;
    while (x) {
      rlt += sum[x], x -= x & -x;
    }
    return rlt;
  }
} A, B;
int n, k, a, b, q, type, val, d, p, f[200200], g[200200];
int main() {
  scanf("%d %d %d %d %d", &n, &k, &a, &b, &q);
  while (q--) {
    scanf("%d", &type);
    if (type == 1) {
      scanf("%d %d", &d, &val);
      int x = min(val, a - f[d]);
      A.add(d, x), f[d] += x;
      int y = min(val, b - g[d]);
      B.add(d, y), g[d] += y;
    } else {
      scanf("%d", &p);
      printf("%I64d\n", A.calc(p - 1) + B.calc(n) - B.calc(p + k - 1));
    }
  }
  return 0;
}
