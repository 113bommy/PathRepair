#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int a, b, n, val;
    cin >> a >> b >> n;
    val = a ^ b;
    if (n % 3 == 0) {
      cout << a << endl;
    } else if (n % 3 == 1) {
      cout << b << endl;
    } else {
      cout << val << endl;
    }
  }
}
