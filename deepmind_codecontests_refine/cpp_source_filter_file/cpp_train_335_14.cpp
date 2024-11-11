#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
mt19937 rnd(1);
long long bit(long long mask, long long i) { return ((mask >> i) & 1); }
vector<long long> ans((long long)2e6 + 1);
void solve() {
  ans[2] = ans[1] = 0;
  long long a = 1, b = 0;
  long long ex = 0;
  long long add = 0;
  unordered_map<long long, long long> cnt;
  cnt.rehash((long long)2e6);
  cnt[2 * a + 5 * b + ex] = 0;
  for (long long i = 2; i <= (long long)2e6; ++i) {
    long long c = a;
    long long d = b;
    b += c;
    a -= c;
    a += 2 * d;
    ex += d;
    a %= MOD;
    b %= MOD;
    ex %= MOD;
    add = cnt[ex];
    cnt[(2 * a + 5 * b + ex) % MOD] = (b + add) % MOD;
    ans[i] = (4 * (b + add)) % MOD;
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  solve();
  for (long long num_test = 0; num_test < t; ++num_test) {
    long long n;
    cin >> n;
    cout << ans[n] << "\n";
  }
  return 0;
}
