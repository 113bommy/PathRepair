#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  long long res = c;
  if (a >= b) {
    res += b + b;
    a -= b;
    res += a > 0;
  } else {
    res += a + a;
    b -= a;
    res += b > 0;
  }
  cout << res;
  return 0;
}
