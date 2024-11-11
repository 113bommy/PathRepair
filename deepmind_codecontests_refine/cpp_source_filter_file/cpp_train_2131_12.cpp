#include <bits/stdc++.h>
int e(long long a) {
  long long s = abs(a);
  while (s) {
    if (s % 10 == 8) {
      return false;
    }
    s /= 10;
  }
  return true;
}
using namespace std;
int main() {
  long long a, b;
  cin >> a;
  b = a;
  while (e(b)) {
    b++;
  }
  cout << b - a;
  return 0;
}
