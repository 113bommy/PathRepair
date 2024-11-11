#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int i, a, b, c, x = n, y = 1, z = 1;
  for (i = 1; i < (n / 2); i++) {
    if (n % i == 0) {
      a = i;
      b = n / i;
      c = abs(a - b);
      if (c < x) {
        x = c;
        y = a;
        z = b;
      }
    }
  }
  cout << y << " " << z << endl;
}
