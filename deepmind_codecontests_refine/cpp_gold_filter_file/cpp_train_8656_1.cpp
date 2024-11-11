#include <bits/stdc++.h>
using namespace std;
int main() {
  int long long q;
  cin >> q;
  while (q--) {
    int long long n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    if (n < 11) {
      cout << "NO" << endl;
    } else if (n == 11 && s[0] != '8') {
      cout << "NO" << endl;
    } else if (n == 11 && s[0] == '8') {
      cout << "YES" << endl;
    } else {
      for (int i = 0; i <= n - 11; i++) {
        if (s[i] == '8') {
          ans = 1;
          break;
        }
      }
      if (ans == 1) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}
