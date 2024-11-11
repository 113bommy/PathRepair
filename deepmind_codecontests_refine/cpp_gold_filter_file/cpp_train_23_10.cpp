#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int n, k;
vector<int64_t> a;
vector<int64_t> b;
vector<int64_t> c;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int64_t _t;
    bool _a, _b;
    cin >> _t >> _a >> _b;
    if (_a && _b) {
      c.push_back(_t);
    } else {
      if (_a)
        a.push_back(_t);
      else if (_b)
        b.push_back(_t);
    }
  }
  a.push_back(0);
  b.push_back(0);
  c.push_back(0);
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  for (int i = 1; i < int(a.size()); i++) a[i] += a[i - 1];
  for (int i = 1; i < int(b.size()); i++) b[i] += b[i - 1];
  for (int i = 1; i < int(c.size()); i++) c[i] += c[i - 1];
  bool done = false;
  int64_t ans = 0;
  for (int i = 0; i <= k; i++) {
    if ((c.size() > i) && (min(a.size(), b.size()) > (k - i))) {
      if (!done)
        ans = c[i] + a[k - i] + b[k - i];
      else
        ans = min(ans, c[i] + a[k - i] + b[k - i]);
      done = true;
    }
  }
  if (!done)
    cout << -1 << '\n';
  else
    cout << ans << '\n';
  return 0;
}
