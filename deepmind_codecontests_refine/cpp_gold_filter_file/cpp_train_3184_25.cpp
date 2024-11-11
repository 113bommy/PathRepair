#include <bits/stdc++.h>
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
using namespace std;
int n, rt;
vector<int> g[N];
long long a[N], l, r, t;
int main() {
  scanf("%I64d%I64d%I64d", &l, &r, &t);
  scanf("%d", &n);
  if (n == 0) {
    printf("%lld\n", l);
    return 0;
  }
  for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
  long long ret = 1e13;
  long long p;
  if (a[1] > 0 && a[1] <= l)
    ret = min(ret, l - a[1] + 1), p = a[1] - 1;
  else if (a[1] > l)
    ret = 0, p = l;
  if (ret == 0) {
    printf("%lld\n", p);
    return 0;
  }
  long long now = max(l, a[1]);
  for (int i = 1; i <= n; ++i) {
    if (now + t > r) break;
    if (i != 1) {
      if (a[i] > now) {
        printf("%lld\n", now);
        return 0;
      }
      if (ret > now - a[i] + 1) {
        ret = now - a[i] + 1;
        p = a[i] - 1;
      }
    }
    now = max(now, a[i]);
    int cnt = 1;
    while (i + 1 <= n && a[i + 1] == a[i]) ++cnt, ++i;
    now += 1ll * cnt * t;
  }
  if (now + t <= r) {
    printf("%lld\n", now);
    return 0;
  }
  printf("%lld\n", p);
  return 0;
}
