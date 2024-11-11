#include <bits/stdc++.h>
using namespace std;
int main() {
  int a = 0, b = 0;
  string str;
  cin >> str;
  for (int i = 0; i < str.size(); i++) {
    if (str[i + 1] == str[i] && b < 5) {
      b++;
    } else {
      a++;
      b = 1;
    }
  }
  cout << a << endl;
  return 0;
}
