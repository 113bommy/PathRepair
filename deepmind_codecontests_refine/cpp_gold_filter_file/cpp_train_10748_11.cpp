#include <bits/stdc++.h>
using namespace std;
const long long max3 = 1003;
const long long max4 = 10004;
const long long max5 = 100005;
const long long max6 = 1000006;
const long long max7 = 10000007;
const long long lg4 = 13;
const long long lg5 = 17;
const long long lg6 = 20;
const long long INF = 2LL * 1000000000;
const long long INFLL = 9LL * 1000000000 * 1000000000;
const long long M = 1e9 + 7;
long long powmod(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
  }
  return res;
}
int n;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    int odds = 0, evens = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (a & 1)
        odds++;
      else
        evens++;
    }
    bool ok = false;
    for (int i = 1; i <= min(odds, x); i += 2) {
      if (i & 1) {
        if ((x - i) <= evens) ok = true;
      }
    }
    if (ok)
      cout << "Yes" << '\n';
    else
      cout << "No" << '\n';
  }
  return 0;
}
