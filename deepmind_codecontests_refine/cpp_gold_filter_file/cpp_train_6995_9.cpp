#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, b = 0, p = 0, a = 0, t;
  cin >> n;
  x = n;
  while (x > 0) {
    if (x % 10 != 4 && x % 10 != 7) {
      p = 1;
      break;
    }
    x = x / 10;
  }
  if (p != 1)
    cout << "YES";
  else if (n % 47 == 0)
    cout << "YES";
  else {
    t = n;
    while (t % 4 == 0) {
      a++;
      t = t / 4;
    }
    t = n;
    while (t % 7 == 0) {
      b++;
      t = t / 7;
    }
    if (a == 0 && b == 0)
      cout << "NO";
    else if (a % 2 != 0 && b % 2 != 0 && (a + b) % 2 != 0)
      cout << "NO";
    else
      cout << "YES";
  }
}
