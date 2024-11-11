#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  char z;
  bool d = true;
  string s = "#Black & White";
  for (int i = 0; i < a * b; i++) {
    cin >> z;
    if ((z == 'M' || z == 'C' || z == 'Y') && d) {
      s = "#Color";
      d = false;
    }
  }
  cout << s;
  return 0;
}
