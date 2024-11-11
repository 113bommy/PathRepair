#include <bits/stdc++.h>
using namespace std;
int x[5000], y[5000], z[5000];
int main() {
  int n, m, k;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i];
  cin >> m;
  for (int i = 0; i < m; i++) cin >> y[i];
  cin >> k;
  for (int i = 0; i < k; i++) cin >> z[i];
  int a, b;
  cin >> a >> b;
  sort(x, x + n);
  sort(y, y + m);
  sort(z, z + k);
  float kq = x[n - 1] * sqrt((float)(y[m - 1] * b) / (a * z[0] + b * y[m - 1]));
  cout << setprecision(12) << kq;
  return 0;
}
