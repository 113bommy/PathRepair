#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  if (n <= 3) {
    cout << s << endl;
    return 0;
  }
  if (n % 2) {
    cout << s[0] << s[1] << s[2] << "-";
    for (int i = 3; i < n; i++) {
      cout << s[i];
      if (!(i & 1) && i != n - 1) {
        cout << "-";
      }
    }
  } else {
    for (int i = 0; i < n; i++) {
      cout << s[i];
      if ((i & 1) && i != n - 1) {
        cout << "-";
      }
    }
  }
}
