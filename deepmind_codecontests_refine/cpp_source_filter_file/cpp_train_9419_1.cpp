#include <bits/stdc++.h>
using namespace std;
int main() {
  string num1, num2, num3;
  int i, j, k, l, m, n, last, flag = 0;
  cin >> num1;
  num2 = num1;
  num3 = num1;
  l = num1.length();
  last = num1.at(l - 1) - 48;
  for (i = 0; i < l - 1; i++) {
    m = num2.at(i);
    if (last % 2 == 0 && m < last) {
      swap(num2.at(i), num2.at(l - 1));
      flag = 1;
      cout << num2 << endl;
      return 0;
    }
  }
  if (flag == 0) {
    for (i = l - 2; i >= 0; i--) {
      m = num3.at(i);
      if (m % 2 == 0 && last < m) {
        swap(num3.at(i), num3.at(l - 1));
        cout << num3 << endl;
        return 0;
      }
    }
  }
  cout << "-1" << endl;
}
