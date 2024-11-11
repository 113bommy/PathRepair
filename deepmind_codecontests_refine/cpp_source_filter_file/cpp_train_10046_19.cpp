#include <bits/stdc++.h>
using namespace std;
int z;
int uni(int n, int m, int f, int g) {
  if ((n == 0 && f == z) || (f == 0 || n == z)) return 0;
  if ((m == 0 && g == z) || (m == z && g == 0))
    return 1;
  else
    return -1;
}
int main() {
  int n, m, f, g;
  cin >> z >> n >> m >> f >> g;
  int h = uni(n, m, f, g);
  if (h == -1)
    cout << abs(n - f) + abs(m - g);
  else if (h == 0)
    cout << z + min(z - m + z - g, m + g);
  else
    cout << z + min(z - n + z - f, n + f);
  return 0;
}
