#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  if (a >= b) {
    cout << b << " " << (a - b) / 2;
  } else if (b > a) {
    cout << a << " " << (b - a) / 2;
  }
  return 0;
}
