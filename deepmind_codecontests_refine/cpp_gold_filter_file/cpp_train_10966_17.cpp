#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  while (cin >> n >> k) {
    if (n * 2 == k)
      cout << k / 2 << endl;
    else {
      if ((k - n * 2) >= n)
        cout << 0 << endl;
      else
        cout << n - (k - n * 2) << endl;
    }
  }
  return 0;
}
