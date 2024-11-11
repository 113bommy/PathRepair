#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, a, b, p, r;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    if (a % b != 0) {
      p = a / b;
      r = b * (p + 1) - a;
      cout << r << '\n';
    } else if (a % b == 0) {
      cout << '0';
    }
  }
}
