#include <bits/stdc++.h>
using namespace std;
const long long modu = 1e9 + 7;
const long long maxn = 1e6 + 9;
long long n, k;
long long powmod(long long a, long long n) {
  if (n == 0) return 1;
  long long r = powmod(a, n / 2);
  r = (r * r) % modu;
  if (n % 2) r = (r * a) % modu;
  return r;
}
void gcd(long long a, long long b, long long& x, long long& y, long long& d) {
  if (!b)
    x = 1, y = 0, d = a;
  else {
    gcd(b, a % b, y, x, d);
    y -= (a / b) * x;
  }
}
long long modReverse(long long a) {
  long long x, y, d;
  gcd(a, modu, x, y, d);
  return (x % modu + modu) % modu;
}
long long a[maxn], s[maxn];
void update(long long& a, long long b) {
  a = (a * b) % modu;
  a = (a + modu) % modu;
}
int main(int argc, char* argv[]) {
  cin >> n >> k;
  for (int i = 1; i <= k + 1; i++) a[i] = a[i - 1] + powmod(i, k);
  if (n < k + 2) {
    cout << a[n] << endl;
    exit(0);
  }
  long long i1 = 1;
  for (int i = 0; i <= k + 1; i++) update(i1, (n - i));
  s[0] = 1;
  for (int i = 1; i <= k + 1; i++) s[i] = s[i - 1], update(s[i], i);
  long long res = 0;
  for (int i = 0; i <= k + 1; i++) {
    long long now = 1;
    update(now, s[i]);
    update(now, n - i);
    update(now, modu + s[k + 1 - i] * ((k + 1 - i) % 2 ? -1 : 1));
    now = modReverse(now);
    update(now, a[i]);
    update(now, i1);
    res = (res + now) % modu;
  }
  cout << res << endl;
  return 0;
}
