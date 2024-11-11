#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, d, d1;
  cin >> n >> m;
  int c[m];
  for (int i = 0; i < m; i++) {
    cin >> c[i];
  }
  sort(c, c + m);
  d = c[m - 1] - c[0];
  for (int i = n; i <= m; i++) {
    d1 = abs(c[i - 1] - c[i - n]);
    if (d1 < d) d = d1;
  }
  cout << d;
}
