#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
long long mpow(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n /= 2;
  }
  return res;
}
array<array<int, 100>, 100> a;
int det(int n) {
  long long res = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j)
      if (a[j][i]) {
        a[i].swap(a[j]);
        break;
      }
    if (!a[i][i]) return 0;
    res = res * a[i][i] % mod;
    long long mul = mpow(a[i][i], mod - 2);
    for (int j = i; j < n; ++j) {
      a[i][j] = a[i][j] * mul % mod;
    }
    for (int j = i + 1; j < n; ++j)
      if (a[j][i]) {
        long long mul = a[j][i];
        for (int l = i; l < n; ++l) {
          a[j][l] = (a[j][l] - a[i][l] * mul) % mod;
        }
      }
  }
  if (res < 0) res += mod;
  return res;
}
vector<long long> mul(vector<long long> x, vector<long long> y) {
  vector<long long> res(x.size() + y.size() - 1);
  for (int i = 0; i < x.size(); ++i)
    for (int j = 0; j < y.size(); ++j) {
      res[i + j] = (res[i + j] + x[i] * (long long)y[j]) % mod;
    }
  return res;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int> > e;
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    --a;
    --b;
    e.emplace_back(a, b);
  }
  vector<long long> v(n);
  for (int x = 0; x < n; ++x) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) a[i][j] = -1;
      a[i][i] = n - 1;
    }
    for (pair<int, int> p : e) {
      a[p.first][p.first] += x - 1;
      if (p.second < n - 1) {
        a[p.second][p.first] -= x - 1;
        a[p.first][p.second] -= x - 1;
        a[p.second][p.second] += x - 1;
      }
    }
    v[x] = det(n - 1);
  }
  vector<long long> p(n);
  for (int i = 0; i < n; ++i) {
    vector<long long> x(1, v[i]);
    long long d = 1;
    for (int j = 0; j < n; ++j)
      if (i != j) {
        d = d * (i - j);
      }
    x[0] = x[0] * mpow(d, mod - 2) % mod;
    for (int j = 0; j < n; ++j)
      if (i != j) {
        vector<long long> y(2, 1);
        y[0] = -j;
        x = mul(x, y);
      }
    for (int i = 0; i < p.size(); ++i) {
      p[i] = (p[i] + x[i]) % mod;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (p[i] < 0) p[i] += mod;
    cout << p[i] << ' ';
  }
  cout << endl;
  return 0;
}
