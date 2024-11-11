#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  while (cin >> n >> m) {
    int a = (n + m) / 3;
    if (n <= 2 * m && m <= 2 * n)
      cout << a << endl;
    else if (n > 2 * m)
      cout << m << endl;
    else if (n < 2 * n)
      cout << n << endl;
  }
  return 0;
}
