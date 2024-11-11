#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
int dblcmp(double d) {
  if (fabs(d) < eps) return 0;
  return d > eps ? 1 : -1;
}
const long long mod = 1000000007LL;
int a[1111111], n;
long long v[1111111];
long long p(int x) {
  long long s = 0;
  for (int i = x; i; i -= i & (-i)) {
    s += v[i];
    s %= mod;
  }
  return s;
}
void c(int x, long long t) {
  for (int i = x; i <= 1000000; i += i & (-i)) {
    v[i] += t;
    v[i] %= mod;
  }
}
long long ps[1111111];
int l[1111111];
long long sum[1111111];
int main() {
  int i, j, k;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", a + i);
    long long t = 1 + p(a[i]);
    t *= a[i];
    t %= mod;
    ps[i] = t;
    long long pr = sum[a[i]];
    ps[i] -= pr;
    ps[i] = (ps[i] % mod + mod) % mod;
    c(a[i], ps[i]);
    sum[a[i]] += ps[i];
    sum[a[i]] %= mod;
  }
  long long ans = 0;
  for (i = 1; i <= n; i++) {
    ans += ps[i];
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
