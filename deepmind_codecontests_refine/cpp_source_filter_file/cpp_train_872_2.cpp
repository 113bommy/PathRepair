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
int q, op;
int xa, ya, xb, yb;
long long v;
long long sum[2][2][1010][1010];
void XOR(int x, int y, int z) {
  for (int i = x; i <= n; i += (i & (-i))) {
    for (int j = y; j <= n; j += (j & (-j))) {
      sum[x & 1][y & 1][i][j] ^= z;
    }
  }
}
void range_xor(int xa, int ya, int xb, int yb, long long z) {
  XOR(xa, ya, z);
  XOR(xa, yb + 1, -z);
  XOR(xb + 1, ya, -z);
  XOR(xb + 1, yb + 1, z);
}
long long ask(int x, int y) {
  long long res = 0;
  for (int i = x; i >= 1; i -= (i & (-i))) {
    for (int j = y; j >= 1; j -= (j & (-j))) {
      res ^= sum[x & 1][y & 1][i][j];
    }
  }
  return res;
}
long long range_ask(int xa, int ya, int xb, int yb) {
  return ask(xb, yb) ^ ask(xb, ya - 1) ^ ask(xa - 1, yb) ^ ask(xa - 1, ya - 1);
}
void Solve() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d", &op);
    if (op == 2) {
      scanf("%d%d%d%d%I64d", &xa, &ya, &xb, &yb, &v);
      range_xor(xa, ya, xb, yb, v);
    }
    if (op == 1) {
      scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
      printf("%I64d\n", range_ask(xa, ya, xb, yb));
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
