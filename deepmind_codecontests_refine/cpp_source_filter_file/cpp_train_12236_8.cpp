#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  if (b == 0) {
    cout << a << endl;
  } else if (b > 0) {
    b = b % n;
    if (b == 0) {
      cout << a << endl;
    } else {
      int val = (a + b);
      val = val > n ? val % n + 1 : val;
      cout << val << endl;
    }
  } else {
    b = -b;
    b = b % n;
    if (b == 0) {
      cout << a << endl;
    } else {
      int val = a - b;
      val = val <= 0 ? val + n : val;
      cout << val << endl;
    }
  }
  return 0;
}
