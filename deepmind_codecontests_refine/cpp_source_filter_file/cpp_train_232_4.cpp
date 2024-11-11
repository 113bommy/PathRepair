#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const long long Inf = 0x7f7f7f7f7f7f7f;
const long long mod = 1e6 + 3;
bool isPowerOfTwo(int n) { return n > 0 && (n & (n - 1)) == 0; }
int modPowerOfTwo(int x, int mod) { return x & (mod - 1); }
int getBit(int a, int b) { return (a >> b) & 1; }
int Max(int a, int b) { return b & ((a - b) >> 31) | a & (~(a - b) >> 31); }
int Min(int a, int b) { return a & ((a - b) >> 31) | b & (~(a - b) >> 31); }
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
int Abs(int n) { return (n ^ (n >> 31)) - (n >> 31); }
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res % mod;
}
void extend_gcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1, y = 0;
    return;
  }
  extend_gcd(b, a % b, x, y);
  long long tmp = x;
  x = y;
  y = tmp - (a / b) * y;
}
long long mod_inverse(long long a, long long m) {
  long long x, y;
  extend_gcd(a, m, x, y);
  return (m + x % m) % m;
}
long long eulor(long long x) {
  long long cnt = x;
  long long ma = sqrt(x);
  for (int i = 2; i <= ma; i++) {
    if (x % i == 0) cnt = cnt / i * (i - 1);
    while (x % i == 0) x /= i;
  }
  if (x > 1) cnt = cnt / x * (x - 1);
  return cnt;
}
int t, n, a[maxn], b[maxn];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  if (n == 1) {
    cout << 1 << " " << 1 << '\n';
    cout << -a[1] << '\n';
    for (int i = 2; i <= 3; i++) {
      cout << 1 << " " << 1 << '\n';
      cout << 0 << '\n';
    }
    return 0;
  }
  cout << 1 << " " << n - 1 << "\n";
  for (int i = 1; i <= n - 1; i++) {
    cout << (n - 1) * a[i] << " ";
    a[i] += (n - 1) * a[i];
  }
  cout << endl;
  cout << n << " " << n << '\n';
  cout << -a[n] << '\n';
  cout << 1 << " " << n << '\n';
  for (int i = 1; i < n; i++) cout << -a[i] << " ";
  cout << 0;
}
