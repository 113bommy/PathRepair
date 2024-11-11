#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2 * 1e5 + 10;
ll res, mx;
ll a[N], price[N];
std::vector<ll> con[N];
bool vis[N];
ll cal_dis(ll x, ll y, ll nx, ll ny) {
  ll k = (nx - x) * (nx - x) + (ny - y) * (ny - y);
  return ceil(sqrt(k));
}
void solve() {
  ll r, x, y, nx, ny;
  cin >> r >> x >> y >> nx >> ny;
  ll k = cal_dis(x, y, nx, ny);
  cout << ceil(k / (double)(2 * r));
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t = 1;
  while (t--) {
    solve();
  }
}
