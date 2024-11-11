#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  b = b % n;
  if (b > 0) {
    a = a + b;
    if (a >= n) {
      cout << a % n + 1;
    } else {
      cout << a;
    }
  } else {
    a += b;
    if (a <= 0) {
      cout << n + a;
    } else {
      cout << a;
    }
  }
  return 0;
}
