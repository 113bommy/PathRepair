#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n;
  while (cin >> n >> m) {
    int b, a = n / 2 + n % 2;
    bool f = 0;
    for (int i = a; i < n; i++)
      if (i % m == 0) {
        f = 1;
        b = i;
        break;
      }
    if (f && b >= m)
      cout << b << endl;
    else
      cout << -1 << endl;
  }
}
