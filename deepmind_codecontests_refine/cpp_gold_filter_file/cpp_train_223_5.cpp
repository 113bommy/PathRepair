#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int x;
  cin >> x;
  while (x--) {
    long long int a, b, n;
    cin >> a >> b >> n;
    if (n % 3 == 0) {
      cout << a << endl;
    } else if (n % 3 == 1) {
      cout << b << endl;
    } else {
      a = a ^ b;
      cout << a << endl;
    }
  }
}
