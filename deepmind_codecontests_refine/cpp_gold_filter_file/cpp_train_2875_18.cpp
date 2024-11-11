#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n;
  cin >> k;
  if (k == 0 || k == n) {
    cout << 0 << " " << 0;
    return 0;
  }
  if (n >= 3 * k) {
    cout << 1 << " " << 2 * k;
    return 0;
  }
  if (n < 3 * k) {
    cout << 1 << " " << n - k;
    return 0;
  }
}
