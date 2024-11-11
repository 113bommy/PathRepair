#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long ret = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ret = (ret << 1) + (ret << 3) + c - 48;
    c = getchar();
  }
  return ret * f;
}
const int maxn = 1e6;
const long long mod = 1e9 + 7;
int a[maxn], cnt;
bool b[maxn] = {1, 1};
long long pow(long long a, long long n) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = ans * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return ans;
}
long long get(long long n, long long j) {
  long long ans = 0, x = 0;
  x = n / j;
  while (x) {
    ans += x;
    x /= j;
  }
  return ans;
}
int main() {
  long long x = read(), n = read();
  long long ans = 1;
  for (long long j = 2; j * j < x; j++) {
    if (x % j == 0) {
      ans = ans * pow(j, get(n, j)) % mod;
      while (x % j == 0) x /= j;
    }
  }
  if (x > 1) ans = ans * pow(x, get(n, x)) % mod;
  cout << ans << endl;
}
