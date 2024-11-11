#include <bits/stdc++.h>
using namespace std;
const long long MAXN = (long long)((1e5) + 100);
long long cuberoot(long long x) {
  long long lo = 1, hi = min(2000000ll, x);
  while (hi - lo > 1) {
    long long mid = (lo + hi) / 2;
    if (mid * mid * mid < x) {
      lo = mid;
    } else
      hi = mid;
  }
  if (hi * hi * hi <= x)
    return hi;
  else
    return lo;
}
const long long dx[4] = {-1, 1, 0, 0};
const long long dy[4] = {0, 0, -1, 1};
long long XX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
long long YY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const long long N = (long long)(1 * 1e6 + 10);
bool comp(pair<long long, pair<long long, long long>> p1,
          pair<long long, pair<long long, long long>> p2) {
  if (p1.first > p2.first)
    return true;
  else if (p1.second == p2.second) {
    if (p1.second.first < p2.second.first) return true;
  }
  return false;
}
long long fact(long long n);
long long ncr(long long n, long long r) {
  return fact(n) / (fact(r) * fact(n - r));
}
long long fact(long long n) {
  long long res = 1;
  for (long long i = 2; i <= n; i++) res = res * i;
  return res % 1000000007;
}
const long long a = 1000000000;
long long nCr(long long n, long long r) {
  long long fac1 = 1, fac2 = 1, fac;
  for (long long i = r; i >= 1; i--, n--) {
    fac1 = fac1 * n;
    if (fac1 % i == 0)
      fac1 = fac1 / i;
    else
      fac2 = fac2 * i;
  }
  fac = fac1 / fac2;
  return fac % a;
}
const long long m = 1000000007;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
signed main() {
  long long n;
  cin >> n;
  long long arr[n + 1];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long mx = 0;
  vector<long long> v;
  for (long long i = n - 1; i >= 0; i--) {
    if (i == n - 1) {
      v.push_back(0);
      mx = arr[i];
    } else {
      long long ans = 0;
      if (mx >= arr[i])
        ans = max(mx, arr[i]) - arr[i] + 1;
      else
        ans = max(mx, arr[i]) - arr[i];
      v.push_back(ans);
      mx = max(mx, arr[i]);
    }
  }
  for (long long i = n - 1; i >= 0; i--) cout << v[i] << " ";
}
