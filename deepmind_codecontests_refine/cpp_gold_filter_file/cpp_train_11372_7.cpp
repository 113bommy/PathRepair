#include <bits/stdc++.h>
using namespace std;
long long u, v, c, d, e;
int main() {
  cin >> u >> v;
  if (!u && !v) {
    cout << 0;
    return 0;
  }
  if (u == v) {
    cout << 1 << '\n' << u;
    return 0;
  }
  if (u > v || u % 2 != v % 2) {
    cout << -1;
    return 0;
  }
  e = (v - u) / 2;
  c = u + e;
  d = e;
  if ((c ^ d) == u) {
    cout << 2 << '\n' << c << " " << d;
    return 0;
  }
  cout << 3 << '\n';
  cout << d << " " << d << " " << u;
  return 0;
}
