#include <bits/stdc++.h>
using namespace std;
int constexpr N = 2e5 + 5;
int n, m;
char s[20004];
void solve() {
  bool b = false;
  int ind;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    if (s[i] == '0') b = true, ind = i;
  }
  if (b) {
    if (ind + 1 <= n / 2)
      cout << ind + 1 << " " << n << " " << ind + 2 << " " << n << '\n';
    else
      cout << 1 << " " << ind + 1 << " " << 1 << " " << ind << '\n';
  } else {
    cout << 1 << " " << n / 2 << " " << (n + 3) / 2 << " " << n << '\n';
  }
  return;
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
