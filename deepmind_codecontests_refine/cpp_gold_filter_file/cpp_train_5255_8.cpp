#include <bits/stdc++.h>
using namespace std;
int n, m, i, j;
long long w[101][101], a[101], b[101], c[101][101], t, mx, k;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
void vivod(long long s) {
  cout << "YES" << endl;
  cout << s << endl;
  for (int i = 1; i <= n; i++)
    if (a[i] >= 0)
      cout << a[i] << " ";
    else
      cout << a[i] + (a[i] / s) + s << " ";
  cout << endl;
  for (int j = 1; j <= m; j++)
    if (b[j] >= 0)
      cout << b[j] << " ";
    else
      cout << b[j] + (b[j] / s) + s << " ";
}
int main() {
  cin >> n >> m;
  mx = 0;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {
      cin >> w[i][j];
      mx = max(mx, w[i][j]);
    }
  a[1] = 0;
  for (j = 1; j <= m; j++) b[j] = w[1][j];
  for (i = 2; i <= n; i++) a[i] = w[i][1] - b[1];
  t = 0;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {
      c[i][j] = fabs(a[i] + b[j] - w[i][j]);
      if (c[i][j] != 0) t = 1;
    }
  if (t == 0) {
    vivod(10000000001);
    return 0;
  }
  k = 0;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) k = gcd(c[i][j], k);
  if (k <= mx) {
    cout << "NO";
    return 0;
  }
  vivod(k);
  return 0;
}
