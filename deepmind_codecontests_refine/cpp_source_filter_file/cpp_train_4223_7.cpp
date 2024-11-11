#include <bits/stdc++.h>
using namespace std;
void my_dbg() { cout << endl; }
template <typename Arg, typename... Args>
void my_dbg(Arg A, Args... B) {
  cout << ' ' << A;
  my_dbg(B...);
}
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
const int inf = INT_MAX;
const int ninf = INT_MIN;
const int mod = 1e9 + 7;
const int N = 2e5 + 2;
void solve() {
  ll d, k, a, b, t;
  cin >> d >> k >> a >> b >> t;
  if (d <= a) {
    cout << b * d;
  } else if (t + a * k > b * k) {
    cout << a * k + (d - k) * b;
  } else {
    ll cnt = d / k;
    cout << (cnt - 1) * t + cnt * k * a + min(t + a * (d % k), b * (d % k));
  }
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
