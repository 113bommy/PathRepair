#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, a, b;
  bool flag = true;
  cin >> n;
  if (n % 7 == 0) {
    for (i = 1; i <= n / 7; i++) cout << 7;
    cout << "\n";
  } else {
    a = n % 7;
    b = n / 7;
    switch (a) {
      case 1:
        if (b > 0) {
          for (i = 1; i <= 2; i++) cout << 4;
          for (i = 1; i < b; i++) cout << 7;
          cout << "\n";
        } else
          flag = false;
        break;
      case 2:
        if (b > 1) {
          for (i = 1; i <= 4; i++) cout << 4;
          for (i = 1; i <= b - 2; i++) cout << 7;
          cout << "\n";
        } else
          flag = false;
        break;
      case 3:
        if (b > 2) {
          for (i = 1; i <= 6; i++) cout << 4;
          for (i = 1; i <= b - 3; i++) cout << 7;
          cout << "\n";
        } else
          flag = false;
        break;
      case 4: {
        cout << 4;
        for (i = 1; i <= b; i++) cout << 7;
        cout << "\n";
      } break;
      case 5:
        if (b > 0) {
          for (i = 1; i <= 3; i++) cout << 4;
          for (i = 1; i < b; i++) cout << 7;
          cout << "\n";
        } else
          flag = false;
        break;
      case 6:
        if (b > 5) {
          for (i = 1; i <= 12; i++) cout << 4;
          for (i = 1; i <= b - 6; i++) cout << 7;
          cout << "\n";
        } else
          flag = false;
        break;
    }
  }
  if (!flag)
    if (n % 4 == 0) {
      for (i = 1; i <= n / 4; i++) cout << 4;
      cout << "\n";
    } else
      cout << -1 << endl;
  return 0;
}
