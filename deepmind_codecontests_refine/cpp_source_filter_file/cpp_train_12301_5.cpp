#include <bits/stdc++.h>
using namespace std;
signed main() {
  string s;
  cin >> s;
  long long n = s.size();
  long long an = 0;
  for (long long i = 0; i < n; i++) {
    long long r = INT_MAX;
    for (long long j = i; j <= min((long long)(i + 9), n - 1); j++) {
      for (long long k = 1; k <= 3; k++) {
        if (j + 2 * k < n) {
          if (s[j] == s[j + k] and s[j] == s[j + 2 * k]) {
            r = min(r, j + 2 * k);
          }
        }
      }
    }
    if (r != INT_MAX) an = an + n - r;
  }
  cout << an << endl;
}
