#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAX = 100010;
int n, k, a[300];
int main() {
  cin >> n >> k;
  for (int i = 0, _n = (n); i < _n; ++i) {
    cin >> a[i];
  }
  int ans = INT_MIN;
  for (int L = 0, _n = (n); L < _n; ++L) {
    for (int R = L, _n = (n); R < _n; ++R) {
      int s = 0;
      vector<int> x, y;
      for (int i = 0, _n = (n); i < _n; ++i) {
        if (i <= R && i >= L) {
          x.push_back(a[i]);
          s += a[i];
        } else
          y.push_back(a[i]);
      }
      sort((x).begin(), (x).end());
      sort(y.rbegin(), y.rend());
      int cnt = 0;
      for (int i = 0, _n = (min((int)(x).size(), (int)(y).size())); i < _n;
           ++i) {
        if (cnt > k || y[i] < 0) break;
        s -= x[i];
        swap(y[i], x[i]);
        s += x[i];
        cnt++;
      }
      ans = max(ans, s);
    }
  }
  cout << ans << endl;
  return 0;
}
