#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n >> s;
  if (n % 2) {
    cout << 1 << '\n' << s << endl;
  } else {
    int a, b;
    a = b = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        ++a;
      } else {
        ++b;
      }
    }
    if (a == b) {
      cout << 2 << endl;
      cout << s.substr(0, n - 1) << ' ' << s[n - 1] << endl;
    } else {
      cout << 1 << '\n' << s << endl;
    }
  }
}
