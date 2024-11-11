#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, r;
  cin >> a >> b;
  if (a < b) {
    int t = a;
    a = b;
    b = t;
  }
  if (a % 2 == 0 || b % 2 == 0) {
    r = a * b / 2;
  } else {
    r = (b - 1) * a / 2 + a / 2;
  }
  cout << r;
}
