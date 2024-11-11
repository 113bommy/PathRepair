#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
const long long N = 1e6 + 7;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long ind = -1;
  for (long long i = 0; i < n - 1; i++) {
    if (s[i] > s[i + 1]) {
      ind = i;
      break;
    }
  }
  string ans;
  if (ind != -1) {
    for (long long i = 0; s[i]; i++) {
      if (ind != i) ans += s[i];
    }
  } else {
    for (long long i = 0; i < n - 1; i++) ans += s[i];
  }
  cout << ans;
  return 0;
}
