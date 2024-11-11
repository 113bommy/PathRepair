#include <bits/stdc++.h>
#pragma GCC optimize("O3", "Ofast", "unroll-loops", "fast-math")
using namespace std;
signed main() {
  long long i, j, n;
  cin >> n;
  for (i = 0; i < n; i++) {
    string s;
    long long cur;
    cin >> cur >> s;
    long long a = 0, b = 0;
    for (j = 0; j < cur; j++) {
      if (s[j] == '>') {
        break;
      } else {
        a++;
      }
    }
    for (j = cur - 1; j > 0; j--) {
      if (s[j] == '<') {
        break;
      } else {
        b++;
      }
    }
    cout << min(a, b) << '\n';
  }
  return 0;
}
