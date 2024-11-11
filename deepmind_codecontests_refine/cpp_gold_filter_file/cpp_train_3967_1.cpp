#include <bits/stdc++.h>
using namespace std;
struct pp {
  long long x, y;
};
const int base = 1000 * 1000 * 1000;
const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
long long inf = 1e7;
double pi = 3.14159265359;
const int mod = 15e8 + 1;
long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long binpow(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res *= a, res %= mod;
    a *= a, a %= mod;
    n >>= 1;
  }
  return res;
}
long long t, n, ans, m, sum, cnt, maxx, minx = inf, maxy = maxx, miny = minx, x,
                                        y, z;
long long a[111111];
char c;
int main() {
  cin >> n >> m;
  for (long long i = 0; i < 1000; i++) cout << 2;
  cout << endl;
  for (long long j = 0; j < 1000; j++) {
    if (j == 999)
      cout << 8;
    else
      cout << 7;
  }
  return 0;
}
