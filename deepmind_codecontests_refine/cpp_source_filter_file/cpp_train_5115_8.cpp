#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;
const long long inf = 1e9 + 7;
long long a, fa[N], s[N], ans;
signed main() {
  scanf("%lld", &a);
  for (long long i = 2; i <= a; i++) scanf("%lld", &fa[i]);
  for (long long i = 1; i <= a; i++) {
    scanf("%lld", &s[i]);
    if (s[i] == -1) s[i] = inf;
  }
  for (long long i = 2; i <= a; i++) s[fa[i]] = min(s[i], s[fa[i]]);
  for (long long i = 2; i <= a; i++) {
    if (s[i] < s[fa[i]]) {
      puts("-1");
      return 0;
    }
    if (s[i] <= 1e9) ans += s[i] - s[fa[i]];
  }
  printf("%lld", ans);
  return 0;
}
