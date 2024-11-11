#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, a, b, n;
  cin >> a >> b;
  if (b % 2 == 1) {
    b = (b + 1) / 2;
    cout << b << endl;
  } else {
    b = a - b + 1;
    cout << b << endl;
  }
  return 0;
}
