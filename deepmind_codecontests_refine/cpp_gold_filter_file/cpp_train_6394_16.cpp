#include <bits/stdc++.h>
using namespace std;
long long a, b, w, x, c;
bool catched(long long k) {
  long long step = (b + k * x) / w;
  return ((c - k) <= (a - k + step));
}
int main() {
  ios::sync_with_stdio(NULL);
  cin.tie(NULL);
  cin >> a >> b >> w >> x >> c;
  x = w - x;
  long long l = -1, r = 2 * 1e12;
  while (r - l > 1) {
    long long m = (l + r) >> 1;
    if (catched(m))
      r = m;
    else
      l = m;
  }
  cout << r;
  return 0;
}
