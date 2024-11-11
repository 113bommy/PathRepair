#include <bits/stdc++.h>
using namespace std;
int main() {
  long long b, g, r, ans = 0, a[4] = {0}, s = 0;
  cin >> r >> g >> b;
  a[0] = r % 3;
  a[1] = g % 3;
  a[2] = b % 3;
  ans = (r / 3) + (g / 3) + (b / 3) + (min(a[0], min(a[1], a[2])));
  for (long long i = 0; i < 3; i++)
    if (a[i] == 2) s++;
  if (s == 2 && r > 3 && g > 3 && b > 3) ans += 1;
  cout << ans << endl;
  return 0;
}
