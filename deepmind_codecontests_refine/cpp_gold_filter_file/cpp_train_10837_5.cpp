#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[102];
  int i, a, b, z, st;
  a = 5;
  b = 20;
  cin.getline(s, 101);
  for (i = 0; (s[i] != '\0'); i++) {
  }
  a = i / b;
  z = i % b;
  if (z != 0) {
    a++;
  }
  for (b = 1; ((b * a) < i); b++) {
  }
  z = (a * b) - i;
  cout << a << " " << b << "\n";
  st = 1;
  for (int j = 0; j < i; j++) {
    if (st == b) {
      if (z > 0) {
        cout << "*";
        z--;
        cout << "\n";
        cout << s[j];
        st = 1;
      } else {
        cout << s[j];
        cout << "\n";
        st = 0;
      }
    } else {
      cout << s[j];
    }
    st++;
  }
  return (0);
}
