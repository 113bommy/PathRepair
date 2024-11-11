#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  int f = 0;
  if (str[0] != '1') {
    cout << "NO" << endl;
    return 0;
  }
  for (int i = 1; i < str.length(); ++i) {
    if (str[i] == '4') {
      ++f;
      if (f > 2) {
        cout << "NO" << endl;
        return 0;
      }
    } else if (str[i] == '1') {
      f = 0;
    } else {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
