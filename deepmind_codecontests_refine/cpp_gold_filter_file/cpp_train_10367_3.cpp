#include <bits/stdc++.h>
using namespace std;
const long long base = 1000000007;
const int maxn = 200005;
long long f, w, h, valid, total;
long long fac[maxn];
long long power(long long first, int n) {
  if (n == 0) return 1;
  long long j = power(first, n / 2);
  if (n & 1)
    return ((j * j) % base) * first % base;
  else
    return j * j % base;
}
long long C(long long n, long long k) {
  if (k > n) return 0;
  long long res;
  res = fac[n];
  res = res * power(fac[k], base - 2) % base;
  res = res * power(fac[n - k], base - 2) % base;
  return res;
}
long long distribute(long long ball, long long box, long long mh) {
  int i, j;
  ball -= box * mh;
  if (ball < 0) return 0;
  if (ball == 0) return 1;
  return C(ball + box - 1, box - 1);
}
int main() {
  int i, j;
  long long u, v;
  cin >> f >> w >> h;
  h++;
  if (w == 1) {
    if (h > 1)
      cout << 0;
    else if (f == 0)
      cout << 1;
    else
      cout << 1;
    return 0;
  } else if (w == 0) {
    cout << 1;
    return 0;
  }
  fac[0] = 1;
  for (i = 1; i <= 200002; i++) fac[i] = fac[i - 1] * i % base;
  for (u = 1; u <= w; u++) {
    v = C(f + 1, u);
    valid = (valid + v * distribute(w, u, h) % base) % base;
  }
  total = fac[f + w];
  total = total * power(fac[f], base - 2) % base;
  total = total * power(fac[w], base - 2) % base;
  cout << valid * power(total, base - 2) % base;
  return 0;
}
