#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
int main() {
  int l = 0;
  while (1) {
    int a = getc(stdin);
    if (a == '\n') break;
    a = getc(stdin);
    int end = 0;
    int sign;
    if (a == '/') {
      end = 1;
      sign = getc(stdin);
    } else {
      sign = a;
    }
    a = getc(stdin);
    if (!end) {
      for (int i = (0); i < (2 * l); i++) {
        cout << " ";
      }
      cout << "<" << char(sign) << ">" << endl;
      l++;
    } else {
      l--;
      for (int i = (0); i < (2 * l); i++) {
        cout << " ";
      }
      cout << "</" << char(sign) << ">" << endl;
    }
  }
  return 0;
}
