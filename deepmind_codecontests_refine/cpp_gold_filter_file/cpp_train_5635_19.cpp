#include <bits/stdc++.h>
using namespace std;
unsigned long long f[65], g[65];
void pre() {
  for (int i = 1; i <= 61; i++) {
    f[i] = f[i - 1] + (1uLL << i) - 1;
    g[i] = 4uLL * g[i - 1] + 1;
  }
}
int main() {
  pre();
  int cases;
  scanf("%d", &cases);
  for (; cases; cases--) {
    unsigned long long n, k;
    scanf("%llu%llu", &n, &k);
    unsigned long long ans = -1;
    for (int i = 0; i <= min(61uLL, n); i++) {
      unsigned long long l = f[i],
                         r = (n <= 32)
                                 ? g[n] - ((1uLL << (i + 1)) - 1) * g[n - i]
                                 : k;
      if (i == 0) r = 0;
      if (l <= k && r >= k) {
        ans = n - i;
        break;
      }
    }
    if (ans == -1)
      puts("NO");
    else
      printf("YES %llu\n", ans);
  }
  return 0;
}
