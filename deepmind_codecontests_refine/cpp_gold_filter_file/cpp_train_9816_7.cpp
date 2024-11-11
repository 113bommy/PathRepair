#include <bits/stdc++.h>
using namespace std;
const long long N = 200005;
const long long B = 20;
long long JC[N];
long long n, q;
long long sum[N], a[N], b[N];
bool used[N];
void solve(long long m) {
  long long t = min(n, B);
  for (long long u = 1; u <= t + 5; u++) used[u] = false;
  for (long long u = 1; u <= t; u++) {
    long long x = t - u, t1 = m / JC[x];
    m = m - t1 * JC[x];
    for (long long i = 1; i <= t; i++) {
      if (used[i] == false) {
        if (t1 == 0) {
          b[u] = i;
          used[i] = true;
          break;
        } else
          t1--;
      }
    }
  }
  long long o = n - t + 1;
  for (long long u = o; u <= n; u++) a[u] = b[u - o + 1] + o - 1;
  for (long long u = o; u <= n; u++) sum[u] = sum[u - 1] + a[u];
}
int main() {
  JC[0] = 1;
  for (long long u = 1; u <= B; u++) JC[u] = JC[u - 1] * u;
  scanf("%lld%lld", &n, &q);
  for (long long u = 1; u <= n; u++) a[u] = u;
  for (long long i = 1; i <= n; i++) sum[i] = sum[i - 1] + i;
  long long m = 0;
  while (q--) {
    long long op;
    scanf("%lld", &op);
    if (op == 1) {
      long long l, r;
      scanf("%lld%lld", &l, &r);
      printf("%lld\n", sum[r] - sum[l - 1]);
    } else {
      long long x;
      scanf("%lld", &x);
      m = m + x;
      solve(m);
    }
  }
  return 0;
}
