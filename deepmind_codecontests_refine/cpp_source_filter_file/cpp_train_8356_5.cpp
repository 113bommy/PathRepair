#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long x = 0, y = 0, z = 0, r = 0, f = 0;
    x = n / 3;
    if (x * 3 != n) {
      x--;
      if (x * 3 + 5 == n)
        y++;
      else {
        x--;
        if (x * 3 + 7 == n)
          z++;
        else
          f = 1;
      }
    }
    if (x < 1) f = 1;
    if (f)
      cout << -1 << endl;
    else
      cout << x << "  " << y << " " << z << endl;
  }
}
