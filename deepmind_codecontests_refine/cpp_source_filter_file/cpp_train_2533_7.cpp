#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  if (n == 1) {
    cout << 1;
  } else {
    long long x = 0;
    long long a = n;
    long long sum = 0;
    while (a != 1) {
      for (long long i = 2; i * i <= a; i++) {
        if (a % i == 0) {
          sum += a;
          a = a / i;
          x = 1;
          break;
        }
      }
      if (x == 0) {
        sum += 1;
        a = 1;
      } else {
        x = 0;
      }
    }
    cout << sum;
  }
  return 0;
}
