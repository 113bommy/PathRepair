#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  int a, b, n;
  cin >> a >> b >> n;
  while (1) {
    n = n - gcd(a, n);
    if (n < b) {
      cout << 0 << endl;
      break;
    }
    n = n - gcd(b, n);
    if (n < a) {
      cout << 1 << endl;
      break;
    }
  }
  return 0;
}
