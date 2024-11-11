#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
ostream& operator<<(ostream& out, const pair<T1, T2> p) {
  out << '(' << p.first << ',' << p.second << ')';
  return out;
}
template <class T1, class T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
  in >> p.first >> p.second;
  return in;
}
template <class T>
istream& operator>>(istream& in, vector<T>& v) {
  for (T& x : v) in >> x;
  return in;
}
template <class T>
ostream& operator<<(ostream& out, const vector<vector<T>>& v) {
  for (const vector<T>& x : v) out << x << '\n';
  return out;
}
template <class T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  for (const T& x : v) out << x << ' ';
  return out;
}
long long gcd(long long a, long long b) {
  if (b > a) swap(a, b);
  return (b ? gcd(b, a % b) : a);
}
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using tiii = pair<pair<int, int>, int>;
using vi = vector<int>;
using vl = vector<long long>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
const int h = 1000000007;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cerr.setstate(ios::failbit);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int c3 = 0;
    vi ans;
    while (n >= 0) {
      for (int z = 0; 5 * z <= n; z++)
        if ((n - z) % 7 == 0) ans = {c3, z, (n - z) / 7};
      c3++;
      n -= 3;
    }
    if (ans.empty())
      cout << "-1\n";
    else
      cout << ans << '\n';
  }
}
