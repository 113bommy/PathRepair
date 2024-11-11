#include <bits/stdc++.h>
using namespace std;
int a[5];
int main() {
  while (cin >> a[1] >> a[2] >> a[3] >> a[4]) {
    sort(a, a + 5);
    int x = 0, y = a[4];
    int i = 3;
    while (i > 0) {
      if (y > x)
        x += a[i--];
      else
        y += a[i--];
    }
    if (x == y)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
