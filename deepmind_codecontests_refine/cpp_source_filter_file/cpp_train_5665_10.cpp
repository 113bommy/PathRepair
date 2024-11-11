#include <bits/stdc++.h>
using namespace std;
pair<int, int> p[105];
int main() {
  int n, s1 = 0, s2 = 0, t = 0, x, y;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    s1 += x;
    s1 &= 1;
    s2 += y;
    s2 &= 1;
    t |= (x + y) & 1;
  }
  if (!s1 && !s2)
    cout << 0;
  else if (!(s1 + s2) & 1 && t)
    cout << 1;
  else
    cout << -1;
}
