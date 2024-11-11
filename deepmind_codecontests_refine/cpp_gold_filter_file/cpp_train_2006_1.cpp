#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (n < k)
      cout << k - n << endl;
    else {
      if ((n & 1) == (k & 1))
        cout << 0 << endl;
      else
        cout << 1 << endl;
    }
  }
  return 0;
}
