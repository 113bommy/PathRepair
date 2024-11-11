#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, ab;
  cin >> a >> b >> ab;
  if (a == b) {
    cout << a + b + (ab * 2);
  } else if (a > b) {
    cout << (ab * 2) + b + (b + 1);
  } else if (b > a) {
    cout << (ab * 2) + a + (a + 1);
  }
  return 0;
}
