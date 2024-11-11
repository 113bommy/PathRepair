#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  int n;
  int list[201][201];
  cin >> t;
  while (t > 0) {
    t--;
    cin >> n;
    char qwe;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if ((i == 0 && j == 0) || (i == (n - 1) && j == (n - 1))) {
          cin >> qwe;
        } else {
          cin >> qwe;
          list[i][j] = (int)qwe;
        }
      }
    }
    int b = list[n - 2][n - 1];
    int c = list[n - 1][n - 2];
    int d = list[n - 3][n - 1];
    int e = list[n - 2][n - 2];
    int f = list[n - 1][n - 3];
    int num = 0;
    if (f == e && e == d) {
      if (c != e) {
        num++;
      }
      if (b != e) {
        num++;
      }
      cout << num << endl;
      if (c != e) {
        cout << n - 1 + 1 << " " << n - 2 + 1 << endl;
      }
      if (b != e) {
        cout << n - 2 + 1 << " " << n - 1 + 1 << endl;
      }
    } else if (e != f && e != d) {
      if (b == c) {
        if (b == e) {
          cout << 1 << endl << n - 2 + 1 << " " << n - 2 + 1 << endl;
        } else {
          cout << 2 << endl;
          cout << n - 1 + 1 << " " << n - 3 + 1 << endl;
          cout << n - 3 + 1 << " " << n - 1 + 1 << endl;
        }
      } else {
        cout << 2 << endl;
        cout << n - 2 + 1 << " " << n - 2 + 1 << endl;
        if (c == e) {
          cout << n - 2 + 1 << " " << n - 1 + 1 << endl;
        } else {
          cout << n - 1 + 1 << " " << n - 2 + 1 << endl;
        }
      }
    } else {
      if (b == c && b == e) {
        cout << 2 << endl;
        cout << n - 2 + 1 << " " << n - 2 + 1 << endl;
        if (f == e) {
          cout << n - 1 + 1 << " " << n - 3 + 1 << endl;
        } else {
          cout << n - 3 + 1 << " " << n - 1 + 1 << endl;
        }
      } else {
        if (b == c) {
          cout << 1 << endl;
        } else {
          cout << 2 << endl;
        }
        if (f == e) {
          cout << n - 3 + 1 << " " << n - 1 + 1 << endl;
        } else {
          cout << n - 1 + 1 << " " << n - 3 + 1 << endl;
        }
        if (b == c) {
        } else {
          if (e == b) {
            cout << n - 2 + 1 << " " << n - 1 + 1 << endl;
          } else {
            cout << n - 1 + 1 << " " << n - 2 + 1 << endl;
          }
        }
      }
    }
  }
}
