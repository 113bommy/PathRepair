#include <bits/stdc++.h>
using namespace std;
int n, m, tmp, T, now, ans;
int main() {
  scanf("%d", &T);
  for (int Case = 1; Case <= T; ++Case) {
    scanf("%d %d", &n, &m), ans = 1 % m, now = 2, tmp = 2;
    while (now <= n) {
      ans = (1ll * (min(2ll * now - 1, 0ll + n) - now + 1) * tmp + ans) % m;
      tmp = 1ll * tmp * (now + 1) % m, now <<= 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
