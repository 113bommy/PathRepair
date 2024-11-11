#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long inf = 1e18;
inline long long in() {
  long long x;
  scanf("%lld", &x);
  return x;
}
int32_t main() {
  long long n = in();
  long long k = in();
  long long a[n];
  for (long long i = 0; i < n; i++) a[i] = in();
  map<long long, long long> f;
  long long pre[n + 1];
  pre[0] = 0;
  for (long long i = 1; i <= n; i++) pre[i] = a[i - 1] + pre[i - 1];
  long long cur = 1;
  long long ans = 0, tmp = 0;
  while (cur <= inf) {
    tmp = 0;
    for (long long i = 0; i <= n; i++) {
      tmp += f[pre[i] - cur];
      f[pre[i]]++;
    }
    f.clear();
    ans += tmp;
    if (k == 1 or (k == -1 and cur == -1)) break;
    cur *= k;
  }
  cout << ans;
}
