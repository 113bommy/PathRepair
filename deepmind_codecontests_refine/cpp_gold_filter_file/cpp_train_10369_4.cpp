#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  while (t--) {
    long long int x, y, l, r;
    cin >> x >> y >> l >> r;
    int a = 0, b = 0;
    while (!(powl(x, a) >= (long double)r / (long double)x)) {
      a++;
    }
    while (!(powl(y, b) >= (long double)r / (long double)y)) {
      b++;
    }
    if (powl(x, a - 1) >= (long double)(1e18) / x) {
      a--;
    }
    if (powl(y, b - 1) >= (long double)(1e18) / y) {
      b--;
    }
    vector<long long int> v;
    for (int i = 0; i <= a; i++) {
      for (int j = 0; j <= b; j++) {
        if (powl(x, i) > (long long int)5e17 &&
            powl(y, j) > (long long int)5e17)
          continue;
        if (powl(x, i) + powl(y, j) >= l && powl(x, i) + powl(y, j) <= r) {
          v.push_back(powl(x, i) + powl(y, j));
        }
      }
    }
    if (v.size() == 0) {
      cout << r - l + 1 << endl;
      return 0;
    }
    sort(v.begin(), v.end());
    long long int ans = 0;
    ans = max(ans, v[0] - l);
    for (int i = 1; i < v.size(); i++) {
      ans = max(ans, v[i] - v[i - 1] - 1);
    }
    ans = max(ans, r - v[v.size() - 1]);
    cout << ans;
  }
}
