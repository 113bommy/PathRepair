#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)(2e6 + 123);
const int R = (int)(2e6);
const long long inf = (long long)(5e6 + 7);
long long pn, p[maxn], lp[maxn], b[maxn];
bool u[maxn];
void resheto(long long n) {
  for (long long i = 3; i * i <= n; i += 2)
    if (!u[i])
      for (long long j = i * i; j <= n; j += 2 * i) u[j] = 1;
  p[pn++] = 2;
  for (long long i = 3; i <= n; i += 2)
    if (!u[i]) p[pn++] = i;
  for (long long i = 0; i < pn; ++i) {
    for (long long j = p[i]; j <= n; j += p[i]) lp[j] = p[i];
  }
}
long long n, val, x, k, t, ans1;
long long res(long long x) {
  long long ans = x;
  for (long long mask = 1; mask < (1 << n); ++mask) {
    long long cnt = 0, a = 1;
    for (long long i = 0; i < n; ++i) {
      if ((mask >> i) & 1) {
        cnt++;
        a *= b[i];
      }
    }
    if (cnt & 1)
      ans -= x / a;
    else
      ans += x / a;
  }
  return ans - ans1;
}
long long bin(long long l, long long r, long long k) {
  while (r - l > 1) {
    long long m = (l + r) / 2;
    if (res(m) >= k)
      r = m;
    else
      l = m;
  }
  if (res(l) == k) return l;
  return r;
}
int main() {
  ios_base ::sync_with_stdio(NULL);
  resheto(R);
  cin >> t;
  for (long long cs = 1; cs <= t; ++cs) {
    cin >> x >> val >> k;
    n = ans1 = 0;
    while (val != 1) {
      b[n++] = lp[val];
      long long y = lp[val];
      while (val % y == 0) val /= y;
    }
    ans1 = res(x);
    cout << bin(x + 1, inf, k) << endl;
  }
  return 0;
}
