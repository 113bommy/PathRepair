#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  if (n <= 7) {
    if (n == 1 or n == 2 or n == 4 or n == 5)
      cout << 1 << endl;
    else
      cout << 0 << endl;
    return 0;
  }
  long long k1 = 4, k2 = 5;
  int h = 1;
  while (k1 < n or k2 < n) {
    if (n == k1 or n == k2) {
      cout << 1 << endl;
      return 0;
    }
    if (h & 1) {
      k1 = 2 * k1 + 1;
      k2 = k1 + 1;
    } else {
      k1 = 2 * k2;
      k2 = k1 + 1;
    }
    h++;
  }
  cout << 0 << endl;
}
