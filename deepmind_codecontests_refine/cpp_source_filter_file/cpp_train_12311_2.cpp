#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long n) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a;
    a = ((a) * (a));
    n >>= 1;
  }
  return res;
}
long long binpow(long long a, long long n, long long m) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = ((res % m) * (a % m)) % m;
    a = (a * a) % m;
    n >>= 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin.sync();
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c;
    cin >> a >> b >> c;
    long long res1 = -1, res2 = -1;
    if (a == c && b == 1) {
      cout << "-1"
           << " "
           << "-1"
           << "\n";
      continue;
    }
    if (a < c) {
      res1 = 1;
    }
    if (a > float(c / b)) {
      res2 = b;
    }
    cout << res1 << " " << res2 << "\n";
  }
  return 0;
}
