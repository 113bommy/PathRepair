#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  if (n % 3 == 0) {
    long long rem = 3;
    while (true) {
      if (n % rem != 0) {
        break;
      }
      rem = rem * 3;
    }
    cout << n / 3 + 1;
  } else if (n % 3 == 1) {
    cout << n / 3 + 1;
  } else if (n % 3 == 2) {
    cout << (n + 1) / 3;
  }
  return 0;
}
