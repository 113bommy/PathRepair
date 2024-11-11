#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
inline long long ab(long long x) { return x < 0 ? -x : x; }
inline long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a % b);
}
long long a[N], dt[N];
long long g[N][21];
int lg[N], n;
void init() {
  for (int i = 2; i < N; ++i) lg[i] = lg[i >> 1] + 1;
}
void st() {
  for (int i = 1; i <= n; ++i) g[i][0] = a[i];
  for (int k = 1; k <= lg[n]; ++k) {
    for (int i = 1; i + (1 << k) - 1 <= n; ++i) {
      g[i][k] = gcd(g[i][k - 1], g[i + (1 << k - 1)][k - 1]);
    }
  }
}
long long q(int l, int r) {
  int k = lg[r - l + 1];
  return gcd(g[l][k], g[r - (1 << k) + 1][k]);
}
bool qry(int x) {
  if (x <= 0) return 1;
  for (int i = 2; i + x - 1 <= n; ++i)
    if (q(i, i + x - 1) != 1) return 1;
  return 0;
}
int main() {
  init();
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int _;
  cin >> _;
  while (_--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = n; i; --i) a[i] = ab(a[i] - a[i - 1]);
    st();
    int ans = 0;
    for (int r = 2, l = 2; r <= n; r++) {
      while (l < r && q(l, r) == 1) l++;
      if (q(l, r) != 1) ans = max(ans, r - l + 1);
    }
    ans++;
    cout << ans << '\n';
  }
  return 0;
}
