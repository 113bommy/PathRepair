#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n / 2; i++) {
    if (s[i] == '0') {
      cout << i + 1 << ' ' << n << ' ' << i + 2 << ' ' << n << endl;
      return;
    }
  }
  for (int i = n / 2; i < n; i++) {
    if (s[i] == '0') {
      cout << 1 << ' ' << i + 1 << ' ' << 1 << ' ' << i << endl;
      return;
    }
  }
  cout << 2 << ' ' << n << ' ' << 1 << ' ' << n - 1 << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t_;
  cin >> t_;
  while (t_--) solve();
  return 0;
}
