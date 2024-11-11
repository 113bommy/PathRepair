#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  string s;
  cin >> s;
  long long int a = 0, b = 0;
  for (long long int i = 0; i < n; i++) {
    a = 0, b = 0;
    for (long long int j = 0; j < n; j++) {
      if (s[j] == 'a')
        a++;
      else
        b++;
      if (a == b) {
        cout << i + 1 << " " << j + 1 << "\n";
        return;
      }
    }
  }
  cout << -1 << " " << -1 << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  ;
  ;
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
