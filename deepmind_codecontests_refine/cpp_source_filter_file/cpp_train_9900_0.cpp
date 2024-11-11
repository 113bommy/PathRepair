#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  if (n == 3 && k == 3) {
    cout << 1 << endl;
  } else {
    if (k > (2 * n - 1) || k < 3) {
      cout << 0 << endl;
      return 0;
    }
    long long int s, e;
    if (k <= n + 1 && k != n) {
      s = 1;
      e = k - 1;
      cout << (e) / 2 << endl;
    } else if (k > n + 1) {
      s = k - n;
      cout << (n - s + 1) / 2 << endl;
    } else {
      cout << (n - 2) / 2 << endl;
    }
  }
}
