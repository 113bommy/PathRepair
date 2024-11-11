#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int MAX = 1024;
int digit[128];
i64 dp[12][128][MAX][2];
int DFS(int b, int p, int mask, bool zero, bool tag) {
  if (p == -1) return !zero && !mask;
  if (!tag && ~dp[b][p][mask][zero]) return dp[b][p][mask][zero];
  i64 ret = 0;
  int up = tag ? digit[p] : b - 1;
  for (int i = 0; i <= up; ++i) {
    int nxt = mask;
    if (!zero || i) nxt ^= (1 << i);
    i64 cur = DFS(b, p - 1, nxt, zero && !i, tag && i == up);
    ret += cur;
  }
  if (!tag) dp[b][p][mask][zero] = ret;
  return ret;
}
i64 Calc(i64 n, int b) {
  int p = 0;
  for (; n; n /= b) digit[p++] = n % b;
  return DFS(b, p - 1, 0, true, true);
}
int main() {
  memset(dp, -1, sizeof(dp));
  int q;
  while (cin >> q) {
    int b;
    i64 l, r;
    for (int i = 0; i < q; ++i) {
      cin >> b >> l >> r;
      i64 ll = Calc(l - 1, b);
      i64 rr = Calc(r, b);
      cout << rr - ll << endl;
    }
  }
  return 0;
}
