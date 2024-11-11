#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  if (b > n) b = n;
  if (a > n)
    cout << 0 << endl;
  else if (a == 1 && b == n)
    cout << 1 << endl;
  else {
    int r1, r2;
    a = min(a, b);
    b = max(a, b);
    a--;
    b--;
    r1 = a / m;
    r2 = b / m;
    if (r1 == r2)
      cout << 1 << endl;
    else if (b != n - 1 && a != 0) {
      if (a % m == 0 && b % m == m - 1)
        cout << 1 << endl;
      else if (a % m == 0 || b % m == m - 1)
        cout << 2 << endl;
      else if (r1 + 1 == r2)
        cout << 2 << endl;
      else {
        if ((a % m) + (b % m) == m)
          cout << 2 << endl;
        else
          cout << 3 << endl;
      }
    } else if (a != 0) {
      if (a % m == 0)
        cout << 1 << endl;
      else
        cout << 2 << endl;
    } else {
      if (b % m == m - 1)
        cout << 1 << endl;
      else
        cout << 2 << endl;
    }
  }
}
