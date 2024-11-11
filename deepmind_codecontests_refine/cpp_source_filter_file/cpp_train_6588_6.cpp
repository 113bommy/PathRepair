#include <bits/stdc++.h>
using namespace std;
double pi = acos(-1);
long long i, j;
long long mx = (1ll << 48) - 1, fb[100];
bool ff[100010];
long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
const long long mod = 1e9 + 7;
const long long Max = 1e9 + 7;
long long pow_mod(long long n, long long k) {
  long long res = 1;
  n = n % mod;
  while (k > 0) {
    if (k & 1) res = res * n % mod;
    n = n * n % mod;
    k >>= 1;
  }
  return res % mod;
}
void exgcd(int a, int b, int &d, int &x, int &y) {
  if (!b) {
    d = a;
    x = 1;
    y = 0;
  } else {
    exgcd(b, a % b, d, y, x);
    y -= x * (a / b);
  }
}
long long ans = 0, n, m, l, r, k, x, y, w = 0, a[200007], b[200005], c[200005],
          zd, zx;
string ch;
bool cmp(long long a, long long b) { return a > b; }
void gg() {
  cin >> n >> x;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i], c[i] = 0;
  for (int i = 0; i < n; i++) {
    bool ff = 0;
    for (int j = n - 1; j >= 0; j--) {
      if (c[i]) continue;
      if (a[i] + b[j] > x)
        continue;
      else {
        c[j] = 1;
        ff = 1;
        break;
      }
    }
    if (ff == 0) {
      puts("NO");
      return;
    }
  }
  puts("YES");
}
int main() {
  long long t;
  scanf("%lld", &t);
  while (t--) gg();
}
