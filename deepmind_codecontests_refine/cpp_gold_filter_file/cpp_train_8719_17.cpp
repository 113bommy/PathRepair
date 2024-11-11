#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 0) {
    cout << 6 << endl;
    cout << "Power" << endl;
    cout << "Time" << endl;
    cout << "Space" << endl;
    cout << "Soul" << endl;
    cout << "Reality" << endl;
    cout << "Mind" << endl;
  } else {
    string a[7];
    a[1] = "0";
    a[2] = "0";
    a[3] = "0";
    a[4] = "0";
    a[5] = "0";
    a[6] = "0";
    for (int j = 1; j <= n; j++) {
      cin >> a[j];
    }
    cout << 6 - n << endl;
    int t = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] == "purple") {
        t = t + 1;
      }
    }
    if (t == 0) {
      cout << "Power" << endl;
    }
    t = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] == "green") {
        t = t + 1;
      }
    }
    if (t == 0) {
      cout << "Time" << endl;
    }
    t = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] == "blue") {
        t = t + 1;
      }
    }
    if (t == 0) {
      cout << "Space" << endl;
    }
    t = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] == "orange") {
        t = t + 1;
      }
    }
    if (t == 0) {
      cout << "Soul" << endl;
    }
    t = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] == "red") {
        t = t + 1;
      }
    }
    if (t == 0) {
      cout << "Reality" << endl;
    }
    t = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] == "yellow") {
        t = t + 1;
      }
    }
    if (t == 0) {
      cout << "Mind" << endl;
    }
  }
  return 0;
}
