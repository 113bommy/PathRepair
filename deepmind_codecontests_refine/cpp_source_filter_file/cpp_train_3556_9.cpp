#include <bits/stdc++.h>
using namespace std;
class AB {
 public:
  void ba() {
    int a, b, i, j;
    int c = 0;
    int k[50][50] = {0};
    char c1;
    cin >> a >> b;
    for (i = 1; i <= a; i++) {
      for (j = 1; j <= b; j++) {
        cin >> c1;
        if (c1 == 'W') {
          k[i][j] = 1;
        } else if (c1 == 'P') {
          k[i][j] = 2;
        } else if (c1 == '.') {
          k[i][j] = 3;
        }
      }
    }
    for (i = 1; i <= a; i++) {
      for (j = 1; j <= b; j++) {
        if (k[i][j] == 1) {
          if (k[i][j] == 1 && k[i - 1][j] == 2) {
            k[i - 1][j] = 4;
            k[i][j] = 5;
          } else if (k[i][j] == 1 && k[i + 1][j] == 2) {
            k[i + 1][j] = 4;
            k[i][j] = 5;
          } else if (k[i][j] == 1 && k[i][j + 1] == 2) {
            k[i][j + 1] = 4;
            k[i][j] = 5;
          } else if (k[i][j] == 1 && k[i][j - 1] == 2) {
            k[i][j + 1] = 4;
            k[i][j] = 5;
          }
        }
      }
    }
    for (i = 1; i <= a; i++) {
      for (j = 1; j <= b; j++) {
        if (k[i][j] == 5) {
          c = c + 1;
        }
      }
    }
    cout << "\n" << c;
  }
};
int main() {
  AB a2;
  a2.ba();
  return 0;
}
