#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a, b, i;
    char x;
    cin >> n >> a >> b;
    string s = "";
    for (i = 0; i < b; i++) {
      x = 97 + i;
      s = s + x;
    }
    i--;
    while (s.length() != a) {
      x = 97 + i;
      s = s + x;
    }
    while (s.length() <= n) {
      s = s + s;
    }
    for (i = 0; i < n; i++) {
      cout << s[i];
    }
    cout << endl;
  }
}
