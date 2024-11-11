#include <bits/stdc++.h>
using namespace std;
int main(void) {
  long long int n, k, p, x;
  cin >> n >> k >> p;
  for (int i = 0; i < p; i++) {
    cin >> x;
    if (k == 0)
      cout << '.';
    else if (n <= 2 * k) {
      if ((x & 1) && x < 2 * (n - k))
        cout << '.';
      else
        cout << 'X';
    } else if (n & 1) {
      if ((x <= n - 2 * k + 2 || (x & 1)) && x < n)
        cout << '.';
      else
        cout << 'X';
    } else {
      if (x <= n - k * 2 + 1 || (x & 1))
        cout << '.';
      else
        cout << 'X';
    }
  }
  return 0;
}
