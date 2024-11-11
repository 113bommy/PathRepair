#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  if (n % 2 == 0) {
    cout << (n / 2);
    return 0;
  } else {
    long long temp = -1;
    for (long long i = 2; i * i <= n; i++) {
      if (n / i == 0) {
        temp = i;
        break;
      }
    }
    if (temp == -1) {
      cout << 1;
      return 0;
    } else {
      n -= temp;
      cout << (n / 2) + 1;
      return 0;
    }
  }
  return 0;
}
