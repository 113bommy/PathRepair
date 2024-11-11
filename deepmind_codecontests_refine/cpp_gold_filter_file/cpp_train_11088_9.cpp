#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 15;
const long long int inf = 1e18;
void solve() {
  long long int n;
  cin >> n;
  string s;
  long long int ans = 1;
  cin >> s;
  for (long long int i = 1; i < n; i++) ans += (s[i] != s[i - 1]);
  cout << min(n, ans + 2);
}
void debug(long long int tt) {}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}
