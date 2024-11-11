#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
int main() {
  int a, x, y;
  cin >> a >> x >> y;
  float yCor = y / (float)a;
  if (yCor == y / a) {
    cout << "-1" << endl;
  } else {
    int yy = (int)yCor;
    if (yy % 2 == 1) {
      if (x <= -a / 2.0f || x >= a / 2.0f) {
        cout << -1;
      } else {
        cout << (yy / 2) * 3 + 2;
      }
    } else {
      if (yy == 0) {
        if (x > -a / 2.0f && x < a / 2.0f) {
          cout << 1 << endl;
        } else {
          cout << -1 << endl;
        }
      } else {
        if (x <= -a || x >= a || x == 0) {
          cout << -1 << endl;
        } else {
          int stt = (yy / 2) * 3;
          if (x < 0)
            cout << stt;
          else
            cout << stt + 1;
        }
      }
    }
  }
  return 0;
}
