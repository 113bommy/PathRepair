#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[10] = {1, 1, 2, 2, 0, 0};
  int b[10] = {0, 2, 1, 0, 2, 1};
  int c[10] = {2, 0, 0, 1, 1, 2};
  long long n;
  int m;
  while (cin >> n >> m) {
    if (n > 6) n %= 6;
    if (n) {
      if (m == 0)
        cout << a[n - 1] << endl;
      else if (m == 1)
        cout << b[n - 1] << endl;
      else
        cout << c[n - 1] << endl;
    } else {
      if (m == 0)
        cout << a[6] << endl;
      else if (m == 1)
        cout << b[6] << endl;
      else
        cout << c[6] << endl;
    }
  }
  return 0;
}
