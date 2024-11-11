#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const int INF = 100000000;
const int mod = 1000 * 1000 * 1000 + 7;
const double PI = 3.1415926535897932;
double sqr(double first) { return first * first; };
long double sqr(long double first) { return first * first; };
long long sqr(long long first) { return first * first; };
long long sqr(int first) { return first * 1LL * first; };
long long bpm(long long a, long long n = -2, long long m = mod) {
  n = n >= 0 ? n : m + n;
  long long r = 1;
  while (n) {
    if (n & 1) r = (r * a) % m;
    a = (a * a) % m;
    n >>= 1;
  }
  return r;
}
const int N = 5001;
const int END = 1000 * 1000 * 1001;
long long gcd(long long a, long long b) {
  while (b) a %= b, swap(a, b);
  return a;
};
int l[N], r[N];
int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  int xl, xr;
  cin >> xl;
  xr = xl;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    ;
    if (l <= xr && r >= xl) {
      xl = max(xl, l);
      xr = min(xr, r);
    } else if (r < xl) {
      ans += xl - r;
      xr = xl;
      xl = r;
    } else {
      ans += l - xr;
      xl = xr;
      xr = l;
    }
  }
  cout << ans << endl;
  return 0;
}
