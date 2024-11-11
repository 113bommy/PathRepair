#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
bool isPowerOfTwo(int x) { return x && (!(x & (x - 1))); }
void fast() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int modInverse(long long int n, long long int p) {
  return power(n, p - 2, p);
}
long long int ncr(long long int n, long long int r, long long int p) {
  if (r == 0) return 1;
  long long int fac[n + 1];
  fac[0] = 1;
  for (long long int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
int main() {
  long int n;
  cin >> n;
  string s;
  cin >> s;
  string a[6];
  long int b[6];
  for (long i = 0; i < 6; i++) {
    a[i] = "";
    b[i] = 0;
  }
  string p = "GRB";
  string q = "GBR";
  for (long i = 0; i < 3; i++) {
    long int k = i;
    for (long j = 0; j < n; j++) {
      a[i] += p[k % 3];
      k++;
    }
  }
  for (int i = 3; i < 6; i++) {
    long int k = i % 3;
    for (long j = 0; j < n; j++) {
      a[i] += p[k % 3];
      k++;
    }
  }
  for (long i = 0; i < n; i++) {
    for (long j = 0; j < 6; j++) {
      if (a[j][i] != s[i]) {
        b[j]++;
      }
    }
  }
  long int x = 1000000007;
  for (long i = 0; i < 6; i++) {
    x = min(x, b[i]);
  }
  cout << x << '\n';
  for (long i = 0; i < 6; i++) {
    if (b[i] == x) {
      cout << a[i] << '\n';
      return 0;
    }
  }
}
