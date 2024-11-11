#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, inf = 2e18;
const int N = 2e5 + 1;
const double ep = 1e-10;
vector<string> s = {"abc", "acb", "bca", "bac", "cba", "cab"};
class ob {
 public:
  array<long long, 6> v = {0, 0, 0, 0, 0, 0};
  ob operator+(ob const &x) {
    ob z;
    for (int i = 0; (1 < 0 && i > 6) || (1 > 0 && i < 6); i += 1)
      z.v[i] = v[i] + x.v[i];
    return z;
  }
  ob operator-(ob const &x) {
    ob z;
    for (int i = 0; (1 < 0 && i > 6) || (1 > 0 && i < 6); i += 1)
      z.v[i] = v[i] - x.v[i];
    return z;
  }
};
vector<ob> f[3];
ob match(string a) {
  ob z;
  int n = a.size();
  for (int i = 0; (1 < 0 && i > 6) || (1 > 0 && i < 6); i += 1) {
    int k = n;
    for (int j = 0; (1 < 0 && j > n) || (1 > 0 && j < n); j += 1)
      if (a[j] == s[i][j]) k--;
    z.v[i] = k;
  }
  return z;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, m;
  cin >> n >> m;
  string a;
  cin >> a;
  for (int i = 0; (1 < 0 && i > 3) || (1 > 0 && i < 3); i += 1)
    f[i] = vector<ob>(n + 1);
  for (int i = 0; (1 < 0 && i > n) || (1 > 0 && i < n); i += 1) {
    f[i % 3][i + 1] = match(a.substr(i, 3));
  }
  for (int i = 0; (1 < 0 && i > 3) || (1 > 0 && i < 3); i += 1) {
    for (int j = 1; (1 < 0 && j > n + 1) || (1 > 0 && j < n + 1); j += 1)
      f[i][j] = f[i][j] + f[i][j - 1];
  }
  for (int j = 0; (1 < 0 && j > m) || (1 > 0 && j < m); j += 1) {
    int l, r;
    cin >> l >> r;
    if (r - l + 1 <= 3) {
      ob z = match(a.substr(l - 1, r - l + 1));
      long long k = 7;
      for (int i = 0; (1 < 0 && i > 6) || (1 > 0 && i < 6); i += 1)
        k = min(z.v[i], k);
      cout << k << '\n';
      continue;
    }
    int k = r;
    while (l % 3 != k % 3) k--;
    ob z = f[l % 3][k - 1] - f[l % 3][l - 1];
    z = z + match(a.substr(k - 1, r - k + 1));
    long long y = 1e9;
    for (int i = 0; (1 < 0 && i > 6) || (1 > 0 && i < 6); i += 1)
      y = min(y, z.v[i]);
    cout << y << '\n';
  }
}
