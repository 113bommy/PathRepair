#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000,100000000000")
using namespace std;
const long long inf = 2e18 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-7;
const double PI = 2 * acos(0.0);
const double E = 2.71828;
long long m, l, r, k;
long long b[2][2];
struct matrix {
  long long a[2][2];
  void mul(matrix x) {
    for (int(i) = 0; (i) < (2); ++(i))
      for (int(j) = 0; (j) < (2); ++(j)) b[i][j] = a[i][j], a[i][j] = 0;
    for (int(i) = 0; (i) < (2); ++(i))
      for (int(j) = 0; (j) < (2); ++(j))
        for (int(w) = 0; (w) < (2); ++(w))
          a[i][j] = (a[i][j] + b[i][w] * x.a[w][j]) % m;
  }
  void add(matrix x) {
    for (int(i) = 0; (i) < (2); ++(i))
      for (int(j) = 0; (j) < (2); ++(j)) a[i][j] = (a[i][j] + x.a[i][j]) % m;
  }
};
int go(long long x) {
  if (!x) return 0;
  --x;
  matrix a, res;
  a.a[0][0] = 1;
  a.a[1][0] = 1;
  a.a[0][1] = 1;
  a.a[1][1] = 0;
  res.a[0][0] = 1;
  res.a[1][0] = 0;
  res.a[0][1] = 0;
  res.a[1][1] = 1;
  while (x) {
    if (x & 1) {
      res.mul(a);
    }
    a.mul(a);
    x >>= 1LL;
  }
  return res.a[0][0];
}
int main(void) {
  cin >> m >> l >> r >> k;
  long long id = 0;
  for (long long i = 1; i <= min(r, 10000000LL); ++i) {
    long long another = r / i;
    if (r / i - (l - 1) / i >= k) id = max(id, i);
    if (r / another - (l - 1) / another >= k) id = max(id, another);
  }
  cout << go(id) << "\n";
  return 0;
}
