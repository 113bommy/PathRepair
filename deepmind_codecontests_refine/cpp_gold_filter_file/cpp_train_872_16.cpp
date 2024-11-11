#include <bits/stdc++.h>
using namespace std;
int n, m;
struct bit {
  long long c[1010][1010][2][2];
  void update(int x, int y, long long s) {
    int t1 = x % 2, t2 = y % 2;
    for (int i = x; i <= n; i += (i & -i)) {
      for (int j = y; j <= n; j += (j & -j)) {
        c[i][j][t1][t2] ^= s;
      }
    }
  }
  long long getsum(int x, int y) {
    long long res = 0;
    int t1 = x % 2, t2 = y % 2;
    for (int i = x; i; i -= (i & -i)) {
      for (int j = y; j; j -= (j & -j)) {
        res ^= c[i][j][t1][t2];
      }
    }
    return res;
  }
} BIT;
int main() {
  int op, l, r;
  scanf("%d%d", &n, &m);
  while (m--) {
    int x, y;
    long long s;
    scanf("%d%d%d", &op, &l, &r);
    if (op == 2) {
      scanf("%d%d%lld", &x, &y, &s);
      BIT.update(x + 1, y + 1, s), BIT.update(x + 1, r, s);
      BIT.update(l, y + 1, s), BIT.update(l, r, s);
    } else {
      scanf("%d%d", &x, &y);
      printf("%lld\n", BIT.getsum(x, y) ^ BIT.getsum(x, r - 1) ^
                           BIT.getsum(l - 1, y) ^ BIT.getsum(l - 1, r - 1));
    }
  }
  return 0;
}
