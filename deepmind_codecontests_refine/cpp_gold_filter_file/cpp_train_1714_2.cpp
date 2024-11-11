#include <bits/stdc++.h>
using namespace std;
#pragma(comment, linker("\STACK:50000000"))
int main() {
  ios_base::sync_with_stdio(0);
  long long a, b, c;
  cin >> a >> b >> c;
  if (a >= 2 * (b + c)) {
    cout << b + c;
    return 0;
  }
  if (b >= 2 * (a + c)) {
    cout << a + c;
    return 0;
  }
  if (c >= 2 * (a + b)) {
    cout << a + b;
    return 0;
  }
  cout << (a + b + c) / 3;
  return 0;
}
