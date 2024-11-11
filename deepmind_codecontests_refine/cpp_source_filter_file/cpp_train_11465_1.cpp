#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAX = 10000000000000;
const int N = 200005;
const int mod = 1e9 + 7;
void solve() {
  double d;
  cin >> d;
  double a, b;
  a = (d + sqrt(d * d - 4 * d)) / 2;
  b = (d - sqrt(d * d - 4 * d)) / 2;
  if (a >= 0 && b >= 0) {
    cout << fixed << setprecision(6) << "Y " << a << " " << b << endl;
  } else
    cout << "N\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
