#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  cin >> a >> b;
  int aa;
  int bb;
  if (a[0] == 'm') {
    aa = 1;
  } else if (a[0] == 't' && a[1] == 'u') {
    aa = 2;
  } else if (a[0] == 'w') {
    aa = 3;
  } else if (a[0] == 't') {
    aa = 4;
  } else if (a[0] == 'f') {
    aa = 5;
  } else if (a[0] == 's' && a[1] == 'a') {
    aa = 6;
  } else if (a[0] == 's') {
    aa = 7;
  }
  bb = aa;
  a = b;
  if (a[0] == 'm') {
    aa = 1;
  } else if (a[0] == 't' && a[1] == 'u') {
    aa = 2;
  } else if (a[0] == 'w') {
    aa = 3;
  } else if (a[0] == 't') {
    aa = 4;
  } else if (a[0] == 'f') {
    aa = 5;
  } else if (a[0] == 's' && a[1] == 'a') {
    aa = 6;
  } else if (a[0] == 's') {
    aa = 7;
  }
  int s = (bb - aa + 7) % 7;
  if (s == 0 || s == 2 || s == 3) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
