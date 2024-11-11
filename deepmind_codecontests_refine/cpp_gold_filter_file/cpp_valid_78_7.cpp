#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
const long long N = 4e6 + 6;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long powmod(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
long long readn() {
  long long sum = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    sum = sum * 10 + (ch - '0');
    ch = getchar();
  }
  return sum * f;
}
long long t, l, r, p;
int main() {
  t = readn();
  while (t--) {
    l = readn();
    r = readn();
    p = r - l;
    if (p >= l)
      cout << r / 2 - (r % 2 == 0);
    else
      cout << p;
    cout << endl;
  }
}
