#include <bits/stdc++.h>
using namespace std;
using namespace std;
const long long mod2 = 998244353;
long long spf[100005];
long long fpow(long long x, long long y) {
  x = x % 1000000007;
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x;
    res %= 1000000007;
    y = y >> 1;
    x = x * x;
    x %= 1000000007;
  }
  return res;
}
long long inv(long long a, long long m = 1000000007) {
  long long c = m;
  long long y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long q = a / m;
    long long t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += c;
  return x;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long a[n][2];
  for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
  long long res = 0;
  for (int i = 0; i <= 100000; i++) {
    long long cnt = 0;
    for (int j = 0; j < n; j++) {
      long long x = s[j] - '0';
      if (i < a[j][1]) {
        if (x) cnt++;
      } else {
        long long y = i - a[j][1];
        y /= a[j][0];
        if (y & 1) {
          x ^= 1;
        }
        if (x) cnt++;
      }
    }
    res = max(res, cnt);
  }
  cout << res;
}
