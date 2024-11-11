#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n;
  if (n <= 9)
    cout << n;
  else if (n <= 189) {
    n -= 9;
    if (n & 1) {
      n = (n + 1) / 2;
      k = 10 + (n - 1);
      cout << (k / 10);
    } else {
      n /= 2;
      k = 10 + (n - 1);
      cout << (k % 10);
    }
  } else if (n <= 1000) {
    n -= 189;
    if (n % 3 == 1) {
      n = (n + 2) / 3;
      k = 100 + (n - 1);
      cout << k / 100;
    } else if (n % 3 == 2) {
      n = (n + 1) / 3;
      k = 100 + (n - 1);
      cout << (k / 10) % 10;
    } else if (n % 3 == 0) {
      n = (n) / 3;
      k = 100 + (n - 1);
      cout << k % 10;
    }
  }
  return 0;
}
