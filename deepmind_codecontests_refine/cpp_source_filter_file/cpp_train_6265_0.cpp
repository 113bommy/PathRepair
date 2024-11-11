#include <bits/stdc++.h>
using namespace std;
const long long int N = 2e5 + 5;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int tests;
  tests = 1;
  while (tests--) {
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    long long int c = 0;
    long long int ok = 0;
    for (long long int i = 0; i < n; i++) {
      if (s[i] == '(') ++c;
      if (s[i] == ')') --c;
      if (c < -1) {
        ok = 1;
        break;
      }
    }
    if (ok) {
      cout << "No" << endl;
      continue;
    }
    if (c > 0)
      cout << "No" << endl;
    else
      cout << "Yes" << endl;
  }
  return 0;
}
