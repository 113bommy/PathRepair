#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#pragma GCC optimize("fast-math")
using namespace std;
const long long INF = 1e9 + 228;
const long long INFLL = 1e18;
const long long MOD = 1e9 + 7;
static const long long maxn = 1e6 + 228;
;
const long double eps = 1e-5;
const long double eps2 = 1e-9;
const long long MOD2 = 998244353;
const long long dosz = 5e5;
const long long SZ = (1 << 18);
const long double PI = atan2l(0, -1);
void fast_io() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
long long binpow(long long n, long long k) {
  if (!k) return 1;
  if (k & 1) return binpow(n, k - 1) * n % MOD;
  long long b = binpow(n, k / 2);
  return b * b % MOD;
}
void solve() {
  long long n, p;
  cin >> n >> p;
  vector<long long> nums(n);
  for (long long &i : nums) cin >> i;
  if (p == 1) {
    cout << n % 2 << endl;
    return;
  }
  sort(nums.begin(), nums.end());
  map<long long, long long> kek;
  for (long long i : nums) kek[i]++;
  map<long long, long long> lol;
  set<long long> to_check;
  for (long long i : nums) {
    lol[i]++;
    to_check.insert(-i);
  }
  map<long long, bool> nabr;
  for (long long i : nums) {
    long long cur = i;
    while (lol[cur] >= p) {
      lol[cur + 1] += lol[cur] / p;
      lol[cur] %= p;
      cur++;
      nabr[cur] = true;
      to_check.insert(-cur);
    }
  }
  long long last = -1;
  long long ans = 0;
  while (!to_check.empty()) {
    long long i = -(*to_check.begin());
    to_check.erase(-i);
    if (lol[i] % 2 == 0) {
      continue;
    }
    if (lol[i] & 1) {
      if (nabr[i]) {
        lol[i - 1] += p;
        to_check.insert(-(i - 1));
      } else {
        ans += binpow(p, i);
        break;
      }
    }
  }
  for (long long i : to_check) {
    ans -= binpow(p, -i) * lol[-i];
    while (ans < 0) ans += MOD;
  }
  cout << ans << endl;
}
signed main() {
  fast_io();
  srand(time(NULL));
  cout << fixed << setprecision(12);
  long long q = 1;
  cin >> q;
  while (q--) solve();
}
