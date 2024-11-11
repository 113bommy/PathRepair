#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, x, y;
  cin >> a >> x >> y;
  if (y % a == 0 || x < -a || x > a) {
    cout << -1 << endl;
    return 0;
  }
  int box = y / a;
  box++;
  int num = 2;
  bool d = 0;
  int curr_y = a;
  if (box == 1) {
    if ((float)(x) > -1 * (float)(a / 2.0) && float(x) < (float)(a / 2.0)) {
      cout << box << endl;
    } else {
      cout << -1 << endl;
    }
  } else {
    while (1) {
      if (d) {
        if (x >= -1 * a && x <= 0) {
          if ((x == 0 || x == -1 * a) && (y > curr_y && y < (curr_y + a))) {
            cout << -1 << endl;
            return 0;
          }
          if (y > curr_y && y < curr_y + a) {
            cout << num << endl;
            break;
          } else {
            num += 2;
            curr_y += a;
            d = 0;
          }
        } else {
          if (x == a && (y > curr_y && y < (curr_y + a))) {
            cout << -1 << endl;
            return 0;
          }
          if (y > curr_y && y < curr_y + a) {
            cout << num + 1 << endl;
            break;
          } else {
            num += 2;
            d = 0;
            curr_y += a;
          }
        }
      } else {
        if ((float)x >= -1 * (float)a / 2.0 && (float)x <= (float)a / 2.0) {
          if (y > curr_y && y < curr_y + a) {
            if ((float)x == -1 * (float)a / 2.0 || (float)x == (float)a / 2.0) {
              cout << -1 << endl;
              break;
            } else {
              cout << num << endl;
              break;
            }
          } else {
            num++;
            d = 1;
            curr_y += a;
          }
        } else {
          if (y > curr_y && y < curr_y + a) {
            cout << -1 << endl;
            break;
          } else {
            num++;
            d = 1;
            curr_y += a;
          }
        }
      }
    }
  }
}
