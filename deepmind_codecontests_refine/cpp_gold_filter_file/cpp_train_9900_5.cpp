#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  if (k > 2 * n - 1) {
    cout << "0";
  } else if (k < 2 * n && k > n) {
    if (k % 2 == 0) {
      cout << n - k / 2;
    } else {
      cout << n - (k - 1) / 2;
    }
  } else if (k < n + 1) {
    if (k % 2 == 0)
      cout << k / 2 - 1;
    else
      cout << k / 2;
  }
}
