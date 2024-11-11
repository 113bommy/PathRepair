#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  string s;
  cin >> s;
  int n = s.size(), ctr = 0;
  for (int i = 0; i <= n / 2; i++) {
    if (s[i] != s[n - i - 1]) {
      ctr++;
    }
  }
  if (ctr >= 2) {
    cout << "NO";
  } else if (ctr = 1) {
    cout << "YES";
  } else if (ctr == 0 && n % 2 == 0) {
    cout << "NO";
  } else {
    cout << "YES";
  }
}
