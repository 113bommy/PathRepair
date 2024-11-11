#include <bits/stdc++.h>
const long long int oo = (long long int)1e18 + 10;
const int inf = 0x3f3f3f3f;
const double PHI = ((sqrt(5) + 1) / 2);
using namespace std;
long long int CEIL(long long int, long long int);
long long int FLOOR(long long int a, long long int b) {
  if (b < 0)
    return FLOOR(-a, -b);
  else if (a < 0)
    return -1 * CEIL(-a, b);
  else
    return a / b;
}
long long int CEIL(long long int a, long long int b) {
  if (b < 0)
    return CEIL(-a, -b);
  else if (a < 0)
    return -1 * FLOOR(-a, b);
  else
    return (a + b - 1) / b;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
long long int exgcd(long long int a, long long int b, long long int &x,
                    long long int &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long int xx, yy, g = exgcd(b % a, a, xx, yy);
  x = yy - (b / a) * xx;
  y = xx;
  return g;
}
int bin1(long long int x) {
  int r = 0;
  while (x) {
    r++;
    x &= x - 1;
  }
  return r;
}
long long int power(long long int b, long long int e) {
  if (e == 0) return 1;
  if (e % 2 == 0) return power(b * b, e / 2);
  return b * power(b * b, e / 2);
}
double powerf(double b, int e) {
  if (e == 0) return 1;
  if (e % 2 == 0)
    return powerf(b * b, e / 2);
  else {
    if (e > 0)
      return b * powerf(b * b, e / 2);
    else
      return powerf(b * b, e / 2) / b;
  }
}
long long int modpow(long long int b, long long int e, long long int m) {
  long long int r = 1;
  b = b % m;
  while (e > 0) {
    if (e % 2 == 1) r = (r * b) % m;
    e /= 2;
    b = (b * b) % m;
  }
  return r;
}
long long int modinverse(long long int a, long long int mod) {
  return modpow(a, mod - 2, mod);
}
long long int modinverse2(long long int a, long long int m) {
  long long int x, y;
  exgcd(a, m, x, y);
  while (x < 0) x += m;
  return x;
}
long long int nCrmod(long long int n, long long int r, long long int m) {
  if (r > n) r = n - r;
  long long int res = 1;
  for (long long int i = r; i >= 1; i--) {
    res = (res * (n - i + 1)) % m;
    res = (res * modinverse(i, m));
  }
  return res;
}
long long int nCr(long long int n, long long int r) {
  if (r > n) r = n - r;
  long long int res = 1;
  for (long long int i = r; i >= 1; i--) {
    res *= (n - i + 1);
    res /= i;
  }
  return res;
}
long long int totient(long long int n) {
  long long int res = n, p;
  for (p = 2; p * p <= n; p++) {
    if (n % p == 0) {
      while (n % p == 0) n /= p;
      res -= res / p;
    }
  }
  if (n > 1) res -= res / n;
  return res;
}
bool isprime(long long int x) {
  if (x == 1) return false;
  for (long long int i = 2; i * i <= x; i++)
    if (x % i == 0) return false;
  return true;
}
bool isvowel(char c) {
  if (isupper(c)) c = tolower(c);
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
bool istriangle(long long int a, long long int b, long long int c) {
  return (a + b > c) && (a + c > b) && (b + c > a);
}
long long int stringmod(string s, long long int mod) {
  long long int res = 0;
  for (unsigned int i = 0; i < s.size(); i++)
    res = (res * 10 + s[i] - '0') % mod;
  return res;
}
long long int powinfact(long long int n, long long int p) {
  long long int res = 0, pw = p;
  while (n >= pw) {
    res += (n / pw);
    pw *= p;
  }
  return res;
}
vector<vector<long long int> > matrixmultiply(vector<vector<long long int> > A,
                                              vector<vector<long long int> > B,
                                              long long int n) {
  vector<vector<long long int> > C(2, vector<long long int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++) C[i][j] = (C[i][j] + A[i][k] * B[k][j]);
  return C;
}
vector<vector<long long int> > modmatrixmultiply(
    vector<vector<long long int> > A, vector<vector<long long int> > B,
    long long int n, long long int mod) {
  vector<vector<long long int> > C(2, vector<long long int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++) C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
  return C;
}
vector<vector<long long int> > powermatrix(vector<vector<long long int> > A,
                                           long long int exp, long long int n) {
  if (exp == 1) return A;
  if (exp % 2) return matrixmultiply(A, powermatrix(A, exp - 1, n), n);
  vector<vector<long long int> > X = powermatrix(A, exp / 2, n);
  return matrixmultiply(X, X, n);
}
vector<vector<long long int> > modpowmatrix(vector<vector<long long int> > A,
                                            long long int exp, long long int n,
                                            long long int mod) {
  if (exp == 1) return A;
  if (exp % 2)
    return modmatrixmultiply(A, modpowmatrix(A, exp - 1, n, mod), n, mod);
  vector<vector<long long int> > X = modpowmatrix(A, exp / 2, n, mod);
  return modmatrixmultiply(X, X, n, mod);
}
long long int merge(long long int a[], long long int l, long long int m,
                    long long int r) {
  long long int i = l, j = m + 1, k = 0, inv_cnt = 0, temp[r - l + 1];
  while (i <= m && j <= r) {
    if (a[i] <= a[j])
      temp[k++] = a[i++];
    else {
      temp[k++] = a[j++];
      inv_cnt += (m - i + 1);
    }
  }
  while (i <= m) temp[k++] = a[i++];
  while (j <= r) temp[k++] = a[j++];
  for (i = l; i <= r; i++) a[i] = temp[i - l];
  return inv_cnt;
}
long long int mergesort(long long int a[], long long int l, long long int r) {
  long long int inv_count = 0;
  if (l < r) {
    long long int m = (l + r) / 2;
    inv_count += mergesort(a, l, m);
    inv_count += mergesort(a, m + 1, r);
    inv_count += merge(a, l, m, r);
  }
  return inv_count;
}
double dist(long long int x1, long long int y1, long long int x2,
            long long int y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
void pre() {}
void gcj() {
  long long int t;
  cin >> t;
  for (long long int c = 1; c <= t; c++) {
    cout << "Case #" << c << ": " << endl;
  }
}
void judge() {
  long long int n;
  cin >> n;
  vector<long long int> v(n);
  for (long long int i = 0; i < n; i++) cin >> v[i];
  for (long long int i = 0; i < n; i++)
    if (i % 2 == 0) swap(v[i], v[n - i - 1]);
  for (long long int i = 0; i < n; i++) cout << v[i] << " ";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  pre();
  long long int tt = 1;
  while (tt--) {
    judge();
  }
  return 0;
}
