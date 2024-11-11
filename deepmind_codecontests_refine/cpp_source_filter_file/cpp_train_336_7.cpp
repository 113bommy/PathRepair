#include <bits/stdc++.h>
using namespace std;
long long qpow(long long _b, long long _e) {
  return _e == 0 ? 1
                 : (_e & 1 ? _b : 1) * qpow(_b * _b % 1000000009, _e >> 1) %
                       1000000009;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long ans = 1;
  for (long long i = 2; i <= n; ++i) {
    ans = ans * i % 1000000009;
  }
  cout << (ans + 1000000009 - qpow(2, n - 1)) % 1000000009 << endl;
  return 0;
}
