#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    if (k >= n) {
      cout << (k - n) << endl;
    } else {
      if (k % 2 && n % 2) {
        cout << 0 << endl;
      } else {
        cout << 1 << endl;
      }
    }
  }
}
