#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int MAXN = 2e5 + 10;
void solve() {
  string a;
  cin >> a;
  int res = 1, ans = 1;
  for (auto& c : a) {
    if (c == '0') {
      cout << "1 " << res << endl;
      if (res == 4)
        res = 0;
      else
        res++;
    } else {
      cout << "3 " << ans << endl;
      if (ans == 3)
        ans = 1;
      else
        ans += 2;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
