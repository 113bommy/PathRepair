#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  if (n > 36) {
    cout << "-1" << endl;
  } else if (n == 1) {
    cout << 4 << endl;
  } else if (n % 2 == 0) {
    for (long long i = 1; i <= n / 2; i++) {
      cout << 8;
    }
    cout << endl;
  } else {
    for (long long i = 1; i <= n / 2; i++) {
      cout << 8;
    }
    cout << 0 << endl;
  }
  return 0;
}
