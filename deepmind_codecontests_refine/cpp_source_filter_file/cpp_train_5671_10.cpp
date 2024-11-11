#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, n, m, dx, dy;
  cin >> n >> m >> dx >> dy;
  long long aux, res, x, y, a[n], c[n];
  a[0] = 0;
  for (i = 1; i < n; i++) {
    a[(i * dx) % n] = (i * dy) % n;
  }
  memset(c, 0, sizeof c);
  res = 0;
  for (i = 0; i < m; i++) {
    cin >> x >> y;
    aux = (n + y - a[x]) % n;
    c[aux]++;
    if (c[aux] > c[res]) res = aux;
  }
  cout << 0 << " " << c[res] << endl;
}
