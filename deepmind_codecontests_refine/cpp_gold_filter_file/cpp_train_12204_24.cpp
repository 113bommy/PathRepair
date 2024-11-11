#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MOD = 1000000007;
int n;
ll ar[200005];
ll ans = 1e18;
set<ll> mem;
void tes(ll x) {
  if (x == 1) return;
  if (mem.count(x)) return;
  mem.insert(x);
  ll tp = 0;
  for (int i = (0); i < (n); i++) {
    if (ar[i] <= x)
      tp += x - ar[i];
    else
      tp += min(ar[i] % x, x - (ar[i] % x));
  }
  ans = min(ans, tp);
}
void rn(ll x) {
  if (!x) return;
  for (ll i = 2; i * i <= x; i++) {
    if (x % i) continue;
    tes(i);
    while (x % i == 0) x /= i;
  }
  tes(x);
}
mt19937 rng(152149433);
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = (0); i < (n); i++) cin >> ar[i];
  tes(2);
  vector<int> order(n);
  for (int i = (0); i < (n); i++) order[i] = i;
  shuffle(order.begin(), order.end(), rng);
  for (int lp = (0); lp < (min(n, 2)); lp++) {
    rn(ar[order[lp]] - 1);
    rn(ar[order[lp]]);
    rn(ar[order[lp]] + 1);
  }
  cout << ans << endl;
}
