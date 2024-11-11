#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  long long p, k;
  cin >> n >> p >> k;
  map<long long, long long> mpp;
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    long long u;
    cin >> u;
    u %= p;
    long long u4 = (((u * u) % p * u) % p * u) % p;
    u4 = (u4 - (u * k) % p + p) % p;
    ans += mpp[u4];
    mpp[u4] += 1;
  }
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) solve();
}
