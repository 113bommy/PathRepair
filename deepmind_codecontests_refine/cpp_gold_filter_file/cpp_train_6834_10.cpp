#include <bits/stdc++.h>
using namespace std;
const long long mod = pow(10, 9) + 7;
const long long N = 3e5, M = N;
const long long inf = LLONG_MAX;
const long long infn = LLONG_MIN;
void iluzn() {
  long long n;
  cin >> n;
  long long i;
  if (n >= 37)
    cout << -1;
  else {
    for (i = 0; i < n / 2; i++) cout << 8;
    if (n & 1) cout << 6;
  }
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t = 1;
  while (t--) iluzn();
  return 0;
}
