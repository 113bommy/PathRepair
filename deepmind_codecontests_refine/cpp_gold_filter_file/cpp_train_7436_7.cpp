#include <bits/stdc++.h>
using namespace std;
long long int a, b, c, d, i, j, k;
string x = "RIGHT", y = "LEFT", z = "PRINT", s;
int main() {
  while (cin >> a >> b) {
    cin >> s;
    if (b == 1) {
      while (b <= a) {
        cout << z << " " << s[b - 1] << endl;
        if (b != a) cout << x << endl;
        b++;
      }
    } else if (b == a) {
      while (b >= 1) {
        cout << z << " " << s[b - 1] << endl;
        if (b != 1) cout << y << endl;
        b--;
      }
    } else {
      if (b <= a / 2) {
        while (b != 1) {
          cout << y << "\n";
          b--;
        }
        while (b <= a) {
          cout << z << " " << s[b - 1] << endl;
          if (b != a) cout << x << endl;
          b++;
        }
      } else {
        while (b != a) {
          cout << x << endl;
          b++;
        }
        while (b >= 1) {
          cout << z << " " << s[b - 1] << endl;
          if (b != 1) cout << y << endl;
          b--;
        }
      }
    }
  }
  return 0;
}
