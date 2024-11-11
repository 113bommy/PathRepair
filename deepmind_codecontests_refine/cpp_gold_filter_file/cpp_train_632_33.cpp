#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long n, k, p, x;
  cin >> n >> k >> p;
  while (p--) {
    cin >> x;
    x = n - x;
    bool X = false;
    if (n % 2 == 0) {
      X |= (x % 2 == 0 && x <= 2 * (k - 1));
      if (k > n / 2) X |= (x % 2 == 1 && x < (k - n / 2) * 2);
    } else {
      X |= (x == 0 && k || x % 2 == 1 && x < 2 * (k - 1));
      if (k > (n + 1) / 2) X |= (x % 2 == 0 && x <= 2 * (k - (n + 1) / 2));
    }
    cout << (X ? 'X' : '.');
  }
  cout << endl;
  return 0;
}
