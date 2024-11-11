#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  if (n < 16) {
    if ((n == 10) || (n == 13) || (n == 4) || (n == 6) || (n == 9) ||
        (n == 0)) {
      cout << 1 << endl;
      return 0;
    }
    if ((n == 11) || (n == 8)) {
      cout << 2 << endl;
      return 0;
    } else {
      cout << 0 << endl;
      return 0;
    }
  }
  int sum = 0;
  while (n >= 16) {
    if ((n % 16 == 10) || (n % 16 == 13) || (n % 16 == 4) || (n % 16 == 6) ||
        (n % 16 == 9) || (n % 16 == 0)) {
      sum++;
    }
    if ((n % 16 == 11) || (n % 16 == 8)) {
      sum += 2;
    }
    n = n / 16;
  }
  if ((n == 10) || (n == 13) || (n == 4) || (n == 6) || (n == 9) || (n = 0)) {
    sum++;
  }
  if ((n == 11) || (n == 8)) {
    sum += 2;
  }
  cout << sum << endl;
  return 0;
}
