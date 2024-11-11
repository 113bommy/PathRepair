#include <bits/stdc++.h>
using namespace std;
long int c1, c2, c3, c4, n, m, i, a = 0, t = 0, tmp;
int main() {
  cin >> c1 >> c2 >> c3 >> c4 >> n >> m;
  for (i = 0; i < n; ++i) {
    cin >> tmp;
    if (tmp < (c2 / c1))
      a += tmp * c1;
    else
      a += c2;
  }
  if (a > c3) a = c3;
  for (i = 0; i < m; ++i) {
    cin >> tmp;
    if (tmp < (c2 / c1))
      t += tmp * c1;
    else
      t += c2;
  }
  a += min(c3, t);
  cout << min(c4, a);
  return 0;
}
