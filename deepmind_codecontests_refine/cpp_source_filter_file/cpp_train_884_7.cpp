#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1000000 + 100, mod = 1000000007;
int main() {
  if (fopen("/home/lianyi/123.txt", "r") != NULL) {
    freopen("/home/lianyi/123.txt", "r", stdin);
  } else {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
  }
  long long n, a, b, c;
  while (cin >> n) {
    cin >> a >> b >> c;
    long long res = 0;
    long long can = 0, x = 0;
    if (b - c < a) {
      x = n - b;
      if (x > 0) {
        can = x / (b - c);
        res += can;
        n -= can * (b - c);
        if (n >= b) {
          n -= b - c;
          res++;
        }
      }
    }
    x = n - a;
    if (x > 0) {
      can = x / (a);
      res += can;
      n -= can * a;
      if (n >= a) {
        n -= a;
        res++;
      }
    }
    cout << res << '\n';
  }
  return 0;
}
