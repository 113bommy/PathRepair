#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  char c = str[0];
  int d = str[1];
  if ((c == 'a' || c == 'h') && (d == 1 || d == 8)) {
    cout << 3 << endl;
  } else if ((c == 'a' || c == 'h') || (d == 1 || d == 8)) {
    cout << 5 << endl;
  } else {
    cout << 8 << endl;
  }
  return 0;
}
