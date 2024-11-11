#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  cin >> n >> a;
  if (n == 1) cout << a << endl;
  if (n % 2 == 0) {
    if (a >= n / 2 + 1) {
      cout << a - 1 << endl;
    } else
      cout << a + 1 << endl;
  } else {
    if (a == (n + 1) / 2)
      cout << a - 1 << endl;
    else if (a < (n + 1) / 2)
      cout << a + 1 << endl;
    else
      cout << a - 1 << endl;
  }
  return 0;
}
