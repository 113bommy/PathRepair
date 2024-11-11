#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b, c;
  int x = 0, y = 0, z = 0;
  cin >> a >> b >> c;
  if (a[0] == 'r') {
    if (b[0] == 's' && c[0] == 's') {
      cout << 'F';
      return 0;
    }
  } else if (a[0] == 's') {
    if (b[0] == 'p' && c[0] == 'p') {
      cout << 'F';
      return 0;
    }
  } else if (a[0] == 'p') {
    if (b[0] == 'r' && c[0] == 'r') {
      cout << 'F';
      return 0;
    }
  }
  if (b[0] == 'r') {
    if (a[0] == 's' && c[0] == 's') {
      cout << 'M';
      return 0;
    }
  } else if (b[0] == 's') {
    if (a[0] == 'p' && c[0] == 'p') {
      cout << 'M';
      return 0;
    }
  } else if (b[0] == 'p') {
    if (a[0] == 'r' && c[0] == 'r') {
      cout << 'M';
      return 0;
    }
  }
  if (c[0] == 'r') {
    if (a[0] == 's' && b[0] == 's') {
      cout << 'S';
      return 0;
    }
  } else if (c[0] == 's') {
    if (a[0] == 'p' && b[0] == 'p') {
      cout << 'S';
      return 0;
    }
  } else if (c[0] == 'p') {
    if (a[0] == 'r' && b[0] == 'r') {
      cout << 'S';
      return 0;
    }
  }
  cout << '?';
  return 0;
}
