#include <bits/stdc++.h>
using namespace std;
int n;
string str;
int main() {
  cin >> n;
  while (n) {
    if (n % 7 == 0) {
      n -= 7;
      str += '7';
    } else if (n % 4 == 0) {
      n -= 4;
      str += '4';
    } else {
      n -= 7;
      str += '7';
    }
    if (n < 4 && n != 0) {
      cout << -1 << endl;
      return 0;
    }
  }
  sort(str.begin(), str.end());
  cout << str << endl;
  return 0;
}
