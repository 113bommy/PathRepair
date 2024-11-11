#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using pairll = pair<ll, ll>;
int main() {
  ll t, x, c, sum = 0, y, k;
  string s;
  cin >> t;
  while (t--) {
    cin >> x;
    vector<char> a;
    cin >> s;
    k = 1;
    for (ll i = 0; i < s.length(); i++) {
      a.push_back(s[i]);
    }
    sum = s.length();
    while (a.size() < x) {
      if (a[k - 1] == '2') {
        y = a.size();
        for (ll i = k; i < y; i++) {
          a.push_back(a[i]);
        }
        sum = a.size();
      }
      if (a[k - 1] == '3') {
        y = a.size();
        for (ll i = k; i < y; i++) {
          a.push_back(a[i]);
        }
        for (ll i = k; i < y; i++) {
          a.push_back(a[i]);
        }
        sum = a.size();
      }
      k++;
    }
    sum = a.size();
    for (ll i = k; i <= x; i++) {
      if (a[i - 1] == '2') {
        sum = (sum + (sum - i)) % 1000000007;
      }
      if (a[i - 1] == '3') {
        sum = (sum + 2 * (sum - i)) % 1000000007;
      }
    }
    if (sum < 0) {
      sum = 1000000007 - sum;
    }
    cout << sum << endl;
  }
}
