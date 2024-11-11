#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using PP = pair<ll, P>;
const ll n_ = 2e5 + 100, inf = 1e18 + 1, mod = 1e9 + 7, sqrtN = 320;
ll dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
ll n, m, k, tc = 1, a, b, c, sum, x, y, z, w, base, ans;
ll gcd(ll x, ll y) {
  if (!y) return x;
  return gcd(y, x % y);
}
void solve() {
  cin >> n;
  vector<ll> v(n);
  vector<ll> A(n), B(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  A[n - 1] = 1;
  for (int i = n - 2; i >= 0; i--) {
    if (v[i] < v[i + 1])
      A[i] = A[i + 1] + 1;
    else
      A[i] = 1;
  }
  B[0] = 1;
  for (int i = 1; i < n; i++) {
    if (v[i] < v[i - 1])
      B[i] = B[i - 1] + 1;
    else
      B[i] = 1;
  }
  x = 0, a = 0, b = n - 1;
  ans = -1;
  while (1) {
    if (v[a] > v[b]) {
      if (A[a] & 1)
        break;
      else if (B[b] > ans) {
        ans = B[b];
        b--;
      } else {
        x++;
        break;
      }
    } else if (v[b] > v[a]) {
      if (B[b] & 1)
        break;
      else if (v[a] > ans) {
        ans = v[a];
        a++;
      } else {
        x++;
        break;
      }
    } else {
      if ((A[a] & 1) == 0 && (B[b] & 1) == 0) x++;
      break;
    }
    x++;
  }
  if (x & 1)
    cout << "Bob";
  else
    cout << "Alice";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  while (tc--) solve();
}
