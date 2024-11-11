#include <bits/stdc++.h>
using namespace std;
int a[101], b[101];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, i, j, x = 0, y = 0, z = 1e9;
  cin >> n;
  a[0] = b[0] = 0;
  while (n--) {
    cin >> i >> j;
    if (i == 1)
      a[++x] = j;
    else
      b[++y] = j;
  }
  sort(a + 1, a + 1 + x);
  sort(b + 1, b + 1 + y);
  for (i = 2; i <= x; i++) a[i] += a[i - 1];
  for (j = 2; j <= y; j++) b[i] += b[i - 1];
  for (i = 0; i <= x; i++)
    for (j = 0; j <= y; j++)
      if (i + j * 2 >= a[x - i] + b[y - j]) z = min(z, i + j * 2);
  cout << z;
}
