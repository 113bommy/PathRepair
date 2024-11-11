#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k = 0;
  cin >> n;
  string s, t;
  cin >> s;
  if (n == 1) {
    cout << 1;
  } else {
    for (int i = 1; i < n; i++) {
      cin >> t;
      if (t[0] == s[1]) k++;
      s = t;
    }
    cout << k + 1;
  }
}
