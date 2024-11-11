#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, y, z, ans1 = 0, ans2 = 0;
  cin >> x >> y;
  z = abs(x - y) / 2;
  y = abs(x - y) - z;
  for (int i = 1; i <= z; i++) ans1 = ans1 + i;
  for (int i = 1; i <= y; i++) ans2 = ans2 + i;
  cout << ans1 + ans2;
}
