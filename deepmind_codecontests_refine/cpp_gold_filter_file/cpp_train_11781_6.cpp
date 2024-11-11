#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using ll = long long;
int n, m;
vector<pii> a;
unordered_set<ll> s;
bool f(int r) {
  for (int i = int(0); i < int(m); i++) {
    ll x = a[i].first + r, y = a[i].second + r;
    if (x >= n) x -= n;
    if (y >= n) y -= n;
    if (x > y) swap(x, y);
    if (!s.count(x * n + y)) return 0;
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  a.resize(m);
  s.reserve(1 << 18);
  s.max_load_factor(0.25);
  for (int i = int(0); i < int(m); i++) {
    int x, y;
    cin >> x >> y;
    if (x == n) x = 0;
    if (y == n) y = 0;
    if (x > y) swap(x, y);
    a[i] = {x, y};
    s.emplace(ll(x) * n + y);
  }
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0 && (f(i) || (i > 1 && f(n / i)))) return cout << "Yes\n", 0;
  }
  return cout << "No\n", 0;
}
