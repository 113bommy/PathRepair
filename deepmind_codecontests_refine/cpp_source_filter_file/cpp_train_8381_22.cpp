#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9, N = 3e5 + 1;
vector<int> cntt[26];
vector<int> cnt(101, 0);
void solve() {
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    int digit = int(s[i] + '0');
    if (digit % 4 == 0) ans++;
    if (i) {
      int prev = int(s[i - 1] - '0');
      if ((prev * 10 + digit) % 4 == 0) ans += i;
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(9);
  int t = 1;
  int tc = 0;
  while (t--) {
    tc++;
    solve();
  }
}
