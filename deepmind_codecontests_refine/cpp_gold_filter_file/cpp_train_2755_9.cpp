#include <bits/stdc++.h>
using namespace std;
long long prck(long long n) {
  long long f = 1;
  if (n == 1)
    f = 0;
  else if (n == 2)
    f = 1;
  else if (n % 2 == 0)
    f = 0;
  else {
    long long i;
    for (i = 3; (i * i <= n) && (f == 1); i += 2) {
      if (n % i == 0) f = 0;
    }
  }
  return f;
}
long long nCr(long long n, long long r) {
  long long i, res = 1;
  if (r > n - r) r = n - r;
  for (i = 0; i < r; ++i) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long btod(string n) {
  long long lg = n.length();
  long long i, val = 0, bs = 1;
  for (i = lg - 1; i >= 0; i--) {
    if (n[i] == '1') {
      val += bs;
    }
    bs *= 2;
  }
  return val;
}
long long ston(string s) {
  long long val = 0, bs = 1;
  long long sl = s.length();
  sl--;
  while (sl >= 0) {
    val += ((s[sl] - 48) * bs);
    bs *= 10;
    sl--;
  }
  return val;
}
long long nCrModpDP(long long n, long long r, long long p) {
  long long i, j, C[r + 1];
  memset(C, 0, sizeof(C));
  C[0] = 1;
  for (i = 1; i <= n; i++) {
    for (j = min(i, r); j > 0; j--) {
      C[j] = (C[j] + C[j - 1]) % p;
    }
  }
  return C[r];
}
long long nCrModpLucas(long long n, long long r, long long p) {
  if (r == 0) return 1;
  long long ni = n % p, ri = r % p;
  return (nCrModpLucas(n / p, r / p, p) * nCrModpDP(ni, ri, p)) % p;
}
long long pwr(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long modInverse(long long n, long long p) { return pwr(n, p - 2, p); }
long long nCrModPFermat(long long n, long long r, long long p,
                        long long fac[]) {
  if (r == 0) return 1;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, i;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  int mn = 1001, flg = 0;
  i = 2;
  while (i < n - 1) {
    if (a[i] - a[i - 2] < mn) {
      mn = a[i] - a[i - 2];
      flg = i - 1;
    }
    i++;
  }
  if (flg == 0)
    cout << a[2] - a[0] << "\n";
  else {
    for (i = 1; i < n; i++) {
      if (i != flg) {
        if (a[i] - a[i - 1] > mn) mn = a[i] - a[i - 1];
      } else {
        if (a[i + 1] - a[i - 1] > mn) mn = a[i] - a[i - 1];
        i++;
      }
    }
    cout << mn << "\n";
  }
  return 0;
}
