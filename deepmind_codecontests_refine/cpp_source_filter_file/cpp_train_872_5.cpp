#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int MAXN = 1e3 + 10;
const int N = 3e2 + 10;
const int INF = 0x3f;
int n, m;
long long tree[2][2][MAXN][MAXN];
int lowbit(int x) { return x & -x; }
void add(int x, int y, long long v) {
  for (int i = x; i <= n; i += lowbit(i))
    for (int j = y; j <= n; j += lowbit(j)) tree[x & 1][y & 1][i][j] ^= v;
}
long long sum(int x, int y) {
  long long ret = 0;
  for (int i = x; i > 0; i -= lowbit(i))
    for (int j = y; j > 0; j -= lowbit(j)) ret ^= tree[x & 1][y & 1][i][j];
  return ret;
}
void solve() {
  int ty, x_2, y_2, x_1, y_1;
  long long v;
  while (m--) {
    scanf("%d%d%d%d%d", &ty, &x_1, &y_1, &x_2, &y_2);
    if (ty == 1) {
      long long ans = 0;
      ans ^= sum(x_2, y_2);
      ans ^= sum(x_1 - 1, y_2);
      ans ^= sum(x_2, y_1 - 1);
      ans ^= sum(x_1 - 1, y_1 - 1);
      printf("%lld\n", ans);
    } else {
      scanf("%lld", &v);
      add(x_2 + 1, y_2 + 1, v);
      add(x_1, y_2 + 1, v);
      add(x_2 + 1, y_2, v);
      add(x_1, y_1, v);
    }
  }
}
void init() { scanf("%d%d", &n, &m); }
int main() {
  int T = 1;
  for (int kase = 1; kase <= T; kase++) {
    init();
    solve();
  }
  return 0;
}
