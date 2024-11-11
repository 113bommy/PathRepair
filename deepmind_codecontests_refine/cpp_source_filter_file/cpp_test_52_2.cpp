#include <bits/stdc++.h>
using namespace std;
void solve();
void solvet() {
  int t;
  cin >> t;
  for (long long __ = (0); __ < (t); __++) solve();
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(9);
  ;
  cout << setprecision(20);
  solvet();
  return 0;
}
void solve() {
  long long mod = 1e9 + 7;
  long long n, k;
  cin >> n >> k;
  long long ans = 0;
  long long len = log2(k);
  for (long long i = (0); i < (len + 10); i++) {
    if (k & (1 << i)) {
      long long p = 1;
      for (long long j = (0); j < (i); j++) {
        p *= n;
        p %= mod;
      }
      ans += p;
      ans %= mod;
    }
  }
  cout << ans << endl;
}
