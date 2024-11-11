#include <bits/stdc++.h>
using namespace std;
const int64_t N = 1e6 + 6, M = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int64_t n, m = 0, ans = -1;
    cin >> n;
    vector<int64_t> a(n);
    for (int64_t &e : a) cin >> e, m = max(m, e);
    for (int64_t i = 0; i < n; i++)
      if ((i + 1 < n && a[i] == m && a[i + 1] == m) ||
          (i && a[i] == m && a[i - 1] == m))
        ans = i + 1;
    cout << ans << '\n';
  }
}
