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
  ll asum, bsum, jsum, totsum;
  asum = bsum = jsum = totsum = 0;
  int n;
  cin >> n;
  vi v(n);
  for (ll i = 0; i < (n); i++) {
    int a, b;
    cin >> a >> b;
    bsum += b;
    asum += a;
    v[i] = a - b;
  }
  sort(v.begin(), v.end(), greater<int>());
  for (int i = 0; i < n; i++) {
    jsum += (i + 1) * v[i];
  }
  totsum = jsum - asum + n * bsum;
  cout << totsum << '\n';
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
