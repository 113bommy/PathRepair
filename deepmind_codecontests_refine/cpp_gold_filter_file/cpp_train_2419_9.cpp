#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c;
    cin >> a >> b;
    if (a % b == 0) {
      std::cout << 0 << std::endl;
      continue;
    }
    if (a < b) {
      cout << b - a << endl;
      continue;
    }
    c = a / b;
    cout << (b * (c + 1)) - a << endl;
  }
}
