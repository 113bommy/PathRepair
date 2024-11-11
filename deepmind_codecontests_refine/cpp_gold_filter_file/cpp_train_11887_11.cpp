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
  if (n == 1) {
    cout << "YES" << '\n';
    cout << "1 2" << '\n';
    return;
  }
  if (n % 2 == 0) {
    cout << "NO" << '\n';
    return;
  }
  vi ans(2 * n);
  int idx = 0;
  for (int i = 1; i <= 2 * n; i++) {
    ans[idx] = i;
    if (i & 1) {
      idx = (idx + n) % (2 * n);
    } else {
      idx = (idx + 1) % (2 * n);
    }
  }
  cout << "YES" << '\n';
  for (int x : ans) cout << x << " ";
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
