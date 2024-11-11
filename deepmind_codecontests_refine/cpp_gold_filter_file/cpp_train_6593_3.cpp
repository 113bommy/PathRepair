#include <bits/stdc++.h>
using namespace std;
int a, s, d, f, g, h, j, k, l, n, i, q, nas, nas1;
string z, x, z1, x1;
int main() {
  cin >> n >> z1 >> x1;
  j = z1.size();
  k = x1.size();
  h = min(j, k);
  g = 0;
  for (i = 0; i < k; i++) {
    z = z + z1;
  }
  for (i = 0; i < j; i++) {
    x = x + x1;
  }
  for (i = 0; i < k * j; i++) {
    if (i == n) {
      cout << d << " " << f;
      return 0;
    }
    if (z[i] == 'R' && x[i] == 'S') f++;
    if (x[i] == 'R' && z[i] == 'S') d++;
    if (z[i] == 'S' && x[i] == 'P') f++;
    if (x[i] == 'S' && z[i] == 'P') d++;
    if (z[i] == 'P' && x[i] == 'R') f++;
    if (x[i] == 'P' && z[i] == 'R') d++;
  }
  for (i = 0; i < n % (k * j); i++) {
    if (z[i] == 'R' && x[i] == 'S') nas1++;
    if (x[i] == 'R' && z[i] == 'S') nas++;
    if (z[i] == 'S' && x[i] == 'P') nas1++;
    if (x[i] == 'S' && z[i] == 'P') nas++;
    if (z[i] == 'P' && x[i] == 'R') nas1++;
    if (x[i] == 'P' && z[i] == 'R') nas++;
  }
  if (d > 0)
    cout << n / (k * j) * d + nas << " ";
  else
    cout << 0 << " ";
  if (f > 0)
    cout << n / (k * j) * f + nas1 << " ";
  else
    cout << 0;
}
