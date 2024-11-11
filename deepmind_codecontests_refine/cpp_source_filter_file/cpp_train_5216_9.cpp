#include <bits/stdc++.h>
using namespace std;
const int maxn = 1 << 21;
const int N = int(1e5);
const long long mod = int(1e9) + 7;
const long long inf = 1e18;
const double PI = 3.1415926536;
inline int Set(int n, int pos) { return n = n | 1 << pos; }
inline bool check(int n, int pos) { return n & 1 << pos; }
inline int Reset(int n, int pos) { return n = n & ~(1 << pos); }
inline int lastbit(int n) { return n & (-n); }
inline long long MM(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  long long c = (a * b) % mod;
  return c;
}
inline long long AM(long long a, long long b) {
  a = (a + mod) % mod;
  b = (b + mod) % mod;
  long long c = (a + b) % mod;
  return c;
}
inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
inline int lcm(int a, int b) { return (a * b) / gcd(a, b); }
inline long long power(long long a, long long b) {
  long long ans = 1;
  a = a % mod;
  while (b) {
    if (b & 1) ans = (ans * a) % mod;
    b >>= 1;
    a = (a * a) % mod;
  }
  return ans;
}
inline long long invmod(long long a) {
  long long ans = power(a, mod - 2);
  return ans;
}
inline long long mulmod(long long a, long long b, long long c = mod) {
  long long x = 0, y = a % c;
  while (b > 0) {
    if (b % 2) x = (x + y) % c;
    y = (y * 2) % c;
    b >>= 1;
  }
  return x % c;
}
inline long long Largepower(long long a, long long b, long long c = mod) {
  long long x = 1, y = a % c;
  while (b > 0) {
    if (b & 1) x = mulmod(x, y, c);
    y = mulmod(y, y, c);
    b >>= 1;
  }
  return x;
}
inline long long Egcd(long long a, long long b, long long *x, long long *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  long long x1, y1;
  long long gcd = Egcd(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
inline int bs(int arr[], int l, int r, int item) {
  if (l == r) {
    if (arr[l] == item)
      return r;
    else
      return -1;
  }
  if (item <= arr[(l + r) / 2])
    return bs(arr, l, (l + r) / 2, item);
  else
    return bs(arr, (l + r) / 2 + 1, r, item);
}
inline long long nCrMod(long long n, long long r) {
  if (r > n / 2) r = n - r;
  long long ans = 1;
  for (long long i = 1; i <= r; i++) {
    ans = (ans % mod * (n - r + i + mod) % mod) % mod;
    ans = (ans % mod * invmod(i) % mod) % mod;
  }
  return ans % mod;
}
inline long long nCr(long long n, long long r) {
  if (r > n / 2) r = n - r;
  long long ans = 1;
  for (long long i = 1; i <= r; i++) {
    ans = (ans * (n - r + i));
    ans /= i;
  }
  return ans;
}
inline void fastin(int &x) {
  x = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - '0';
    c = getchar();
  }
  return;
}
int leap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int nleap[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
long long arr[2 * N + 1];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  int ans = 1, prev = 0;
  for (int i = 1; i < n; i++) {
    if (arr[i] < 2 * arr[i - 1]) {
      ans = max(ans, i - prev + 1);
      continue;
    } else {
      prev = i;
    }
  }
  cout << ans << endl;
  return 0;
}
