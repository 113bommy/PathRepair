#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, result, m;
  cin >> a >> b >> c;
  if (a == 1 && b == 1 && c == 1) {
    result = a + b + c;
  } else if (a == 1 && b == 1) {
    result = (a + b) * c;
  } else if (b == 1 && c == 1) {
    result = a * (b + c);
  } else if (a == 1 && c == 1) {
    result = a + b + c;
  } else if (a == 1) {
    result = (a + b) * c;
  } else if (b == 1) {
    m = min(a, c);
    if (m == a) {
      result = (a + b) * c;
    } else {
      result = a * (b + c);
    }
  } else if (c == 1) {
    result = a * (b + c);
  } else {
    result = a * b * c;
  }
  cout << result;
  return 0;
}
