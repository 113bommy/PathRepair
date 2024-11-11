#include <bits/stdc++.h>
const int maxn = 1e5 + 10;
using namespace std;
int n;
long long rec[maxn];
int main() {
  scanf("%d", &n);
  int cnt = 0;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    long long a1, b1, a2, b2;
    scanf("%lld%lld%lld%lld", &a1, &b1, &a2, &b2);
    if (a1 + b1 >= a2 + b2) {
      rec[++cnt] = a1 + b1;
      rec[++cnt] = a2 + b2;
      ans += a1 + a2;
    } else if (a1 > b2)
      ans += a1 - b2;
    else if (b1 > a2)
      ans += b1 - a2;
  }
  sort(rec + 1, rec + cnt + 1);
  for (int i = 1; i <= cnt; i += 2) ans -= rec[i];
  printf("%lld", ans);
  return 0;
}
