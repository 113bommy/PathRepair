#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int line, a, b, n, i, j;
  cin >> line;
  while (line--) {
    cin >> a >> b >> n;
    long long int c = a ^ b;
    if (n % 3 == 0) {
      cout << a << endl;
    } else if (n % 3 == 1) {
      cout << b << endl;
    } else {
      cout << c << endl;
    }
  }
  return 0;
}
