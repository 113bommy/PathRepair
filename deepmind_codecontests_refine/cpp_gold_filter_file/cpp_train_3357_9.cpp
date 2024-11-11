#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    if (k != 1) {
      long long int r = k % (n - 1);
      long long int q = k / (n - 1);
      if (r == 0) {
        cout << q * n - 1;
      } else {
        cout << q * n + r;
      }
    } else
      cout << 1;
    cout << endl;
  }
}
