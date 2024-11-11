#include <bits/stdc++.h>
using namespace std;
using namespace std;
const long long inf = 1e9 + 7;
const long long mod = 1e9 + 7;
using ll = long long;
void fast_stream() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
signed main() {
  ll t = 1;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    vector<ll> s(n);
    for (long long i = 0; i < n; i++) {
      cin >> s[i];
    }
    for (long long i = 0; i < n; i += 2) {
      ll yk = abs(s[i] * s[i + 1]);
      if (s[i] > 0 && s[i + 1] > 0) {
        cout << -s[i + 1] << " " << s[i] << " ";
      } else if (s[i] < 0 && s[i + 1] < 0) {
        cout << s[i + 1] << " " << -s[i] << " ";
      } else {
        cout << -s[i + 1] << " " << s[i] << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
