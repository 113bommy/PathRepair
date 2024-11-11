#include <bits/stdc++.h>
using namespace std;
int n, ans;
int a[19];
int inv[2000009];
int f[16009];
int tag[19];
int qpow(int a, int b) {
  int ans = 1;
  for (; b; b >>= 1, a = (long long)a * a % 1000000007)
    if (b & 1) ans = (long long)ans * a % 1000000007;
  return ans;
}
void init() {
  for (int i = 1; i <= 2000000; i++) inv[i] = qpow(i, 1000000007 - 2);
}
int main() {
  init();
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int s = 1; s < (1 << n); s++) {
    int sm = 0;
    for (int t = (s - 1) & s; t; t = (t - 1) & s) {
      int p = s ^ t, pb = 1;
      for (int i = 1; i <= n; i++)
        if (t >> (i - 1) & 1)
          for (int j = 1; j <= n; j++)
            if (p >> (j - 1) & 1)
              pb = (long long)pb * a[i] % 1000000007 * inv[a[i] + a[j]] %
                   1000000007;
      sm = (sm + (long long)f[t] * pb) % 1000000007;
    }
    f[s] = (1000000007 + 1 - sm) % 1000000007;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int s = 1; s < (1 << n); s++)
      if (s >> (i - 1) & 1) {
        int pb = 1;
        for (int i = 1; i <= n; i++)
          if (s >> (i - 1) & 1)
            for (int j = 1; j <= n; j++)
              if (!(s >> (j - 1) & 1))
                pb = (long long)pb * a[i] % 1000000007 * inv[a[i] + a[j]] %
                     1000000007;
        ans = (ans + (long long)f[s] * pb) % 1000000007;
      }
  printf("%d", ans);
  return 0;
}
