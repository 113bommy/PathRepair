#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int main() {
  long long t;
  string s;
  cin >> t;
  while (t--) {
    cin >> s;
    long long bal = 0;
    long long ans = 0;
    long long n = s.length();
    for (long long i = 0; i < n; i++) {
      if (s[i] == '-')
        bal--;
      else
        bal++;
      if ((bal < 0 && i < n - 1) || (bal >= 0 && i == n - 1)) {
        ans = ans + i + 1;
        bal = 0;
      }
      if (bal < 0 && i == n - 1) {
        ans = ans + i + 1 + i + 1;
      }
    }
    cout << ans << "\n";
  }
}
