#include <bits/stdc++.h>
using namespace std;
const int N3 = 1e3 + 15;
const int N4 = 1e4 + 15;
const int N5 = 1e5 + 15;
const int N6 = 1e6 + 15;
const int N7 = 1e7 + 15;
const int N8 = 1e8 + 15;
const int N9 = 1e9 + 15;
long long a[110], ans, l, r, mx, b[110], n, m, s;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= m; ++i) {
    cin >> l >> r;
    ans = 0;
    for (int j = l; j <= r; ++j) ans += a[j];
    b[i] = ans;
  }
  sort(b + 1, b + m + 1);
  s = 0;
  for (int i = m; i >= 1; --i) {
    s += b[i];
    mx = max(mx, s);
  }
  cout << mx;
  return 0;
}
