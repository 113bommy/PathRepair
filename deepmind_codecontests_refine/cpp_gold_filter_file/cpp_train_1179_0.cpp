#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void D() {
  ll a, b;
  cin >> a >> b;
  string s, t;
  s = to_string(a);
  t = to_string(b);
  if (s.length() < t.length()) {
    ll diff = t.length() - s.length();
    while (diff--) {
      s = "0" + s;
    }
  } else if (s.length() > t.length()) {
    ll diff = s.length() - t.length();
    while (diff--) {
      t = t + "0";
    }
  }
  reverse(t.begin(), t.end());
  ll carry = 0;
  string ans;
  ll val;
  for (int i = t.length() - 1; i >= 0; i--) {
    val = t[i] - '0' + s[i] - '0';
    val += carry;
    ans.push_back((val % 10) + '0');
    carry = val / 10;
  }
  if (carry) ans.push_back(carry + '0');
  reverse(ans.begin(), ans.end());
  ll res = atoi(ans.c_str());
  cout << res << "\n";
  ;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(0);
  cout << fixed;
  ll n, m, k, pt(0), ct(0), x, y;
  ll t = 1;
  while (t--) {
    D();
  }
}
