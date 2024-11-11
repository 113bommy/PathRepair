#include <bits/stdc++.h>
using namespace std;
string base(int a, int b, int base) {
  int res = a * b;
  int temp = 0, c = 0;
  string y = "";
  while (res != 0) {
    int x = (int)res % base;
    res /= base;
    y += (x + 48);
  }
  reverse(y.begin(), y.end());
  return y;
}
int main() {
  int num;
  cin >> num;
  for (int i = 1; i < num; i++) {
    for (int j = 1; j < num; j++) {
      if (j == num - 1) {
        cout << base(i, j, num) << endl;
      } else
        cout << base(i, j, num) << " ";
    }
  }
  return 0;
}
