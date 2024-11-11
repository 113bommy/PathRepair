#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  ll sum = 0;
  vector<ll> v(n);
  for (int i = 0; i < (n); i++) {
    cin >> v[i];
    sum += v[i];
  }
  ll l = (sum - n * (n - 1) / 2) / n + 1;
  sum = l * n + n * (n - 1) / 2 - sum;
  for (int i = 0; i < n; ++i) cout << l + i - (n - i <= sum) << ' ';
  return 0;
}
