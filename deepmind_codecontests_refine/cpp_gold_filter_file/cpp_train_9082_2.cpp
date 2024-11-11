#include <bits/stdc++.h>
using namespace std;
void flag(long long l, long long r, long long m) {
  long long a, x;
  a = 0;
  for (a = l; a <= r; a++) {
    x = m % a;
    if (x <= r - l && m / a > 0) {
      cout << a << ' ' << x + l << ' ' << l << endl;
      return;
    }
    if (a - x <= r - l) {
      cout << a << ' ' << l << ' ' << a - x + l << endl;
      return;
    }
  }
}
int main() {
  long long t, l, r, m;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> l >> r >> m;
    flag(l, r, m);
  }
}
