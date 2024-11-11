#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, r, a, b, x;
  cin >> n >> m >> r;
  int c[n], d[m];
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> d[i];
  }
  sort(c, c + n);
  sort(d, d + n, greater<int>());
  x = r;
  a = r / c[0];
  r -= a * c[0];
  b = a * d[0];
  b += r;
  cout << max(x, b) << endl;
}
