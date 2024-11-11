#include <bits/stdc++.h>
using namespace std;
int mod = 998244353;
const int inf = 1e9;
long long int linf = 1000000ll * 10000 * 10000;
const int maxn = 1e6 + 50;
pair<int, int> P[maxn];
int m, k, A[maxn], n, res[maxn];
long long int l, ans;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> m >> l >> k;
  for (int i = 0; i < m; i++) {
    cin >> A[i];
  }
  n = m * k;
  ans = l % mod;
  for (int i = 0; i < n; i++) {
    P[i].first = A[i % m];
    P[i].second = i;
  }
  sort(P, P + n);
  long long int q = l / m;
  int r = l % m;
  for (int i = 0; i < n; ++i) {
    int ki = P[i].second;
    if (ki / m + 1 == 1) {
      res[ki / m + 1]++;
      continue;
    }
    res[ki / m + 1] += res[ki / m];
    res[ki / m + 1] %= mod;
    if (ki >= l) continue;
    long long int cnt = q - (ki / m + 1) + 1;
    if (ki % m <= r - 1) cnt++;
    ans += ((long long int)res[ki / m] % mod) * (cnt % mod) % mod;
    ans %= mod;
  }
  cout << ans;
  return 0;
}
