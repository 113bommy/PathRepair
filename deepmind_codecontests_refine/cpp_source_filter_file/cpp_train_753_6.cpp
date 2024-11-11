#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long ksm(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}
int t;
long long n, k;
long long a[200005], ma, mi;
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ma = mi = a[1];
    for (int i = 1; i <= n; i++) {
      if (a[i] > ma) ma = a[i];
      if (a[i] < mi) mi = a[i];
    }
    for (int i = 1; i <= n; i++) a[i] = ma - a[i];
    ma = ma - mi;
    ma = 0;
    k--;
    if (k % 2 == 0) {
      cout << a[1];
      for (int i = 2; i <= n; i++) cout << " " << a[i];
      cout << "\n";
    } else {
      cout << ma - a[1];
      for (int i = 2; i <= n; i++) cout << " " << ma - a[i];
      cout << "\n";
    }
  }
  return 0;
}
