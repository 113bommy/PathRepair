#include <bits/stdc++.h>
using namespace std;
long long x, y, i, j, k, l, r, m, s, t, n, a[1323456], b[323456], z, d[322222],
    c[323456], f[112345], g[123456];
string q, qq;
double ll, ss;
pair<long long, long long> p[345678];
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    p[i].first = a[i];
    p[i].second = i;
  }
  sort(p, p + n);
  k = (n - 1) / 3;
  t = (2 * n - 1) / 3;
  for (i = 0; i <= k; i++) {
    c[p[i].second] = i;
    d[p[i].second] = p[i].first - i;
  }
  for (i = k + 1; i <= t; i++) {
    d[p[i].second] = i;
    c[p[i].second] = p[i].first - i;
  }
  for (i = t + 1; i < n; i++) {
    d[p[i].second] = n - i - 1;
    c[p[i].second] = p[i].first - n + i + 1;
  }
  cout << "YES" << endl;
  for (i = 0; i < n; i++) cout << c[i] << ' ';
  cout << endl;
  for (i = 0; i < n; i++) cout << d[i] << ' ';
  return 0;
}
