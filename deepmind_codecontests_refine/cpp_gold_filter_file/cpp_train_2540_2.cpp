#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
const long long mod = 1e9 + 7;
long long n, m, t, k, a[N], b[N], tong, ans, c[N];
priority_queue<long long, vector<long long>, greater<long long> > pq;
long long pw(long long k, long long n) {
  long long total = 1;
  for (; n; n >>= 1) {
    if (n & 1) total = (total * k) % mod;
    k = (k * k) % mod;
  }
  return total;
}
long long cal(long long u, long long v) {
  if (u > v) return 0;
  return a[v] * b[u] % mod * b[v - u] % mod;
}
void sol() {
  cin >> n;
  bool ok = true;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] != -1) b[a[i]] = 1;
    if (a[i] != -1) c[i] = 1;
    if (a[i] == i) {
      ok = false;
    }
    if (a[i] == -1) ++m;
  }
  for (int i = 1; i <= n; i++) {
    if (b[i] == 0 && c[i] == 0) ++tong;
  }
  a[0] = b[0] = 1;
  if (!ok) {
    cout << 0;
    return;
  }
  for (int i = 1; i <= n; i++) {
    a[i] = (a[i - 1] * i) % mod;
    b[i] = pw(i, mod - 2);
    b[i] = (b[i] * b[i - 1]) % mod;
  }
  ans = a[m];
  for (int i = 1; i <= tong; i++) {
    if (i % 2 == 1) {
      ans = (ans - cal(i, tong) * a[m - i] % mod + mod) % mod;
    } else
      ans = (ans + cal(i, tong) * a[m - i] % mod) % mod;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (fopen("permute"
            ".inp",
            "r")) {
    freopen(
        "permute"
        ".inp",
        "r", stdin);
    freopen(
        "permute"
        ".out",
        "w", stdout);
  }
  int ntest = 1;
  while (ntest-- > 0) sol();
}
