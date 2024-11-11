#include <bits/stdc++.h>
using namespace std;
const int N = 100020;
int n;
long long a[N];
int res[N], pos[65];
bitset<N> f[65];
int main() {
  scanf("%d", &n);
  long long X = 0;
  int tot = 0;
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), X ^= a[i];
  for (int bit = 0; bit < 2; bit++)
    for (int i = 62; i >= 0; i--)
      if (((X >> i) & 1) == bit) {
        tot++;
        for (int j = 1; j <= n; j++)
          if ((a[j] >> i) & 1) f[tot][j] = 1;
        f[tot][n + 1] = bit ^ 1;
        for (int j = 1; j < tot; j++)
          if (f[tot][pos[j]]) f[tot] ^= f[j];
        pos[tot] = 0;
        for (int j = 1; j <= n; j++)
          if (f[tot][j]) {
            pos[tot] = j;
            break;
          }
        if (!pos[tot]) {
          tot--;
          continue;
        }
        for (int j = 1; j < tot; j++)
          if (f[j][pos[tot]]) f[j] ^= f[tot];
      }
  for (int i = 0; i <= 62; i++) res[pos[i]] = f[i][n + 1];
  for (int i = 1; i <= n; i++) printf("%lld ", 2 - res[i]);
  return 0;
}
