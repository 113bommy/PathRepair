#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, x = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
      if (s[i] == '8') {
        x = i + 1;
        break;
      }
    }
    if (x == 0) {
      cout << "NO" << endl;
    } else {
      if (n - x >= 10) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}
