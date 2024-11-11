#include <bits/stdc++.h>
using namespace std;
int m;
int main() {
  cin >> m;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c) {
      cout << 0 << endl;
      continue;
    }
    if (abs(a - b) + abs(b - c) + abs(a - c) <= 2) {
      cout << 0 << endl;
      continue;
    }
    if (a == b && b > c) {
      a--;
      b--;
      c++;
      cout << abs(a - b) + abs(a - c) + abs(b - c) << endl;
      continue;
    } else if (a == c && b > c) {
      a--;
      c--;
      b++;
      cout << abs(a - b) + abs(a - c) + abs(b - c) << endl;
      continue;
    } else if (b == c && c > a) {
      b--;
      c--;
      if (c != a) a++;
      cout << abs(a - b) + abs(a - c) + abs(b - c) << endl;
      continue;
    } else if (a == b && b < c) {
      a++;
      b++;
      if (b != c) c--;
      cout << abs(a - b) + abs(a - c) + abs(b - c) << endl;
      continue;
    } else if (a == c && b < c) {
      a++;
      c++;
      if (c != b) b--;
      cout << abs(a - b) + abs(a - c) + abs(b - c) << endl;
      continue;
    } else if (b == c && c < a) {
      b++;
      c++;
      if (c != a) a--;
      cout << abs(a - b) + abs(a - c) + abs(b - c) << endl;
      continue;
    }
    if (a >= b && a >= c) {
      a--;
      b >= c ? c++ : b++;
    } else if (b >= c) {
      b--;
      a >= c ? c++ : a++;
    } else {
      c--;
      a >= b ? b++ : a++;
    }
    cout << abs(a - b) + abs(a - c) + abs(b - c) << endl;
  }
  return 0;
}
