#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
const long double pi = acosl(-1);
const int mod = 998244353;
const int mod1 = 1e9 + 7;
mt19937_64 rnd(time(0));
void faster() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
}
void solve() {
  int n;
  cin >> n;
  if (n % 4 != 0)
    cout << "NO\n";
  else
    cout << "YES\n";
}
signed main() {
  faster();
  double start = clock();
  int t;
  cin >> t;
  while (t--) solve();
  cerr << "Time " << (clock() - start) * 1.0 / CLOCKS_PER_SEC << "s\n";
  return 0;
}
