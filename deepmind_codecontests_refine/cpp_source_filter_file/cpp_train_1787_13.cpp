#include <bits/stdc++.h>
using namespace std;
signed main() {
  string s;
  cin >> s;
  long long n = s.length();
  long long ans = 0;
  long long right = 2 * n;
  for (long long i = n - 1; i >= 0; i--) {
    for (long long j = i + 2; j < n && j <= right; j++) {
      if (s[i] == s[j] && s[i] == s[(i + j) / 2]) {
        right = min(right, j);
        break;
      }
    }
    ans += max(n - right, 0LL);
  }
  cout << ans << endl;
}
