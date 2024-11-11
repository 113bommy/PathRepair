#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long n, k;
    cin >> n >> k;
    if (n % 2 == 0 && k == 1) {
      cout << "NO" << endl;
      continue;
    }
    if (n % 2 == 1 && k == 1) {
      cout << "YES" << endl;
      continue;
    }
    if (n < k * k) {
      cout << "NO" << endl;
      continue;
    }
    if (n % 2 == 1 && k % 2 == 1) {
      cout << "YES" << endl;
      continue;
    }
    if (n % 2 == 1 && k % 2 == 0) {
      cout << "NO" << endl;
      continue;
    }
    if (n % 2 == 0 && k % 2 == 1) {
      cout << "NO" << endl;
      continue;
    }
    if (n % 2 == 0 && k % 2 == 0) {
      cout << "YES" << endl;
      continue;
    }
  }
  return 0;
}
