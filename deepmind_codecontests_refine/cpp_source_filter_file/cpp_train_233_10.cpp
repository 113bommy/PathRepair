#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 11;
const long long mod = 998244353;
const long long inf = 1e9 + 1;
long long fact[N];
long long ifact[N];
long long powmod(long long base, long long exp) {
  long long res = 1;
  while (exp) {
    if (exp & 1) res = (res * base) % mod;
    base = (base * base) % mod;
    exp >>= 1;
  }
  return res;
}
void compute() {
  fact[0] = 1;
  ifact[0] = 1;
  for (long long i = 1; i < N; ++i) {
    fact[i] = (fact[i - 1] * i) % mod;
    ifact[i] = powmod(fact[i], mod - 2);
  }
}
long long ncr(long long n, long long r) {
  if (n < r) return 0;
  long long ans = (fact[n] * ifact[n - r]) % mod;
  ans = (ans * ifact[r]) % mod;
  return ans;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  compute();
  long long n, k;
  cin >> n >> k;
  vector<pair<long long, long long>> arr;
  for (long long i = 0; i < n; ++i) {
    long long l, r;
    cin >> l >> r;
    arr.push_back({l, 0});
    arr.push_back({r, 1});
  }
  if (k == 1) {
    cout << n << endl;
    return 0;
  }
  sort(arr.begin(), arr.end());
  long long ans = 0;
  long long cnt = 0;
  for (auto x : arr) {
    if (x.second == 1) {
      cnt--;
      ans = (ans + ncr(cnt, k - 1));
    } else
      cnt++;
  }
  cout << ans;
  return 0;
}
