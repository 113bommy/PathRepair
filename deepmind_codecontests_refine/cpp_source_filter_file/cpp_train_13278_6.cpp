#include <bits/stdc++.h>
using namespace std;
int main() {
  string str1 = "I hate it";
  string str2 = "I hate that";
  string str3 = "I love it";
  string str4 = "I love that";
  int n, i;
  cin >> n;
  if (n % 2 == 1) {
    for (i = 0; i < n / 2; ++i) {
      cout << str2 << " " << str4 << " ";
    }
    cout << str1 << endl;
  } else if (n % 2 == 0) {
    for (i = 0; i < n / 2 - 1; ++i) {
      cout << str2 << " " << str4 << " ";
    }
    cout << str2;
    cout << str3 << endl;
  }
  return 0;
}
