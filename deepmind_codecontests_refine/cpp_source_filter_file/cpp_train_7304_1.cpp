#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
map<long long, long long> mp;
int main() {
  long long n, k, p, x, ans = 0;
  scanf("%lld%lld%lld", &n, &p, &k);
  for (long long i = 0; i < n; ++i) {
    scanf("%lld", &x);
    mp[((x * x % p * x * x % p - x * k % p) % p + p) % p]++;
  }
  for (auto e : mp) {
    x = e.second;
    ans += x * (x - 1) / 2;
  }
  printf("%lld\n", ans);
  return 0;
}
