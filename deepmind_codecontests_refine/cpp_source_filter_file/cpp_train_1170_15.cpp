#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " = " << a << endl;
  err(++it, args...);
}
const int mod = 1e9 + 7;
void solve() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  char ch;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int cnt1 = 0, cnt2 = 0, cnt = 0;
    for (int j = 0; j < m; j++) {
      cin >> ch;
      if (ch == '.') {
        if (cnt == 2) {
          cnt2++;
          cnt = 0;
        }
        cnt++;
      }
      if (ch == '*' || j == m - 1) {
        if (cnt == 1)
          cnt1++;
        else if (cnt == 2)
          cnt2++;
        cnt = 0;
      }
    }
    if (x <= y)
      ans += 1ll * x * cnt1 + 1ll * x * 2 * cnt2;
    else {
      ans += 1ll * x * cnt1 + 1ll * y * cnt2;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int tt;
  cin >> tt;
  while (tt--) solve();
}
