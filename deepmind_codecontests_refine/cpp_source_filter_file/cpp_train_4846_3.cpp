#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, siz = 1e6 + 5;
long long t, n, m, k, a[siz], prime[siz], factors[siz];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (long long i = 2; i < siz; i++) {
    if (prime[i]) continue;
    for (long long j = i; j < siz; j += i) prime[j] = i;
  }
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    while (x > 1) {
      long long cur = prime[x], cnt = 0;
      while (x % cur == 0) cnt++, x /= cur;
      factors[cur] = max(factors[cur], cnt);
    }
  }
  long long f = 1;
  while (k > 1) {
    if (factors[prime[k]] < 0) {
      f = 0;
      break;
    }
    factors[prime[k]]--;
    k /= prime[k];
  }
  if (f)
    cout << "Yes\n";
  else
    cout << "No\n";
}
