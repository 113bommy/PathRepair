#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int l, i, y;
    cin >> l;
    char s[100];
    cin >> s;
    for (i = 0; i < l; i++) {
      if (s[i] == '8') {
        break;
      }
    }
    if (l - i < 11)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
