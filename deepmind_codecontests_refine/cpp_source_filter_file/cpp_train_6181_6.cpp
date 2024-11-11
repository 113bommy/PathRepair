#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n;
bitset<N> f[100], g[100];
long long sum;
int js, p[N], ans[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    long long x;
    scanf("%lld", &x);
    sum ^= x;
    for (int j = 0; j <= 64; ++j)
      if (x & (1ll << j)) g[j][i] = 1;
  }
  for (int b = 0; b <= 1; ++b)
    for (int i = 64; i >= 0; --i)
      if (((sum >> (long long)i) & 1) == b) {
        f[++js] = g[i];
        f[js][n + 1] = !b;
        for (int j = 1; j <= js - 1; ++j)
          if (f[js][p[j]]) f[js] ^= f[j];
        p[js] = n + 2;
        for (int j = 1; j <= n; ++j)
          if (f[js][j]) {
            p[js] = j;
            break;
          }
        if (p[js] > n) {
          js--;
          continue;
        }
        for (int j = 1; j <= js - 1; ++j)
          if (f[j][p[js]]) f[j] ^= f[js];
      }
  for (int i = 1; i <= js; ++i) ans[p[i]] = f[i][n + 1];
  for (int i = 1; i <= n; ++i) printf("%d ", 2 - ans[i]);
  return 0;
}
