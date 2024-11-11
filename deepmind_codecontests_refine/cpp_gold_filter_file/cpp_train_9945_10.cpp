#include <bits/stdc++.h>
using namespace std;
int main() {
  string a1, a2, b1, b2;
  cin >> a1 >> a2 >> b1 >> b2;
  int t1 = 0;
  if (a1[0] != 'X') {
    if (a1[1] != 'X')
      t1 = int(a1[1]) - int(a1[0]);
    else {
      t1 = int(a2[0] - a2[1]);
    }
  } else {
    t1 = int(a2[1]) - int(a1[1]);
  }
  int t2 = 0;
  if (b1[0] != 'X') {
    if (b1[1] != 'X')
      t2 = int(b1[1]) - int(b1[0]);
    else
      t2 = int(b2[0] - b2[1]);
  } else {
    t2 = int(b2[1]) - int(b1[1]);
  }
  if (t1 == 1 || t1 == -2) {
    if (t2 == 1 || t2 == -2) {
      cout << "YES";
    } else {
      cout << "NO";
    }
  } else {
    if (t2 == 1 || t2 == -2) {
      cout << "NO";
    } else {
      cout << "YES";
    }
  }
  return 0;
}
