#include <bits/stdc++.h>
using namespace std;
const long long LINF = 1e18 + 7;
const int N = 33;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double EPS = 1e-8;
int a, b, c, d, e, f, r[6], x[7];
const int w[] = {1, 1, -1, 1, -1, -1};
void solve() {
  r[0] = a + b - e - f;
  r[1] = a - c + d - f;
  r[2] = -a + c + e;
  r[3] = b - c + d - e;
  r[4] = c - b + f;
  r[5] = e - d + f;
  for (int i = (0); i < (6); ++i) {
    if (r[i] & 1) {
      puts("-1");
      return;
    }
    r[i] >>= 1;
  }
  x[6] = max(max(0, -r[0]), max(-r[1], -r[3]));
  for (int i = (0); i < (6); ++i) {
    x[i] = r[i] + w[i] * x[6];
    if (x[i] < 0) {
      puts("-1");
      return;
    }
  }
  int L = 0;
  for (int i = (0); i < (7); ++i) L += x[i];
  printf("%d\n", L);
  for (int i = (0); i < (4); ++i) {
    for (int j = (1); j < (8); ++j)
      for (int k = (0); k < (x[j - 1]); ++k) putchar('a' + (j >> i & 1));
    puts("");
  }
}
int main() {
  scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
  solve();
  return 0;
}
