#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, t, a, k1, k2, k3;
  cin >> n;
  t = k1 = k2 = k3 = 0;
  for (i = 0; i < n; i++) {
    cin >> a;
    if (a == 1)
      k1++;
    else if (a == 2)
      k2++;
    else if (a == 3)
      k3++;
    else if (a == 4)
      t++;
  }
  t += k3;
  if (k1 > k3)
    k1 -= k3;
  else
    k1 = 0;
  t = k2 / 2;
  k2 = k2 % 2;
  k1 += 2 * k2;
  t += (k1 + 3) / 4;
  cout << t << endl;
  return 0;
}
