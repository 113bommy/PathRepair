#include <bits/stdc++.h>
using namespace std;
const long double pi = asin(1) * 2;
const long long M = 1000000007;
long long pow1(long long a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % M;
    }
    a = (a * a) % M;
    b >>= 1;
  }
  return res % M;
}
const long long N = 100001;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  t = 1;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    long long sm = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      sm += a[i];
    }
    if (n > 32) {
      cout << sm - n << "\n";
    } else {
      sort(a, a + n);
      long long ans = 10000000000;
      long long x = 1;
      for (long long i = 0; i < a[n - 1]; i++) {
        if (pow(x + 1, n - 1) >= 100000000000) break;
        x++;
      }
      for (long long i = 1; i <= x; i++) {
        long long temp = 0;
        long long y = 1;
        for (long long j = 0; j < n; j++) {
          temp += abs(a[j] - y);
          y *= i;
        }
        ans = min(ans, temp);
      }
      cout << ans << "\n";
    }
  }
  return 0;
}
