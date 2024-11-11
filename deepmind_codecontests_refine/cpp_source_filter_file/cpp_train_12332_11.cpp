#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d, e, k, i;
  cin >> a >> b >> c >> d >> e;
  cin >> k;
  for (int i = 0; i < (k); i++) {
    string s;
    cin >> s;
    if (s[0] == 'X' && s[1] == 'X' && s[2] == 'L') {
      if (e >= 1) {
        e -= 1;
        cout << "XXL" << endl;
      } else if (d >= 1) {
        d -= 1;
        cout << "XL" << endl;
      } else if (c >= 1) {
        c -= 1;
        cout << "L" << endl;
      } else if (b >= 1) {
        b -= 1;
        cout << "M" << endl;
      } else if (a >= 1) {
        a -= 1;
        cout << "S" << endl;
      }
    }
    if (s[0] == 'X' && s[1] == 'L') {
      if (d >= 1) {
        d -= 1;
        cout << "XL" << endl;
      } else if (e >= 1) {
        e -= 1;
        cout << "XXL" << endl;
      } else if (c >= 1) {
        c -= 1;
        cout << "L" << endl;
      } else if (b >= 1) {
        b -= 1;
        cout << "M" << endl;
      } else if (a >= 1) {
        a -= 1;
        cout << "S" << endl;
      }
    }
    if (s[0] == 'L') {
      if (c >= 1) {
        c -= 1;
        cout << "L" << endl;
      } else if (d >= 1) {
        d -= 1;
        cout << "XL" << endl;
      } else if (b >= 1) {
        b -= 1;
        cout << "M" << endl;
      } else if (e >= 1) {
        e -= 1;
        cout << "XXL" << endl;
      } else if (a >= 1) {
        a -= 1;
        cout << "S" << endl;
      }
    }
    if (s[0] == 'M') {
      if (b >= 1) {
        b -= 1;
        cout << "M" << endl;
      } else if (c >= 1) {
        c -= 1;
        cout << "L" << endl;
      } else if (a >= 1) {
        a -= 1;
        cout << "S" << endl;
      } else if (d >= 1) {
        d -= 1;
        cout << "XL" << endl;
      } else if (e >= 1) {
        e -= 1;
        cout << "XXL" << endl;
      }
    }
    if (s[0] == 'S') {
      if (a >= 1) {
        a -= 1;
        cout << "S" << endl;
      } else if (b >= 1) {
        b -= 1;
        cout << "M" << endl;
      }
      if (c >= 1) {
        c -= 1;
        cout << "L" << endl;
      } else if (d >= 1) {
        d -= 1;
        cout << "XL" << endl;
      } else if (e >= 1) {
        e -= 1;
        cout << "XXL" << endl;
      }
    }
  }
  return 0;
}
