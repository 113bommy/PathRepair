#include <bits/stdc++.h>
using namespace std;
long int mx(long int a, long int b) {
  if (a > b) return a;
  return b;
}
long int mn(long int a, long int b) {
  if (a < b) return a;
  return b;
}
int main() {
  long int n, a, b, i;
  cin >> n;
  long int temp = n;
  for (i = 1; i <= n; i++) {
    if (n % i == 0) {
      long int x = mn(i, (n / i));
      long int y = mx(i, (n / i));
      if ((y - x) < temp) {
        temp = y - x;
        a = x;
        b = y;
      }
    }
  }
  cout << a << " " << b << "\n";
  return 0;
}
