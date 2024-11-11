#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, l, r, ans = 0;
void solve(ll L, ll R, ll val, ll QL, ll QR) {
  if (QR < L || R < QL) {
    return;
  }
  if (L == R) {
    ans += val;
    return;
  }
  ll mid = (L + R) / 2;
  solve(L, mid - 1, val / 2, QL, QR);
  solve(mid, mid, val % 2, QL, QR);
  solve(mid + 1, R, val / 2, QL, QR);
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> l >> r;
  ll x = log2(n) + 1;
  solve(1, (ll)pow(2, x) - 1, n, l, r);
  cout << ans;
  return 0;
}
