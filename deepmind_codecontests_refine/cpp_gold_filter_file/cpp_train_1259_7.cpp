#include <bits/stdc++.h>
using namespace std;
long long qqq = 1;
long long n, m, cnt[300];
string second;
long double x;
void solve() {
  cin >> n >> second;
  bool first = 1;
  for (long long i = 0; i < n / 2; i++) {
    if (abs(second[i] - second[n - i - 1]) % 2 ||
        abs(second[i] - second[n - i - 1]) > 2)
      first = 0;
  }
  cout << (first ? "YES\n" : "NO\n");
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> qqq;
  while (qqq--) {
    solve();
  }
  return 0;
}
