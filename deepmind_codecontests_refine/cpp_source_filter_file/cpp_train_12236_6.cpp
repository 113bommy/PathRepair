#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (c >= 0) {
    if ((b + c) % a == 0) {
      cout << a;
      return 0;
    } else {
      cout << (b + c) % a;
      return 0;
    }
  } else if (c < 0) {
    if (b + c == 0) {
      cout << a;
      return 0;
    } else if (b + c > 0) {
      cout << c + b;
      return 0;
    } else {
      cout << (a + (b + c));
      return 0;
    }
  }
  return 0;
}
