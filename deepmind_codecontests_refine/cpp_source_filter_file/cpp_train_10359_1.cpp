#include <bits/stdc++.h>
using namespace std;
const int maxn = 500010, maxN = 10000010, MOD = 1e9 + 7;
int n, mx = 0, ans = 0, f[maxN], a[maxn], b[maxN], m[maxN];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    mx = max(mx, x);
    b[x]++;
  }
  m[1] = 1;
  f[0] = 1;
  for (int i = 1; i <= mx; i++) f[i] = (f[i - 1] << 1) % MOD;
  for (int i = 1; i <= mx; i++) {
    int x = b[i];
    for (int j = i + i; j <= mx; j += i) {
      m[j] -= m[i];
      x += b[j];
    }
    if (i > 1)
      ans = (ans - m[i] * (f[x] - 1) % MOD * (n - x) % MOD + MOD) % MOD;
  }
  printf("%d", ans);
}
