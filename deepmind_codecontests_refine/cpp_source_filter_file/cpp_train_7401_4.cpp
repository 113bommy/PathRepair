#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10;
long long n;
long long a[N], b[N];
inline long long check(long long x) {
  if (x == 0)
    return n;
  else
    return x;
}
signed main() {
  long long maxn = 0, id = -1;
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++)
    scanf("%lld", &b[i]), a[i] = b[i], maxn = max(maxn, b[i]);
  a[0] = b[0] = b[n];
  for (long long i = 1; i <= n; i++)
    if (b[i] == maxn && b[i - 1] ^ maxn) {
      id = i;
      break;
    }
  if (!~id) {
    if (maxn == 0) {
      printf("YES\n");
      for (long long i = 1; i <= n; i++) printf("%lld ", 1);
    } else {
      printf("NO\n");
    }
  } else {
    a[check((id - 1 + n) % n)] += maxn;
    for (long long i = 1; i < n; i++)
      a[check((id - i + n) % n)] += a[check((id - i + 1 + n) % n)];
    printf("YES\n");
    for (long long i = 1; i <= n; i++) printf("%lld ", a[i]);
  }
}
