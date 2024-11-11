#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, x, y, a, b, c, d;
  cin >> n >> x >> y;
  if (x == y) {
    a = x - 1;
    b = n - x;
    if (a <= b) {
      cout << "White";
    } else {
      cout << "Black";
    }
  } else {
    a = (x - 2) + (y - 2);
    b = (n - x) + (n - y);
    if (a < b) {
      cout << "White";
    } else {
      cout << "Black";
    }
  }
  return 0;
}
