#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string str1, str;
  int rest = 366 % 7;
  while (cin >> n >> str1 >> str) {
    if (str[0] == 'w') {
      cout << 52 + (n >= 5 && n < 7 ? 1 : 0) << endl;
    } else {
      if (n <= 29) {
        cout << 12 << endl;
      } else if (n == 30) {
        cout << 11 << endl;
      } else if (n == 31) {
        cout << 7 << endl;
      }
    }
  }
}
