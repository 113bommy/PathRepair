#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ld = long double;
using pld = pair<ld, ld>;
template <class F, class S>
istream &operator>>(istream &in, pair<F, S> &a) {
  in >> a.first >> a.second;
  return in;
}
template <class F, class S>
ostream &operator<<(ostream &out, pair<F, S> a) {
  out << a.first << " " << a.second;
  return out;
}
template <class T>
istream &operator>>(istream &in, vector<T> &a) {
  for (auto &i : a) in >> i;
  return in;
}
template <class T>
ostream &operator<<(ostream &out, vector<T> a) {
  for (auto &i : a) out << i << " ";
  return out;
}
inline void Start() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
mt19937_64 rnd((ull)chrono::steady_clock::now().time_since_epoch().count());
signed main() {
  Start();
  ll n, k;
  cin >> n >> k;
  ll l = 1, r = n;
  while (true) {
    if (r - l + 1 > 5 * k) {
      ll m = l + r >> 1;
      cout << l << " " << m << endl;
      string s;
      cin >> s;
      if (s == "Bad") {
        return 0;
      }
      if (s == "Yes") {
        if (l == m) return 0;
        r = m;
      } else {
        l = m + 1;
      }
      l = max(1ll, l - k), r = min(n, r + k);
    } else {
      ll m = rnd() % (r - l + 1) + l;
      cout << m << " " << m << endl;
      string s;
      cin >> s;
      if (s == "Bad") {
        return 0;
      }
      if (s == "Yes") {
        return 0;
      } else {
        l = max(1ll, l - k), r = min(n, r + k);
      }
    }
  }
  return 0;
}
