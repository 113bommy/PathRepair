#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k = 0, n = 0;
  cin >> n >> k;
  if (n >= k) {
    cout << (k - 1) / 2;
    return 0;
  }
  if (n < k && (2 * n - k + 1) / 2 > 0) {
    cout << (2 * n - k + 1) / 2;
    return 0;
  }
  if (n < k && (2 * n - k + 1) / 2 <= 0) {
    cout << 0;
  }
}
