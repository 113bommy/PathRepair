#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    long long z = 0, x = 1;
    for (int i = 1; i <= 9; i++) {
      x *= 10;
      if (x - 1 <= b) {
        z = i;
      }
    }
    cout << z * a << endl;
  }
}
