#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#pragma GCC optimize("O3")
using namespace std;
using namespace std::chrono;
long long mod_exp(long long x, long long n) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = (res * x) % 1000000007;
    x = (x * x) % 1000000007;
    n >>= 1;
  }
  return res;
}
void inout() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long k;
  cin >> k;
  int x = 9;
  for (long long i = 1;; i++) {
    if (k <= (i * x)) {
      x = (x / 9) + (--k / i);
      while (++k % i) x /= 10;
      cout << x % 10;
      exit(0);
    }
    k -= (i * x);
    x *= 10;
  }
  return 0;
}
