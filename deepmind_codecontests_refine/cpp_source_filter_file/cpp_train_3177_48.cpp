#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, x, y, z;
  cin >> a >> b >> c >> x >> y >> z;
  int cnt1 = 0, cnt2 = 0;
  cnt1 += max(0, a - x) / 2;
  cnt1 += max(0, b - y) / 2;
  cnt1 += max(0, c - z) / 2;
  cnt2 += max(0, x - a);
  cnt2 += max(0, y - b);
  cnt2 += max(0, z - c);
  if (cnt1 == cnt2)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
