#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n > 2) {
      cout << "YES" << '\n';
      cout << 2 << '\n';
      cout << s.substr(0, 1) << " " << s.substr(1, n - 1) << '\n';
    } else {
      if (s[0] > s[1]) {
        cout << "YES" << '\n' << 2 << '\n' << s[0] << " " << s[1];
      } else {
        cout << "NO" << '\n';
      }
    }
  }
}
