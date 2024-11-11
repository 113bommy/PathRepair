#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  if (k == n) {
    cout << 0 << " " << 0 << endl;
    return 0;
  }
  if (k == 0) {
    cout << 0 << " " << 0 << endl;
    return 0;
  }
  cout << 1 << (n == 2 ? 1 : (3 * k > n ? (n - k) : 2 * k)) << endl;
  return 0;
}
