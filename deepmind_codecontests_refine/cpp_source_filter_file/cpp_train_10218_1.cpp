#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  long long n, k;
  scanf("%lld%lld", &n, &k);
  long long a, b;
  scanf("%lld%lld", &a, &b);
  long long val1 = (b - a + k) % k;
  long long val2 = (b + a) % k;
  long long val3 = (-b - a + 2 * k) % k;
  long long val4 = (-b + a + k) % k;
  vector<long long> v;
  for (int i = 0; i < n; ++i) {
    v.push_back(k * 1ll * i + val1);
    v.push_back(k * 1ll * i + val2);
    v.push_back(k * 1ll * i + val3);
    v.push_back(k * 1ll * i + val4);
  }
  long long mn = n * k, mx = 0;
  for (int x : v) {
    long long g = gcd(x, n * k);
    mn = min(mn, n * k / g);
    mx = max(mx, n * k / g);
  }
  printf("%lld %lld\n", mn, mx);
}
