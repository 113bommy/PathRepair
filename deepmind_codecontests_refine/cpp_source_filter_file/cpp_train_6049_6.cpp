#include <bits/stdc++.h>
using namespace std;
const double pi = 2 * acos(0.0);
const int inf = 0x3f3f3f3f;
const double infd = 1.0 / 0.0;
long long power(long long x, long long y, long long MOD) {
  long long res = 1;
  x = x % MOD;
  while (y > 0) {
    if (y & 1) res = (res * x) % MOD;
    y = y >> 1;
    x = (x * x) % MOD;
  }
  return res;
}
long long mul(long long a, long long b, long long MOD) {
  if (b == 1) {
    return a;
  }
  if (b % 2 == 0) {
    return 2 * (mul(a, b / 2, MOD) % MOD);
  } else {
    return (a + (2 * (mul(a, b / 2, MOD)) % MOD)) % MOD;
  }
}
bool ispow2(long long n) {
  if (((n & (n - 1)) == 0) && n != 0) {
    return true;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, w, b, ans, x;
  vector<int> a;
  cin >> n >> w >> b;
  for (int i = 0; i < n; i++) {
    cin >> x;
    a.push_back(x);
  }
  for (int i = n / 2; i < n; i++) {
    if (i == (n - i - 1) && i == (n / 2)) {
      if (a[i] == 2) {
        ans += min(w, b);
      }
    } else if (a[i] != a[n - i - 1] && (a[i] != 2 && a[n - i - 1] != 2)) {
      ans = -1;
      break;
    } else if (a[i] == 2 && a[n - i - 1] == 2) {
      ans += 2 * (min(w, b));
    } else if (a[i] == 2) {
      if (a[n - i - 1] == 0) {
        ans += w;
      } else {
        ans += b;
      }
    } else if (a[n - i - 1] == 2) {
      if (a[i] == 0) {
        ans += w;
      } else {
        ans += b;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
