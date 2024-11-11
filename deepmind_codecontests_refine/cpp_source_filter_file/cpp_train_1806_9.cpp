#include <bits/stdc++.h>
using namespace std;
int n, m, T;
int k, p;
long long l, r;
int _pow(const int a, const long long l, const int p) {
  int x = 1, y = a;
  for (long long e = l; e > 0; e >>= 1) {
    if (e & 1) x = (long long)x * y % p;
    y = (long long)y * y % p;
  }
  return x;
}
int Gans() {
  scanf("%d%I64d%I64d%d", &k, &l, &r, &p);
  if (p == 2) return (k & 1) ? 0 : 1;
  if (k % p == 0) return (k & 1) ? _pow((p + 1) / 2, r - l, p) : 1;
  int a = _pow(2, l, p - 1), A, B;
  A = _pow(k, a, p);
  if (A == 1) return (k & 1) ? 2 : _pow(2, r - l + 1, p);
  a = _pow(2, r - l + 1, p - 1);
  B = _pow(A, a, p) - 1;
  B = (long long)B * _pow(A - 1, p - 2, p) % p;
  if (k & 1) B = (long long)B * _pow((p + 1) / 2, r - l, p);
  return B;
}
int main() {
  for (scanf("%d", &T); T--;) printf("%d\n", Gans());
  return 0;
}
