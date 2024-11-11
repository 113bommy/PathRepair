#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int x, y, i = 0;
  cin >> x >> y;
  while (1) {
    if (i % 2 == 0) {
      if (y >= 2) {
        if (x >= 2) {
          x -= 2;
          y -= 2;
        } else {
          if (x * 100 + y * 10 >= 220) {
            if (x > 0 && y >= 12) {
              x -= 1;
              y -= 12;
            } else {
              if (y >= 22) {
                y -= 22;
              } else {
                cout << "Hanako";
                return 0;
              }
            }
          } else {
            cout << "Hanako";
            return 0;
          }
        }
      } else {
        cout << "Hanako";
        return 0;
      }
    } else {
      if (y >= 22) {
        y -= 22;
      } else {
        if (y * 10 + x * 100 >= 220) {
          if (y >= 12 && x >= 1) {
            y -= 12;
            x -= 2;
          } else {
            if (y >= 2 && x >= 2) {
              y -= 2;
              x -= 2;
            } else {
              cout << "Ciel";
              return 0;
            }
          }
        } else {
          cout << "Ciel";
          return 0;
        }
      }
    }
    i++;
  }
  return 0;
}
