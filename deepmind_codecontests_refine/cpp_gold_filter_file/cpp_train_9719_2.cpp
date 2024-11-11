#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
void _print() { cout << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  cout << t;
  if (sizeof...(v)) cout << ", ";
  _print(v...);
}
const int mod = 1000000007;
void io_set() {}
void solve() {
  ll a, b, c;
  cin >> a >> b >> c;
  ll POS = a * b * c;
  POS = sqrt(POS);
  ll A = POS / a, B = POS / b, C = POS / c;
  cout << 4 * (A + B + C);
}
signed main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}
