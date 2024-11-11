#include <bits/stdc++.h>
using namespace std;
long long n, t;
int main() {
  string s;
  cin >> t;
  while (t--) {
    long long yes = 0;
    cin >> n >> s;
    for (long long j = 0; j < n; j++) {
      if (s[j] == '8') {
        if (n - j >= 11) {
          yes++;
        }
        break;
      }
    }
    if (yes > 0)
      cout << "YES\n";
    else
      cout << "NO\n";
    s.clear();
  }
  return 0;
}
