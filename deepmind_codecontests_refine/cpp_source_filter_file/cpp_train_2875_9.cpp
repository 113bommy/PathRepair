#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n, k;
  cin >> n >> k;
  if (k == 0)
    cout << 0 << " " << 0;
  else {
    if (k == n)
      cout << 0 << " " << 0;
    else {
      if (n <= 3 * k) {
        cout << 1 << " " << n - k;
      } else {
        cout << 1 << " " << 2 * k;
      }
    }
  }
  return 0;
}
