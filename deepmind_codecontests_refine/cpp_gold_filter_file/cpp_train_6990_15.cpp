#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1, -1, -1, 0, 1, -1, 0, 1};
int kx8[] = {1, 1, 2, 2, -1, -1, -2, -2};
int ky8[] = {2, -2, 1, -1, 2, -2, 1, -1};
long long bigmod(long long a, long long b, long long c) {
  if (b == 0) return 1 % c;
  long long x = bigmod(a, b / 2, c);
  x = (x * x) % c;
  if (b % 2 == 1) x = (x * a) % c;
  return x;
}
long long mod_inverse(long long a, long long mod) {
  return bigmod(a, mod - 2, mod);
}
int a[505][505];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  vector<int> v;
  for (int i = 0; i < (n); i++) v.push_back(1);
  int xr = 0;
  int i = 1;
  for (auto x : v) {
    xr ^= a[i][1];
    i++;
  }
  if (xr) {
    cout << "TAK" << endl;
    for (auto x : v) cout << x << " ";
    cout << endl;
    return 0;
  }
  bool flg = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 2; j <= m; j++) {
      if (a[i][j] != a[i][1]) {
        flg = 1;
        v[i - 1] = j;
        break;
      }
    }
    if (flg) break;
  }
  if (!flg)
    cout << "NIE" << endl;
  else {
    cout << "TAK" << endl;
    for (auto x : v) cout << x << " ";
    cout << endl;
  }
  return 0;
}
