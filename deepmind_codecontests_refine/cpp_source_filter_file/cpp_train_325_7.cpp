#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const long long INF = 1e18 + 7;
void solve() {
  int n, x, y;
  cin >> n >> x >> y;
  string s;
  cin >> s;
  string res;
  for (int i = 0; i < x; i++) {
    if (i == y)
      res += '1';
    else
      res += '0';
  }
  int ans = 0;
  for (int i = n - 1; i >= n - x - 1; i--) {
    if (s[i] != res[n - 1 - i]) ans++;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  tt = 1;
  while (tt--) {
    solve();
    cout << '\n';
  }
}
