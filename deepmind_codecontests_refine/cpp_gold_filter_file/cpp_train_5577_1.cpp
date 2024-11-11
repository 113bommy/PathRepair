#include <bits/stdc++.h>
using namespace std;
long long min(long long a, long long b, long long c) {
  return min(min(a, b), c);
}
int main() {
  long long n, a, b, c;
  cin >> n >> a >> b >> c;
  a = min(a, c + b, 3 * c);
  b = min(2 * a, b, 2 * c);
  c = min(3 * a, a + b, c);
  switch (4 - n % 4) {
    case 1:
      cout << a;
      break;
    case 2:
      cout << b;
      break;
    case 3:
      cout << c;
      break;
    default:
      cout << 0;
  }
  return 0;
}
