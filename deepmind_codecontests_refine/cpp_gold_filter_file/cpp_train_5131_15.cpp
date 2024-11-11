#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    ll a, b, c, d, ans;
    cin >> a >> b >> c >> d;
    if (a > b * c) {
      ans = -1;
    } else {
      ll k = a / (b * d);
      ans = a * (k + 1) - b * d * (k * (k + 1)) / 2;
    }
    cout << ans << endl;
  }
  return 0;
}
