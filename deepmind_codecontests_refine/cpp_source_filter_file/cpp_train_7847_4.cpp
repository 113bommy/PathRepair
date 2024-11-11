#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, y, m, c;
  cin >> x >> y >> m;
  c = 0;
  if (x < y) swap(x, y);
  if (x < 1 && x < m) {
    cout << -1;
    return 0;
  }
  if (y < 0) {
    c = -y / x;
    y += c * x;
  }
  while (x < m) {
    c++;
    y += x;
    if (x < y) swap(x, y);
  }
  cout << c;
  return 0;
}
