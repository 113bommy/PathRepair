#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using PP = pair<ll, P>;
const ll n_ = 4e5 + 100, inf = 1e18, mod = 1e9 + 7, sqrtN = 333, p = 27;
ll dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
ll n, m, k, tc = 1, a, b, c, d, sum, x, y, z, base, ans;
ll gcd(ll x, ll y) {
  if (!y) return x;
  return gcd(y, x % y);
}
ll A[220], B[120];
void solve() {
  cin >> n >> k;
  memset(A, 0, sizeof(A));
  x = n - k;
  n *= 2;
  while (k--) {
    cin >> a >> b;
    A[a] = b;
    A[b] = a;
  }
  vector<ll> v;
  for (int i = 1; i <= n; i++) {
    if (A[i]) continue;
    v.push_back(i);
  }
  for (int i = 0; i < v.size() / 2; i++) {
    A[v[i]] = v[i + v.size() / 2];
    A[v[i + v.size() / 2]] = v[i];
  }
  ans = 0;
  for (int i = 1; i <= n; i++) {
    if (A[i] <= i) continue;
    for (int j = i + 1; j <= n; j++) {
      if (i == j || A[j] <= j || j > A[i]) continue;
      if (A[i] < A[j]) {
        ans++;
      }
    }
  }
  cout << ans << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> tc;
  while (tc--) solve();
}
