#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vc = vector<char>;
using vd = vector<double>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int a[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int b[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
inline ll power(ll x, ll y) {
  ll temp;
  if (y == 0) return 1;
  temp = power(x, y / 2);
  if (y % 2 == 0)
    return (temp * temp);
  else
    return (x * temp * temp);
}
bool sortbysec(pll &a, pll &b) { return (a.second < b.second); }
signed main() {
  string s;
  cin >> s;
  ll n = s.size();
  if (n < 26) {
    cout << "-1"
         << "\n";
  } else {
    ll p = 97;
    for (ll i = 0; i < n; i++) {
      ll x = ll(s[i]);
      if (p == 123) {
        break;
      }
      if (x == p) {
        p++;
      } else if (x == (p - 1)) {
        s[i] = char(p);
        p++;
      }
    }
    if (p == 123) {
      cout << s << "\n";
    } else {
      cout << "-1"
           << "\n";
    }
  }
}
