#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, j, i;
  string str, str1, str2;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> str;
    if (str.length() % 2 == 0) {
      j = str.length() / 2;
      str1 = str.substr(0, j);
      str2 = str.substr(j, j);
      if (str1 == str2) {
        cout << "YES" << endl;
      } else
        cout << "NO" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
