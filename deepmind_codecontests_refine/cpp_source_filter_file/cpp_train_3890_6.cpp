#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
const int maxn = 2e5 + 7;
int diry[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dirx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
long long pow(long long x, long long y, long long p) {
  long long res = 1;
  x %= p;
  if (x == 0) {
    return 0;
  }
  while (y > 0) {
    if (y & 1) {
      res = (res * x) % p;
    }
    y >>= 1;
    x = (x * x) % p;
  }
  return res;
}
long long factorial(long long n) {
  int res = 1, i;
  for (i = 2; i <= n; i++) res *= i;
  return res;
}
int main() {
  int t = 1;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long res = pow(3, n);
    res--;
    if (res < 0) res += m;
    cout << res << endl;
  }
}
