#include <bits/stdc++.h>
using namespace std;
class mat {
 public:
  long long a, b, c, d;
};
mat a;
long long n, k, l, m, step, res;
long long power(long long a, long long b);
mat mult(mat a, mat b);
mat power1(mat a, long long n);
int main() {
  cin >> n >> k >> l >> m;
  step = power(2, n);
  a.a = a.b = a.c = 1;
  a.d = 0;
  a = power1(a, n + 1);
  res = 1;
  while (l > 0) {
    if (k % 2)
      res = (res * ((step + m - a.a) % m)) % m;
    else
      res = (res * a.a) % m;
    k /= 2;
    l--;
  }
  if (k > 0)
    cout << 0;
  else
    cout << res % m;
  return 0;
}
long long power(long long a, long long b) {
  long long res;
  if (b == 0) return 1;
  res = power(a, b / 2) % m;
  res = (res * res) % m;
  if (b % 2) res = (res * a) % m;
  return res;
}
mat mult(mat a, mat b) {
  mat res;
  res.a = (a.a * b.a + a.b * b.c) % m;
  res.b = (a.a * b.b + a.b * b.d) % m;
  res.c = (a.c * b.a + a.d * b.c) % m;
  res.d = (a.c * b.b + a.d * b.d) % m;
  return res;
}
mat power1(mat a, long long n) {
  mat res, a1;
  if (n == 0) {
    res.a = res.d = 1;
    res.b = res.c = 0;
    return res;
  }
  res = power1(a, n / 2);
  res = mult(res, res);
  if (n % 2) {
    a1.a = a1.b = a1.c = 1;
    a1.d = 0;
    res = mult(res, a1);
  }
  return res;
}
