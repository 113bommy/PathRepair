#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, k;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n >> k;
    if (k >= n)
      cout << k - n << endl;
    else {
      if ((n % 2 == 0 && k % 2 == 1) || (n % 2 == 1 && k % 2 == 0))
        cout << 1 << endl;
      else
        cout << 0 << endl;
    }
  }
  return 0;
}
