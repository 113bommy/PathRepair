#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:66777216")
using namespace std;
const double eps = 1e-7;
const double pi = acos(-1.0);
const long long INF = (long long)2e9 + 1;
const long long LINF = (long long)8e18;
const long long inf = (long long)2e9 + 1;
const long long linf = (long long)8e18;
const long long MM = (long long)1e9 + 7;
int solve();
void gen();
int main() {
  solve();
  return 0;
}
const int dd = 2e5 + 7;
int solve() {
  long long gg;
  cin >> gg;
  while (gg--) {
    long long t;
    cin >> t;
    long long ans = t * (t + 1) / 2;
    long long cur = 1;
    while (cur < t) ans -= 2 * cur, cur *= 2;
    cout << ans << "\n";
  }
  return 0;
}
