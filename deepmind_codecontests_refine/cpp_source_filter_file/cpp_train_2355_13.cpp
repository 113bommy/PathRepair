#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  int p = 1 << 17;
  cin >> n >> x;
  if (n == 2 && x == 0)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    if (n == 1)
      cout << x << endl;
    else if (n == 2)
      cout << 1 << n - 1 << endl;
    else {
      int a, b, c;
      a = 0;
      for (int i = 1; i <= n - 2; ++i) {
        a ^= i;
      }
      b = a ^ p, c = x ^ p;
      if (b == c) {
        for (int i = 0; i < n - 2; ++i) cout << i << " ";
        a ^= n - 2;
        b = a ^ p;
        c = x ^ p;
        cout << b << " " << c << endl;
      } else {
        for (int i = 1; i <= n - 2; ++i) cout << i << " ";
        cout << b << " " << c << endl;
      }
    }
  }
  return 0;
}
