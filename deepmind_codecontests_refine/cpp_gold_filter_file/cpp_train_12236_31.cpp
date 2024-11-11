#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  if (b < 0) {
    b = abs(b);
    while (b != 0) {
      if (a == 1) a = n + 1;
      a--;
      b--;
    }
    cout << a << endl;
  } else if (b >= 0) {
    while (b != 0) {
      if (a == n) a = 0;
      a++;
      b--;
    }
    cout << a << endl;
  }
  return 0;
}
