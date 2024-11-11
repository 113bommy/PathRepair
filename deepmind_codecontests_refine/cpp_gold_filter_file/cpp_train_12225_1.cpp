#include <bits/stdc++.h>
using namespace std;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
string tostring(int x) {
  ostringstream o;
  o << x;
  return o.str();
}
int toint(string s) {
  istringstream st(s);
  int i;
  st >> i;
  return i;
}
const double pi = acos(-1.0);
char a[1000055];
char b[1000055];
int main() {
  int p, x, i, j, c, temp;
  bool flag;
  scanf("%d", &p);
  scanf("%d", &x);
  for (i = 0; i < 1000004; i++) {
    b[i] = '9';
  }
  b[i] = '\0';
  if (p == 1) {
    if (x == 1) {
      cout << "1\n";
    } else {
      cout << "Impossible\n";
    }
  } else {
    flag = 0;
    for (i = 1; i <= 9; i++) {
      if ((i * x) % 10 == 0) continue;
      j = 0;
      c = 0;
      a[0] = (char)(i + 48);
      while (1) {
        temp = (a[j] - '0') * x + c;
        j++;
        a[j] = (char)(temp % 10 + '0');
        c = temp / 10;
        if (j == p - 1) {
          if ((a[j] - '0') * x + c == a[0] - '0' && a[j] != '0') {
            c = 0;
          } else
            c = 10;
          break;
        }
      }
      if (j == p - 1 && c == 0) {
        reverse(a, a + p);
        a[j + 1] = '\0';
        if (strcmp(a, b) < 0) {
          strcpy(b, a);
        }
        flag = 1;
      }
    }
    if (flag) {
      cout << b << endl;
    } else
      cout << "Impossible\n";
  }
  return 0;
}
