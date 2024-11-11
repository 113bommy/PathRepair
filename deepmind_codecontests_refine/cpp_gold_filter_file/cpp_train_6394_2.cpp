#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, w, x, c;
  cin >> a >> b >> w >> x >> c;
  long long l = 0, r = 4e16 + 10;
  for (; r > l;) {
    long long m = (l + r) / 2;
    if (c - m <=
        a - (m * x > b ? ceil((double(m) * double(x) - double(b)) / double(w))
                       : 0))
      r = m;
    else
      l = m + 1;
  }
  cout << l;
  return 0;
}
