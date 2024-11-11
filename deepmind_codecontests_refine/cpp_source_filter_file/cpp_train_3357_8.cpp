#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    long long x = b / a - 1;
    if ((x + b) % a == 0) {
      cout << x + b - 1 << endl;
    } else {
      cout << x + b << endl;
    }
  }
}
