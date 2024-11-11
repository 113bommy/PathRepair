#include <bits/stdc++.h>
using namespace std;
const long long MXN = 3e3 + 10;
long long n, m;
long long Ask(long long p) {
  fflush(stdout);
  cout << "? " << p << '\n';
  fflush(stdout);
  cin >> p;
  fflush(stdout);
  return p;
}
int main() {
  cin >> n;
  m = n / 2;
  if (m % 2) return cout << "! -1", 0;
  long long fir = Ask(1), sec = Ask(m + 1);
  if (fir == sec) return cout << "! 1", 0;
  long long l = 1, r = m;
  while (r - l > 0) {
    long long mid = (l + r) / 2;
    long long x = Ask(mid), y = Ask(mid + m);
    if (x == y) return cout << "! " << mid, 0;
    if (x - y < 0 && fir - sec < 0)
      l = mid + 1;
    else if (x - y > 0 && fir - sec > 0)
      l = mid + 1;
    else if (x - y < 0 && sec - fir < 0)
      r = mid - 1;
    else if (x - y > 0 && sec - fir > 0)
      r = mid - 1;
  }
  cout << "! " << l;
  return 0;
}
