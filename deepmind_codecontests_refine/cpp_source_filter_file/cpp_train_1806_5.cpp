#include <bits/stdc++.h>
using namespace std;
bool debug;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;
int test;
long long k, l, r, p;
long long pot(long long a, long long b, long long mod) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b /= 2;
  }
  return res;
}
int main(int argc, char* argv[]) {
  debug = argc > 1;
  scanf("%d", &test);
  while (test--) {
    scanf("%lld%lld%lld%lld", &k, &l, &r, &p);
    if (p == 2) {
      puts((k & 1) ? "0" : "1");
    } else {
      long long x;
      if (k % p == 0)
        x = 0;
      else
        x = pot(k % p, pot(2 % (p - 1), l, p - 1), p);
      long long g;
      if (x == 1)
        g = pot(2, r - l + 1, p);
      else {
        if (x == 0)
          g = p - 1;
        else
          g = (pot(x, pot(2 % (p - 1), r - l + 2, p - 1), p) - 1 + p) % p;
        g = (g * pot((x - 1 + p) % p, p - 2, p)) % p;
      }
      if (k & 1) g = (g * pot(pot(2, r - l, p) % p, p - 2, p)) % p;
      printf("%lld\n", g);
    }
  }
  return 0;
}
