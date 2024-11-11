#include <bits/stdc++.h>
using namespace std;
long long w[400005], sum[400005][21], f[400005][21], mx[400005][21];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  memset(sum, 0x3f, sizeof(sum));
  int q;
  cin >> q;
  long long last = 0;
  int tot = 1;
  f[1][0] = 1, sum[1][0] = 0;
  while (q--) {
    long long op, p, q;
    cin >> op >> p >> q;
    p ^= last, q ^= last;
    if (op == 1) {
      ++tot;
      w[tot] = q, sum[tot][0] = q, f[tot][0] = tot, mx[tot][0] = q;
      if (q <= w[p]) {
        f[tot][1] = p;
        sum[tot][1] = w[p] + q;
        mx[tot][1] = max(q, w[p]);
        for (int i = 2; i <= 20; ++i) {
          f[tot][i] = f[f[f[tot][i - 1]][1]][i - 1];
          if (!f[tot][i]) break;
          mx[tot][i] = max(mx[f[f[tot][i - 1]][1]][i - 1], mx[tot][i - 1]);
          sum[tot][i] = sum[f[f[tot][i - 1]][1]][i - 1] + sum[tot][i - 1];
        }
      } else {
        for (int i = 20; i >= 1; --i) {
          if (!f[p][i]) continue;
          if (mx[p][i] < q) p = f[f[p][i]][1];
        }
        if (p && q <= w[p]) {
          f[tot][1] = p;
          sum[tot][1] = w[p] + q;
          mx[tot][1] = max(q, w[p]);
          for (int i = 2; i <= 20; ++i) {
            f[tot][i] = f[f[f[tot][i - 1]][1]][i - 1];
            if (!f[tot][i]) break;
            mx[tot][i] = max(mx[f[f[tot][i - 1]][1]][i - 1], mx[tot][i - 1]);
            sum[tot][i] = sum[f[f[tot][i - 1]][1]][i - 1] + sum[tot][i - 1];
          }
        }
      }
    } else {
      long long ans = 0, tmp = 0;
      for (int i = 20; i >= 0; --i) {
        if (!f[p][i]) continue;
        if (sum[p][i] + tmp <= q) {
          tmp += sum[p][i];
          ans += 1 << i;
          p = f[f[p][i]][1];
        }
        if (!p) break;
      }
      cout << (last = ans) << '\n';
    }
  }
}
