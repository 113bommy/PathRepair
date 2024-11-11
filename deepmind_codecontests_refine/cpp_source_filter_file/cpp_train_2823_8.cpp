#include <bits/stdc++.h>
using namespace std;
int main() {
  char t;
  string a, b;
  cin >> t;
  cin >> a >> b;
  if (a == b) {
    cout << "NO";
  } else if (a[1] == t && b[1] != t) {
    cout << "YES";
  } else if (a[1] == b[1]) {
    if (a[0] < 65 && b[0] < 65) {
      if (a[0] > b[0]) {
        cout << "YES";
      } else {
        cout << "NO";
      }
    } else if (a[0] >= 65 && b[0] < 65) {
      cout << "YES";
    } else if (a[0] < 65 && b[0] >= 65) {
      cout << "NO";
    } else {
      if (a[0] == 'A') {
        cout << "NO";
      } else if (a[0] == 'T') {
        cout << "NO";
      } else if (a[0] == 'J') {
        if (b[0] == 'T') {
          cout << "YES";
        } else {
          cout << "NO";
        }
      } else if (a[0] == 'Q') {
        if (b[0] == 'T' || b[0] == 'J') {
          cout << "YES";
        } else {
          cout << "NO";
        }
      } else if (a[0] == 'K') {
        if (b[0] == 'A') {
          cout << "NO";
        } else {
          cout << "YES";
        }
      }
    }
  } else {
    cout << "NO";
  }
  return 0;
}
