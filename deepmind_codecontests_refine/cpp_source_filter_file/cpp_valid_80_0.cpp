#include <bits/stdc++.h>
using namespace std;
const long long N = 2e6 + 5;
const long long M = 2e6 + 5;
long long n, m, t;
char s[20005];
signed main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s + 1;
    bool f = false;
    long long ind = -1;
    for (long long i = 1; i <= n; i++) {
      if (s[i] == '0') {
        f = true;
        ind = i;
        break;
      }
    }
    if (f) {
      if (ind > n / 2) {
        cout << 1 << " " << ind << " " << 1 << " " << ind - 1 << "\n";
        goto line;
      } else {
        cout << ind << " " << n << " " << ind + 1 << " " << n << "\n";
        goto line;
      }
    } else {
      cout << 1 << " " << 1 << " " << 2 << " " << 2 << "\n";
    }
  line:;
  }
}
