#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  int l = str.length();
  string str2;
  cin >> str2;
  int l2 = str2.length();
  if (l > l2)
    cout << l;
  else if (l2 > l)
    cout << l2;
  else {
    for (int i = 0; i < str.length(); i++) {
      if (str[i] != str2[i]) {
        cout << l;
        return 0;
      }
    }
  }
  cout << -1;
}
