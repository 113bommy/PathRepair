#include <bits/stdc++.h>
using namespace std;
int n, q, is[7005], p[7005], mu[7005], m;
bitset<7005> a[7005], c[100005], b[7005], ans;
signed main() {
  scanf("%d%d", &n, &q);
  mu[1] = 1;
  for (int i = 2; i <= 7000; i++) {
    if (!is[i]) p[++m] = i, mu[i] = -1;
    for (int j = 1; j <= m && p[j] * i <= 7000; j++) {
      is[p[j] * i] = 1;
      if (i % p[j] == 0)
        mu[i * p[j]] = 0;
      else
        mu[i * p[j]] = -mu[i];
      if (i % p[j] == 0) break;
    }
  }
  for (int i = 1; i <= 7000; i++)
    for (int j = i; j <= 7000; j += i) {
      a[j][i] = 1;
      b[i][j] = (mu[j / i] + 2) % 2;
    }
  for (int i = 1, op, x, y, v, z; i <= q; i++) {
    scanf("%d", &op);
    if (op == 1)
      scanf("%d%d", &x, &v), c[x] = a[v];
    else if (op == 2)
      scanf("%d%d%d", &x, &y, &z), c[x] = c[y] ^ c[z];
    else if (op == 3)
      scanf("%d%d%d", &x, &y, &z), c[x] = c[y] & c[z];
    else {
      scanf("%d%d", &x, &v);
      ans = c[x] & b[v];
      cout << ans.count() % 2;
    }
  }
}
