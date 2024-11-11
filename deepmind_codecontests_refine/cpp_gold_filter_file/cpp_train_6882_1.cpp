#include <bits/stdc++.h>
using namespace std;
long long sumofdigits(long long n) {
  long long s = 0;
  while (n != 0) {
    s += n % 10;
    n /= 10;
  }
  return s;
}
int main() {
  long long n, m, x = 0, y;
  cin >> n;
  while (1) {
    if (x * 10 + 9 <= n) {
      x = x * 10;
      x += 9;
    } else {
      y = n - x;
      cout << sumofdigits(x) + sumofdigits(y) << endl;
      return 0;
    }
  }
  return 0;
}
