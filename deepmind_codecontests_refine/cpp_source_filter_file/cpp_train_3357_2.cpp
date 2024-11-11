#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  int n, k, c;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    int start;
    c = n - 1;
    if (k <= c) {
      cout << k << "\n";
    } else if (k == n) {
      cout << n + 1 << "\n";
    } else {
      int rem = k % n;
      int initial = (k - (k % (n - 1))) / (n - 1);
      if (rem == 0) {
        start = (n * initial - 1);
      } else {
        start = (n * initial + k % (n - 1));
      }
      cout << start << "\n";
    }
  }
  return 0;
}
