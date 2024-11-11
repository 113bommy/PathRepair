#include <bits/stdc++.h>
using namespace std;
int main() {
  int xa[300005] = {0};
  for (int i = 1; i <= 300000; i++) {
    xa[i] = (xa[i - 1] ^ i);
  }
  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    long long x = xa[a - 1];
    if (x == b) {
      cout << a << endl;
    } else {
      if ((x ^ b) == a) {
        cout << a + 2 << endl;
      } else {
        cout << a + 1 << endl;
      }
    }
  }
}
