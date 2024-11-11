#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, l, n, m, a, b, c, d, e;
  char s[5];
  while (cin >> a >> b >> c >> d >> e) {
    cin >> n;
    for (a = 0; a < n; a++) {
      cin >> s;
      if (strcmp(s, "S") == 0) {
        if (a > 0) {
          a--;
          cout << "S" << endl;
        } else if (a == 0 && b > 0) {
          b--;
          cout << "M" << endl;
        } else if (a == 0 && c > 0) {
          c--;
          cout << "L" << endl;
        } else if (a == 0 && d > 0) {
          d--;
          cout << "XL" << endl;
        } else if (a == 0 && e > 0) {
          e--;
          cout << "XXL" << endl;
        }
      }
      if (strcmp(s, "M") == 0) {
        if (b > 0) {
          b--;
          cout << "M" << endl;
        } else if (b == 0 && c > 0) {
          c--;
          cout << "L" << endl;
        } else if (b == 0 && a > 0) {
          a--;
          cout << "S" << endl;
        } else if (b == 0 && d > 0) {
          d--;
          cout << "XL" << endl;
        } else if (b == 0 && e > 0) {
          e--;
          cout << "XXL" << endl;
        }
      }
      if (strcmp(s, "L") == 0) {
        if (c > 0) {
          c--;
          cout << "L" << endl;
        } else if (c == 0 && d > 0) {
          d--;
          cout << "XL" << endl;
        } else if (c == 0 && b > 0) {
          b--;
          cout << "M" << endl;
        } else if (c == 0 && e > 0) {
          e--;
          cout << "XXL" << endl;
        } else if (c == 0 && a > 0) {
          a--;
          cout << "S" << endl;
        }
      }
      if (strcmp(s, "XL") == 0) {
        if (d > 0) {
          d--;
          cout << "XL" << endl;
        } else if (d == 0 && e > 0) {
          e--;
          cout << "XXL" << endl;
        } else if (d == 0 && c > 0) {
          c--;
          cout << "L" << endl;
        } else if (d == 0 && b > 0) {
          b--;
          cout << "M" << endl;
        } else if (d == 0 && a > 0) {
          a--;
          cout << "S" << endl;
        }
      }
      if (strcmp(s, "XXL") == 0) {
        if (e > 0) {
          e--;
          cout << "XXL" << endl;
        } else if (e == 0 && d > 0) {
          d--;
          cout << "XL" << endl;
        } else if (e == 0 && c > 0) {
          c--;
          cout << "L" << endl;
        } else if (e == 0 && b > 0) {
          b--;
          cout << "M" << endl;
        } else if (e == 0 && a > 0) {
          a--;
          cout << "S" << endl;
        }
      }
    }
  }
  return 0;
}
