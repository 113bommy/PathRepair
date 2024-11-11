#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  int r, count = 0;
  while (b != 0) {
    int r = a % b;
    count += a / b;
    ;
    a = b;
    b = r;
  }
  return count;
}
int main() {
  int tst;
  cin >> tst;
  while (tst--) {
    int a, b;
    cin >> a >> b;
    int val = gcd(a, b);
    cout << val;
  }
  return 0;
}
