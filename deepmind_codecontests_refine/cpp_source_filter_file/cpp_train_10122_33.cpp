#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, a, b, z = 0, x;
  cin >> t;
  int ans[t];
  while (z < t) {
    cin >> a >> b;
    if (a == b)
      x = 0;
    else if (a > b && ((a - b) % 2 == 1))
      x = 1;
    else if (a < b && ((b - a) % 2 == 0))
      x = 1;
    else
      x = 2;
    ans[z] = x;
    z++;
  }
  for (int i = 0; i < t; i++) cout << ans[i] << endl;
}
