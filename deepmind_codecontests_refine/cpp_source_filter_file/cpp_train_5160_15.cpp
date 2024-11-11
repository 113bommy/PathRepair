#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 9e18 + 7;
const ll MAXN = 2e5 + 7;
vector<ll> A(MAXN);
void go() {
  ll n, x;
  cin >> n;
  vector<ll> sum;
  for (ll i = 2; i <= n; i++) {
    cout << "? 1 " << i << endl;
    cin >> x;
    sum.push_back(x);
  }
  cout << "? 2 3" << endl;
  cin >> x;
  ll a = sum[0] + sum[1] - x;
  a /= 2;
  cout << a << " ";
  for (ll i = 0; i < n - 1; i++) {
    cout << sum[i] - a << " ";
  }
  cout << endl;
}
signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(nullptr);
  go();
}
