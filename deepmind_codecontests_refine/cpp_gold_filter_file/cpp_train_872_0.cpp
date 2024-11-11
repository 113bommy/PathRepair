#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma G++ optimize(2)
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;
const double eps = 1e-6;
const long long mod = 1e9 + 7;
const int maxn = 1e6 + 100;
const int maxe = 1e6 + 100;
int n, m;
long long v;
long long t[2][2][1005][1005];
void add(int x, int y) {
  for (int i = x; i <= n; i += (i & (-i))) {
    for (int j = y; j <= n; j += (j & (-j))) {
      t[x & 1][y & 1][i][j] ^= v;
    }
  }
}
long long sum(int x, int y) {
  long long res = 0;
  for (int i = x; i >= 1; i -= (i & (-i))) {
    for (int j = y; j >= 1; j -= (j & (-j))) {
      res ^= t[x & 1][y & 1][i][j];
    }
  }
  return res;
}
void Solve() {
  while (scanf("%d%d", &n, &m) != EOF) {
    int op, x_1, x_2, y_1, y_2;
    for (int i = 0; i < m; i++) {
      scanf("%d%d%d%d%d", &op, &x_1, &y_1, &x_2, &y_2);
      if (op == 2) {
        scanf("%I64d", &v);
        add(x_1, y_1);
        add(x_1, y_2 + 1);
        add(x_2 + 1, y_1);
        add(x_2 + 1, y_2 + 1);
      }
      if (op == 1) {
        printf("%I64d\n", sum(x_2, y_2) ^ sum(x_1 - 1, y_2) ^
                              sum(x_2, y_1 - 1) ^ sum(x_1 - 1, y_1 - 1));
      }
    }
  }
  return;
}
int main() {
  int Case = 1, cases;
  while (Case--) {
    Solve();
  }
  return 0;
}
