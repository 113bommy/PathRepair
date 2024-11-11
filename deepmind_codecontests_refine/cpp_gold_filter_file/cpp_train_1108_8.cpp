#include <bits/stdc++.h>
using namespace std;
const unsigned long long maxn = 500100;
const unsigned long long oo = 2e18;
unsigned long long a[maxn], b[maxn], h[maxn];
unsigned long long n, R, m;
bool can(unsigned long long k) {
  unsigned long long st = 1, ed = min(R + 1, n), sum = 0;
  unsigned long long c = 0;
  for (unsigned long long i = 1; i <= n; i++) {
    b[i] = a[i];
    if (i <= ed) sum += b[i];
  }
  for (unsigned long long i = 1; i <= n; i++) {
    if (sum < k) {
      unsigned long long x = k - sum;
      b[min(i + R, n)] += x;
      sum += x;
      c += x;
    }
    if (st + R <= i) {
      sum -= b[st];
      st++;
    }
    if (ed < n) {
      ed++;
      sum += b[ed];
    }
    if (c > m) return 0;
  }
  return 1;
}
unsigned long long get() {
  unsigned long long l = 0, r = oo;
  while (l + 1 < r) {
    unsigned long long k = (l + r) / 2;
    if (can(k))
      l = k;
    else
      r = k;
  }
  return l;
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> R >> m;
  for (unsigned long long i = 1; i <= n; i++) cin >> a[i];
  cout << get() << endl;
  return 0;
}
