#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, g, b, c;
  cin >> t;
  while (t--) {
    cin >> n >> g >> b;
    if (g >= b) {
      cout << n << endl;
    } else {
      if (n % 2) {
        c = n / 2 + 1;
      } else {
        c = n / 2;
      }
      if (c < g) {
        cout << n << endl;
        continue;
      }
      if (c % g) {
        c = (c / g) * (g + b) + c % g;
      } else {
        c = (c / g - 1) * (g + b) + g;
      }
      if (c < n) {
        cout << c << endl;
      } else {
        cout << c << endl;
      }
    }
  }
}
