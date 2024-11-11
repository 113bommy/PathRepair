#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7, MOD2 = 1e9 + 97, EPS = 1e-6;
const int N = 1e5 + 5;
int n, k, a[N], kn[N];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i <= n; ++i) {
    if (scanf("%d", &a[i]) == 1)
      kn[i] = 1;
    else
      scanf("%*c");
  }
  int t = 0;
  for (int i = 0; i <= n; ++i) t += kn[i];
  if (k == 0) {
    if (kn[0]) return 0 * printf("%s\n", a[0] ? "No" : "Yes");
    return 0 * printf("%s\n", t % 2 ? "Yes" : "No");
  }
  if (t == n + 1) {
    long long s0 = 0, s1 = 0, nk = 1;
    for (int i = 0; i <= n; ++i)
      s0 = (s0 + a[i] * nk) % MOD, nk = (nk * k) % MOD;
    nk = 1;
    for (int i = 0; i <= n; ++i)
      s1 = (s1 + a[i] * nk) % MOD2, nk = (nk * k) % MOD2;
    printf("%s\n", (s0 or s1) ? "No" : "Yes");
    return 0;
  }
  printf("%s\n", t % 2 ? ((n + 1 - t) % 2 ? "Yes" : "No")
                       : ((n + 1 - t) % 2 ? "No" : "Yes"));
  return 0;
}
