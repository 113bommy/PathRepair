#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void err(istringstream *iss) {}
template <typename T, typename... Args>
void err(istringstream *iss, const T &_val, const Args &...args) {
  string _name;
  *iss >> _name;
  if (_name.back() == ',') _name.pop_back();
  cerr << _name << " = " << _val << "; ", err(iss, args...);
}
void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n * k);
  for (auto &i : a) cin >> i;
  reverse(a.begin(), a.end());
  ll ans = 0;
  for (int i = 0; i < k; i++) {
    ans += a[n / 2 + ((n + 2) / 2) * i];
  }
  cout << ans << endl;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
