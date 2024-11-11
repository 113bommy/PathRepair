#include <bits/stdc++.h>
using namespace std;
bool prime(int n) {
  if (n == 1) return 0;
  int dal = 0;
  for (int i = 2; i <= sqrt(n * 1.0); i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
int main() {
  int n;
  cin >> n;
  if (prime(n)) {
    cout << 1 << endl;
    cout << n;
  } else if (n == 4) {
    cout << 2 << endl << 2 << " " << 2;
  } else if (n % 2 == 0) {
    cout << 2 << endl;
    int k = 3;
    while (prime(n - k) + prime(k) != 2) {
      k += 2;
    }
    cout << k << " " << n - k;
  } else {
    cout << 3 << endl;
    cout << 2 << " ";
    n = n - 2;
    int k = 3;
    while (prime(n - k) + prime(k) != 2) {
      k += 2;
    }
    cout << k << " " << n - k;
  }
}
