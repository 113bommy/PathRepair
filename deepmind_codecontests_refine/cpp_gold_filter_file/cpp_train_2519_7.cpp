#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  long long a, b, c, s;
  cin >> T;
  while (T--) {
    cin >> a >> b >> c >> s;
    if (s - a * c < 0) {
      s %= c;
      if (b >= s) {
        cout << "YES\n";
      } else
        cout << "NO\n";
    } else if (s - a * c == 0) {
      cout << "YES\n";
    } else {
      s -= a * c;
      if (b >= s) {
        cout << "YES\n";
      } else
        cout << "NO\n";
    }
  }
  return 0;
}
