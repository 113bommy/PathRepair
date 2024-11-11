#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
const int MAXN = 1e6 + 10;
const long long MOD = 1e9 + 7;
const long long MOD2 = 998244353;
const long long INF = 8e18;
const int LOG = 22;
long long pw(long long a, long long b, long long mod) {
  return (!b ? 1
             : (b & 1 ? (a * pw(a * a % mod, b / 2, mod)) % mod
                      : pw(a * a % mod, b / 2, mod)));
}
long long ps[MAXN], v[MAXN], n, d, b;
bool check(long long x) {
  if (x >= (n + 1) / 2) return 1;
  for (long long i = x + 1; i <= ((n + 1) / 2); i++) {
    int l = max(1ll, i - (i * d)), r = min(n, i + (i * d));
    long long sum = ps[r] - ps[l - 1];
    if (sum < (i - x) * b) {
      return 0;
    }
  }
  for (long long i = n - x; i >= ((n + 1) / 2); i--) {
    int l = max(1ll, i - (n - i + 1) * d), r = min(n, i + (n + 1 - i) * d);
    long long sum = ps[r] - ps[l - 1];
    if (sum < (n - x + 1 - i) * b) {
      return 0;
    }
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> d >> b;
  bool is_OK = 1;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    if (v[i] != b) is_OK = 0;
    ps[i] = ps[i - 1] + v[i];
  }
  if (is_OK) return cout << 0, 0;
  int d = 0, up = n + 1;
  while (up - d > 1) {
    int mid = (up + d) / 2;
    if (check(mid)) {
      up = mid;
    } else {
      d = mid;
    }
  }
  cout << up << "\n";
  return 0;
}
