#include <bits/stdc++.h>
using namespace std;
int a[211111], b[211111], c[211111], n, m, i, j, x, y, z;
int main() {
  int t;
  cin >> n >> m;
  t = m;
  for (i = 1; i <= n; i++) {
    cin >> x;
    a[x]++;
    t = min(x, t);
  }
  while (t < m) {
    z++;
    for (i = t; i < m; i++)
      if (a[i] > 0) {
        a[i + 1]++;
        a[i]--;
      }
    if (a[t] == 0) t++;
  }
  cout << z;
}
