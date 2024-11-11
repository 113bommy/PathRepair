#include <bits/stdc++.h>
using namespace std;
template <typename T>
using V = vector<T>;
const int INF = 1e9 + 5;
const int MOD = (int)1e9 + 7;
const int maxn = (int)1e3 + 5;
const int maxm = (int)1e9;
long long int TEN(int x) {
  long long int ans = 1;
  while (x--) ans *= 10;
  return ans;
}
void add(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
int modE(int n, int x) {
  int res = 1;
  while (x) {
    if (x & 1) res = (1ll * res * n) % MOD;
    n = (1ll * n * n) % MOD;
    x >>= 1;
  }
  return res;
}
int t, n, q, a[30], b;
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n >> q;
  for (int i = 0; i < (int)(n); ++i) {
    cin >> t;
    if (t > maxm) continue;
    int d = 0;
    while ((1LL << d) < t) d++;
    a[d]++;
  }
  while (q--) {
    cin >> b;
    int d = 3, ans = 0, c = 0;
    while (b > 0 && d >= 0) {
      ans += min(b / (1 << d), a[d]);
      b -= min(b / (1 << d), a[d]) * (1 << d);
      d--;
    }
    if (b)
      cout << -1;
    else
      cout << ans;
    cout << endl;
  }
}
