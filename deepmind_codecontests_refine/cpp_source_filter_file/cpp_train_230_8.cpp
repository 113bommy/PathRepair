#include <bits/stdc++.h>
using namespace std;
long long mo(const long long input, const long long ceil) {
  return input >= ceil ? input % ceil : input;
}
void solve(int tt) {
  long long n;
  cin >> n;
  long double pi = 3.141592653589793238;
  n *= 2;
  long double ans = 0.0;
  ans = cos(pi / 2 * n) / sin(pi / n);
  cout << fixed << setprecision(12) << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int tt = 1;
  cin >> tt;
  for (int i = 0; i < tt; i++) solve(tt);
  cerr << "\n\n\nTime : "
       << 1000 * (long double)clock() / (long double)CLOCKS_PER_SEC << "ms\n";
  ;
  return 0;
}
