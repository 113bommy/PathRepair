#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<ll, ll>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
  int n;
  cin >> n;
  vi x(n), y(n);
  for (ll i = 0; i < (n); i++) {
    cin >> x[i] >> y[i];
  }
  int min_x = *min_element(x.begin(), x.end());
  int max_x = *max_element(x.begin(), x.end());
  int min_y = *min_element(y.begin(), y.end());
  int max_y = *min_element(y.begin(), y.end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int dx = max(max_x - x[i], x[i] - min_x);
    int dy = max(max_y - y[i], y[i] - min_y);
    ans = max(ans, dx + dy);
  }
  cout << 2 * ans;
  for (int i = 4; i <= n; i++)
    cout << " " << 2 * (max_x - min_x + max_y - min_y);
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t = 1;
  while (t--) {
    solve();
  }
}
