#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string str;
    cin >> str;
    int i, x = 0, y = 0;
    while (i < str.size() && str[i] == '0') {
      i++;
      x++;
    }
    i = str.size() - 1;
    while (i >= 0 && str[i] == '1') {
      i--;
      y++;
    }
    if (x + y == str.size())
      cout << str;
    else {
      for (i = 0; i <= x; i++) cout << 0;
      for (i = 0; i < y; i++) cout << 1;
    }
    cout << endl;
  }
}
