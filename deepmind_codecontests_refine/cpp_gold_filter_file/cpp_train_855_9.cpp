#include <bits/stdc++.h>
using namespace std;
const int MAX = 400000;
const long long M = 998244353;
long long sil[MAX + 5];
long long n, k;
long long pot(long long x, long long y) {
  long long w = 1;
  while (y > 0) {
    if (y % 2 == 1) w = (w * x) % M;
    x = (x * x) % M;
    y /= 2;
  }
  return w;
}
long long odw(long long x) { return pot(x, M - 2); }
long long binom(long long n, long long k) {
  long long w = sil[n];
  w = (w * odw(sil[n - k])) % M;
  w = (w * odw(sil[k])) % M;
  return w;
}
int main() {
  sil[0] = 1;
  for (long long i = 1; i <= MAX; i++) sil[i] = (sil[i - 1] * i) % M;
  cin >> n >> k;
  if (k == 0) {
    cout << sil[n];
    return 0;
  }
  if (k > n - 1) {
    cout << 0;
    return 0;
  }
  long long w = n - k;
  long long wynik = 0;
  for (long long i = 1; i <= w; i++) {
    long long sign = 1;
    if (i % 2 != w % 2) sign = -1;
    wynik += sign * ((binom(w, i) * pot(i, n)) % M);
    if (wynik < 0) wynik += M * M;
    wynik %= M;
  }
  cout << (((2LL * binom(n, w)) % M) * wynik) % M;
  return 0;
}
