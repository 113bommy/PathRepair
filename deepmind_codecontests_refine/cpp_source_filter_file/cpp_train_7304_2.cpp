#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long long N = 3e5 + 6;
const long long Log2 = 19;
const long long mod = 1e9 + 7;
long long n, p, k, a[N], ans;
map<long long, long long> mp;
long long cal(long long x) { return x * x % mod; }
long long process(long long x) {
  return (cal(x) * cal(x) % p - k * x % p + p * p) % p;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  if (fopen("tst"
            ".inp",
            "r")) {
    freopen(
        "tst"
        ".inp",
        "r", stdin);
  }
  cin >> n >> p >> k;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    long long cur = process(a[i]);
    long long now = mp[cur];
    ans += now * (now - 1) / 2;
    ans += now * (now + 1) / 2;
    mp[cur]++;
  }
  cout << ans;
}
