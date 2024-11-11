#include <bits/stdc++.h>
using namespace std;
long long mul(long long a, long long b, long long p = 1000000007) {
  return ((a % p) * (b % p)) % p;
}
long long add(long long a, long long b, long long p = 1000000007) {
  return (a % p + b % p) % p;
}
void input(long long a[], long long sz) {
  for (long long i = 0; i < sz; i++) cin >> a[i];
}
void print(long long a[], long long sz) {
  for (long long i = 0; i < sz; i++) {
    if (i == sz - 1)
      cout << a[i] << "\n";
    else
      cout << a[i] << " ";
  }
}
long long maxr(long long a[], long long sz) {
  long long ma;
  for (long long i = 0; i < sz; i++) {
    if (i == 0)
      ma = a[i];
    else if (a[i] > ma)
      ma = a[i];
  }
  return ma;
}
long long minr(long long a[], long long sz) {
  long long mi;
  for (long long i = 0; i < sz; i++) {
    if (i == 0)
      mi = a[i];
    else if (a[i] < mi)
      mi = a[i];
  }
  return mi;
}
long long isprm(long long n) {
  if (n <= 1) return 0;
  if (n <= 3) return 1;
  if (n % 2 == 0 || n % 3 == 0) return 0;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return 0;
  return 1;
}
long long b_srch(long long arr[], long long l, long long r, long long x) {
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (arr[m] == x) return m;
    if (arr[m] < x)
      l = m + 1;
    else
      r = m - 1;
  }
  return -1;
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long modInverse(long long n, long long p) { return power(n, p - 2, p); }
long long nCrModPFermat(long long n, long long r, long long p) {
  if (r == 0) return 1;
  long long fac[n + 1];
  fac[0] = 1;
  for (long long i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long h, w, mh = 0, mw = 0, x = 0, y = 0;
  cin >> h >> w;
  long long p1 = log2(h), p2 = log2(w);
  for (long long i = p1; i >= 0; i--) {
    long long ht = pow(2, i);
    long long r = 1.25 * ht;
    long long l = ceil(0.8 * ht);
    if (w > r)
      mw = r;
    else if (w >= l)
      mw = w;
    if (mw != 0) {
      mh = ht;
      break;
    }
  }
  for (long long i = p2; i >= 0; i--) {
    long long ht = pow(2, i);
    long long r = 1.25 * ht;
    long long l = ceil(0.8 * ht);
    if (w > r)
      x = r;
    else if (w >= l)
      x = w;
    if (x != 0) {
      y = ht;
      break;
    }
  }
  long long ar1 = mh * mw, ar2 = x * y;
  if (ar1 > ar2) {
    cout << mh << " " << mw << "\n";
  } else if (ar1 == ar2) {
    if (x > mh)
      cout << x << " " << y << "\n";
    else
      cout << mh << " " << mw << "\n";
  } else if (ar1 < ar2) {
    cout << x << " " << y << "\n";
  }
  return 0;
}
