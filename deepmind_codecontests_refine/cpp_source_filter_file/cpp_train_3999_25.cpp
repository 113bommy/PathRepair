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
    for (int i = 2; i <= n; i++) {
      cin >> t;
      if (s[0] == t[0]) k++;
      s = t;
    }
    cout << k;
  }
}
