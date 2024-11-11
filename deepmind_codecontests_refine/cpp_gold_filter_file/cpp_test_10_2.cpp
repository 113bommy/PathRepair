#include <bits/stdc++.h>
using namespace std;
long long ax, ay, bx, by, k, m, n, q = 1e9 + 7, v, w;
long long P(long long x, long long y) {
  long long s = 1;
  for (; y; y >>= 1) {
    if (y & 1) s = s * x % q;
    x = x * x % q;
  }
  return s;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k >> v >> w >> ax >> ay >> bx >> by;
  cout << P(k, (n * m - (ax == bx && ay == by ? 0 : v * w)));
}
