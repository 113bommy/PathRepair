#include <bits/stdc++.h>
using namespace std;
long long n, k, l, r, c, t, x;
int main() {
  cin >> n >> k;
  l = 1;
  r = n + n;
  while (l < r) {
    c = (l + r) / 2;
    t = 0;
    x = c;
    while (x) {
      t += x;
      x /= k;
    }
    if (t < n)
      l = c + 1;
    else
      r = c;
  }
  cout << (l) << endl;
  return 0;
}
