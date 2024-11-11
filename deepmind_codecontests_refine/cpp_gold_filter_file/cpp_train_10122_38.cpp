#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b;
    cin >> a >> b;
    if (a == b) {
      cout << 0 << endl;
    } else if (a > b && (a - b) % 2 == 0) {
      cout << 1 << endl;
    } else if (a < b && (b - a) % 2 == 1) {
      cout << 1 << endl;
    } else {
      cout << 2 << endl;
    }
  }
  return 0;
}
