#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    set<ll> s;
    ll a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      s.insert(a[i]);
    }
    ll k = s.size();
    sort(a, a + n);
    ll mm = 1;
    ll cnt = 1;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] == a[i + 1]) {
        cnt++;
      } else {
        cnt = 1;
      }
      mm = max(mm, cnt);
    }
    auto it = s.end();
    it--;
    ll p = *it;
    if (k == mm) {
      cout << mm - 1 << endl;
    } else {
      if (k > mm) {
        cout << mm << endl;
      } else {
        cout << k << endl;
      }
    }
  }
}
